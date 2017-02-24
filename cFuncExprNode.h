#pragma once

//**************************************
////// cFuncExprNode.h
//////
////// Makes an ast node of function expressions
//     inherits from all expressions
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//
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
		//inserts any param list for any function
		void Insert(cParamListNode * list)
		{
			AddChild(list);
		}

		virtual cDeclNode * GetType()
		{
			return nullptr;
		}
	
		virtual string NodeType() { return string("funcCall"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	protected:
};
