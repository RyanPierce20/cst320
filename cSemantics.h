#pragma once
//**************************************
//////// cSemantics.h
////////
//////// This class will output the semantic errors
//////// 
////////
//////// Author: Ryan Pierce
//////// ryan.pierce@oit.edu
////////
//////// Date: February 26 2017
////////
//////
////
//
class cSemantics : cVisitor
{
	public:
		cSemantics() : m_numErrors(0) {}
		 
		void SemanticError(cAstNode *node, string msg)
		{
			m_numErrors++;
	
			node->SetHasError();
			std::cout << "ERROR: " << msg << " on line " << node->LineNumber() << "\n";
		}

		void VisitAllNodes(cAstNode *node)
		{
			node->Visit(this); //inherited function to visit nodes
		}
		
		int NumErrors()
		{//the number of errors
			return m_numErrors;
		}

		void Visit(cVarExprNode * node)
		{	//visit the variable expression node
			if(node->GetName()->GetDecl() == nullptr)
			{	//if there is no decl then error
				SemanticError(node, "Symbol " + node->GetName()->GetName() + " not defined");
				return;
			}

			cExprNode * expression = nullptr;//declare the expression to check the decl

			for(int i = 0; i < node->GetChildren(); i++)
			{	//go through the children of the array then check if its int or char
				expression = node->GetArray(i);
				if(!expression->GetType()->IsInt() || !expression->GetType()->IsChar())
				{	//if it isnt an int or char then give error for array 
					SemanticError(node, "Index of " + node->GetName()->GetName() + " is not an int");
					return;
				}
			}
		
		}

		void Visit(cAssignNode * node)
		{	
			VisitAllChildren(node);
			//go through the nodes 

			if(!node->GetExpr()->HasError() && !node->GetVarExpr()->HasError()) 
			{	//if has error then dont enter
				if(node->GetExpr()->GetType() != node->GetVarExpr()->GetType())
				{	//if the types arent the same then produce error
					if((node->GetExpr()->GetType()->IsInt() != !node->GetVarExpr()->GetType()->IsInt()) 
					|| node->GetExpr()->GetType()->IsChar() != !node->GetVarExpr()->GetType()->IsChar()
					|| node->GetExpr()->GetType()->IsFloat() != !node->GetVarExpr()->GetType()->IsFloat()
					|| node->GetExpr()->GetType()->IsStruct() != !node->GetVarExpr()->GetType()->IsStruct()
					|| node->GetExpr()->GetType()->IsArray() != !node->GetVarExpr()->GetType()->IsArray()) 
					{
						SemanticError(node, "Cannot assign " + node->GetExpr()->GetType()->GetName()->GetName() + " to " + node->GetVarExpr()->GetType()->GetName()->GetName());
						return;
					}
				}
			}
		}

		void Visit(cFuncExprNode * node)
		{	//if the decl isnt a function then say its not a function if its being a
			//accessed as one
			if(!node->GetName()->GetDecl()->IsFunc())
			{
				SemanticError(node, node->GetName()->GetName() + " is not a function");
				return;
			}
			//if the function isnt declared but being called then error
			if(node->GetName()->GetDecl() == nullptr)
			{
				SemanticError(node, "Function " + node->GetName()->GetName() + " is not declared");
				return;
			}
			//if there are no statements from function then its not fully defined
			if(node->GetFunc()->GetStmt() == nullptr )
			{
				SemanticError(node, "Function " + node->GetName()->GetName() + " is not fully defined");
				return;
			}
		
			int declParams = 0;//the declared parameters for the function
			int passedParams = 0;//the passed parameters for the function

			//get the params that are declared
			cParamsNode * actualParamDecl = node->GetFunc()->GetParam();
			//get the params that are being passed
			cParamListNode * actualPassedParams = node->GetParam();

			//if there are none being declared then set the int to what it actually is
			if(actualParamDecl != nullptr)
			{
				declParams = actualParamDecl->GetTotal();
			}
			//if there are none being declared then set the int to what it actuall is
			if(actualPassedParams != nullptr)
			{
				passedParams = actualPassedParams->GetNumParam();
			}
			//if they arent the same amount of params then give an error
			if(declParams != passedParams)
			{
				SemanticError(node, node->GetName()->GetName() + " called with wrong number of arguments");
				return;
			}
			//if there are no declared params then visitallchildren
			if(declParams != 0) 
			{ 
				VisitAllChildren(actualPassedParams); 
			}
			//go through all the declared params
			for(int i = 0; i < declParams; i++)
			{	//if they have an error then go in
				if(!actualPassedParams->GetParams(i)->HasError())
				{	//check each parameter and if they aint the same then error
					if(actualPassedParams->GetParams(i)->GetType() != actualParamDecl->GetParamNode(i)->GetType())
					{
						SemanticError(node, node->GetName()->GetName() + " called with incompatible arguement");
						return;
					}
				}
			}
					
				
			

		}
	protected:
	int m_numErrors;

};
