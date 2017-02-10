#pragma once

//**************************************
////// cAssignNode.h
//////
////// Makes sure that you can make assignments
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
#include "cStmtNode.h"
#include "cExprNode.h"
#include "cVarExprNode.h"

class cAssignNode : public cStmtNode
{
	public: 
		cAssignNode(cVarExprNode * varExpr, cExprNode * expr) : cStmtNode()
		{
			AddChild(varExpr);
			AddChild(expr);
		}

		virtual string NodeType() { return string("assign"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
