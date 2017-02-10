#pragma once

//
//
//
//
//
//
//
//

#include "cAstNode.h"
#include "cExprNode.h"
#include "cSymbol.h"

class cParamListNode : public cExprNode
{
	public: 
		cParamListNode(cExprNode * multiple) : cExprNode()
		{
			AddChild(multiple);
		}
	
		void Insert(cExprNode * multiple)
		{
			AddChild(multiple);
		}
		
		virtual string NodeType() { return string("params"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
