#pragma once

//
//
//
//
//
//
//

#include "cAstNode.h"
#include "cStmtNode.h"
#include "cExprNode.h"
#include "cStmtsNode.h"

class cIfNode : public cStmtNode
{
	public:
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
