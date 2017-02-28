#pragma once

//**************************************
////// cVarExprNode.h
//////
////// Defines an AST node for a variable expresion.
//////
////// Inherits from cExprNode so that variable expressions can be used anywhere
////// expressions are used.
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February, 9, 2017
//////
////
#include "cAstNode.h"
#include "cDeclNode.h"
#include "cExprNode.h"

class cVarExprNode : public cExprNode
{
	public:
		cVarExprNode(cSymbol * val) : cExprNode()
		{	
			type = val;	
			AddChild(val);
		}

		virtual string NodeType() {return string("varref"); }

		virtual void Visit(cVisitor * visit) {visit->Visit(this); }
		
		void Insert(cSymbol * var)
		{
			AddChild(var);
		}
	
		cExprNode * GetArray(int index)
		{	//get the expressoon of the array
			index++;
			return static_cast<cExprNode *>(GetChild(index));
		}

		virtual cSymbol * GetName()
		{
			return static_cast<cSymbol *>(GetChild(0)); 
		}


		virtual bool IsVar() { return true; }		
	
		virtual cDeclNode * GetType()
		{
 			cDeclNode * decl = GetName()->GetDecl();
			cDeclNode * node = nullptr;
			//get the declared type of the nodes
			for(int i =0; i < GetChildren(); i++)
			{
				if(decl == nullptr)
				{
					return nullptr;
				}
				decl = decl->GetType()->GetName()->GetDecl();
			}
				
			node = decl->GetType();
			return node;
		}

		int GetChildren()
		{//get all children from nodes
			return this->NumChildren() - 1;
		}	

	protected:
	cSymbol * type;
};
