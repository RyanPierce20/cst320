#pragma once


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

	//	virtual string AttributesToString()
	//	{
			//return " value=\"" + std::to_string() + "\"";
			//return "(EXPR: " + Left->toString() + ' ' + operation->toString() +,
			//	 ' ' Right->toString() + ')';
			//return "";
	//	}
		virtual string NodeType() { return string("expr"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};	
