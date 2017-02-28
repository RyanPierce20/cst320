#pragma once

//**************************************
////// cFuncDeclNode.h
//////
////// Make an ast node for any functions and 
//     make it inherit from DeclNode for any declarations
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//

#include "cAstNode.h"
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamsNode.h"

class cFuncDeclNode : public cDeclNode
{
	public:
		cFuncDeclNode(cSymbol * type, cSymbol * name): m_name(name), m_returnType(type), m_params(nullptr), m_other(nullptr), m_isDefined(false)
                {
			//if the symbol is found in the table then go in and if not insert	
			if(g_SymbolTable.Find(name->GetName()))
			{
				//check if symbol is in local table
				if(g_SymbolTable.FindLocal(name->GetName()))
				{
					//get the symbol's decl and set it to our funcdecl so we can check its params
					cFuncDeclNode *copy = static_cast<cFuncDeclNode *>(g_SymbolTable.FindLocal(name->GetName())->GetDecl());
                                                m_other = copy;
					//if its a function already declared then semantic error
					if(!g_SymbolTable.FindLocal(name->GetName())->GetDecl()->IsFunc())
					{
						SemanticError(name->GetName() + " previously declared as other than a function");
					}
					else
					{	//else if the type is same then saay already declared but has different type
						if(copy->GetType() != this->GetType())
						{						
							SemanticError(name->GetName() + " previously declared with different return type");
						}
						else if (copy->isDefined() == false)
						{//if isnt already defined then set the decl
							name->SetDecl(this);
						}
						
					}	
				}
		
			}
			else
			{//if its found locally and globally then make a new symbol
				if(g_SymbolTable.Find(name->GetName()))
				{
					name = new cSymbol(name->GetName());
				}
				g_SymbolTable.Insert(name);
                                name->SetDecl(this);
			}
			

                        AddChild(type);
                        AddChild(name);
                 
                }

		cParamsNode * GetParams()
		{
			return m_params;
		}
		//insert any kind of node for thr ast so we dont have to make multiple functions to insert 
		//different types of nodes
		void Insert(cAstNode * anything)
		{
			AddChild(anything);
		}

		void InsertParams(cParamsNode * params)
		{	//if the copied func is something and has parameters then dive in
			if((m_other != nullptr) && (m_other->GetParams() != nullptr) && (params != nullptr))
			{	//if the number of parameters dont have same ammount then error
				if(m_other->GetParams()->NumChildren() != params->NumChildren())
				{
					SemanticError(m_name->GetName() + " previously declared with a different number of parameters");
				}
				else
				{	//else say that its okay
					bool flag = false;
					//then loop through the parameters to check every declaration so its correct parameters
					for(int i =0; (i < params->NumChildren()) && (flag == false); i++)
					{
						cDeclNode * param = static_cast<cDeclNode *>(params->GetChild(i));
						cDeclNode * otherParam = static_cast<cDeclNode *>(m_other->GetParams()->GetChild(i));
						//if one of parameters isnt same as one then semantic error
						if (param->GetType() != otherParam->GetType())
						{
							flag = true;
						}
					}
				
					if(flag == true)
					{
						SemanticError(m_name->GetName() + " previously declared with different parameters");
					}
				}
			
			}
			AddChild(params);
			m_params = params;			
		}
	
		void InsertDecls(cDeclsNode * decls)
		{
			AddChild(decls);
		}

		void InsertStmts(cStmtsNode * stmts)
		{	
			if(m_name->GetDecl()->IsFunc())
			{
			//check the node if its already declared 
				cFuncDeclNode * func = static_cast<cFuncDeclNode *>(m_name->GetDecl());
			
				if(stmts != nullptr && func->isDefined() == true)
				{
					SemanticError(m_name->GetName() + " already has a definition");
				}//if its good then consider it already declared
				else if(stmts != nullptr)
				{
					m_isDefined = true;
				}
			}
			AddChild(stmts);

		}
		
		bool isDefined()
		{
			return m_isDefined;
		}

		virtual string NodeType() { return string("func"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	
		virtual cSymbol * GetName()
		{
			return static_cast<cSymbol *>(GetChild(1));	
		}

		virtual cDeclNode * GetType()
		{
			return m_returnType->GetDecl();
		}
	
		cStmtsNode * GetStmt()
		{
			return static_cast<cStmtsNode *>(GetChild(4));
		}
		
		cParamsNode * GetParam()
		{
			return static_cast<cParamsNode *>(GetChild(2));
		}

                cDeclsNode * GetDecl() 
		{ 
			return static_cast<cDeclsNode *>(GetChild(3)); 
		}

		virtual bool IsFunc() { return true; }
		virtual string GetTypeName() { return m_name->GetName();}

	protected:
	//added these members becasue it was easier to debug 
	cSymbol *m_name;
	cSymbol *m_returnType;
	cParamsNode *m_params;
	cFuncDeclNode *m_other;
	bool m_isDefined;
};
	
