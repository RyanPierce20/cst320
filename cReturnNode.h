#pragma once

//**************************************
////// cRerturnNode.h
//////
////// Makes an Ast node for any return stmt
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//
#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"

class cReturnNode : public cStmtNode
{
	public://inherits from stmt so any stmt can be a return stmt
		cReturnNode(cExprNode * expr) : cStmtNode()
		{
			AddChild(expr);
		}

		 virtual string NodeType() { return string("return"); }
  		 virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
