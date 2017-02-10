#pragma once

#include "cAstNode.h"
#include "cExprNode.h"
#include "cParamsNode.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamListNode.h"

class cFuncExprNode : public cExprNode
{
	public:
		cFuncExprNode(cSymbol * type, cParamListNode * name) : cExprNode()
                {
                        AddChild(type);
                        AddChild(name);
                }

		void Insert(cParamListNode * list)
		{
			AddChild(list);
		}
	
		virtual string NodeType() { return string("funcCall"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	protected:
};
