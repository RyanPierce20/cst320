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
			AddChild(val);
		}

		virtual string NodeType() {return string("varref"); }

		virtual void Visit(cVisitor * visit) {visit->Visit(this); }
		
		void Insert(cSymbol * var)
		{
			AddChild(var);
		}

		virtual cDeclNode * GetType()
		{
			return nullptr;
		}	

	protected:
};
