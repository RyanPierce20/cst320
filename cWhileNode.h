#pragma once

//**************************************
////// cWhileNode.h
//////
////// Makes a while stmt node for an stmt
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//

#include "cExprNode.h"
#include "cStmtNode.h"
#include "cAstNode.h"

class cWhileNode : public cStmtNode
{
	public:
		cWhileNode(cExprNode * expr, cStmtNode * stmt) : cStmtNode()
		{
			AddChild(expr);
			AddChild(stmt);
		}

		virtual string NodeType() { return string("while"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:

};
