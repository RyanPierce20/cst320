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
		
		virtual cVarExprNode * GetVarExpr()
		{	//get the varExprNode from the assignment
			return static_cast<cVarExprNode *>(GetChild(0));
		}
	
		virtual cExprNode * GetExpr()
		{	//get the cExprNode so you can see its decl and name
			return static_cast<cExprNode *>(GetChild(1));
		}	
		virtual string NodeType() { return string("assign"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
