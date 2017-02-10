#pragma once

//**************************************
////// cBinadryExprNode.h
//////
////// Makes sure that you can make a binary expression node
////// with the compiler
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

class cBinaryExprNode : public cExprNode
{
	public:
		cBinaryExprNode(cExprNode * Left, cOpNode * operation, cExprNode * Right) : cExprNode()
		{
			AddChild(Left);
			AddChild(operation);
			AddChild(Right);
		}

		virtual string NodeType() { return string("expr"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};	
