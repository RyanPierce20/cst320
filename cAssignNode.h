#pragma once

//
//
//
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
