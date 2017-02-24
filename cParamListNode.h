#pragma once

//**************************************
////// cParamListNodeNode.h
//////
////// Makes an ast node for a list of parameters for 
//	any expression
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//
#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"

class cParamListNode : public cAstNode
{
	public: 
		cParamListNode(cExprNode * multiple) : cAstNode()
		{
			AddChild(multiple);
		}
		//has an insert so you can insert any cExprNode
		void Insert(cExprNode * multiple)
		{
			AddChild(multiple);
		}
		
		virtual string NodeType() { return string("params"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
