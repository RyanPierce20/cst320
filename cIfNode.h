#pragma once

//**************************************
////// cIfNode.h
//////
////// Makes an ast node for any If statements
//     Inherits from statements node so any stmt
//     can have an if condition
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
#include "cStmtsNode.h"

class cIfNode : public cStmtNode
{
	public:// two constructors so other types of if stmts can obtain from this class
		cIfNode(cExprNode * expr, cStmtsNode * ifstmt, cStmtsNode * elsestmt) : cStmtNode()
		{
			AddChild(expr);
			AddChild(ifstmt);
			AddChild(elsestmt);
		}
		
		cIfNode(cExprNode * expr, cStmtsNode * ifstmt) : cStmtNode()
                {
                        AddChild(expr);
                        AddChild(ifstmt);
                }

		
		virtual string NodeType() { return string("if"); }
	        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	
	protected:
};
