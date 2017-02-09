#pragma once

//**************************************
////// cIntExprNode.h
//////
////// Defines an AST node for an integer constant (literals).
//////
////// Inherits from cExprNode so that integer constants can be used anywhere
////// expressions are used.
//////
////// Author: Phil Howard
////// phil.howard@oit.edu
//////
////// Date: Jan. 18, 2015
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

	protected:
};
