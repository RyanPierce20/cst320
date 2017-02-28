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
			m_returnType = type;
                        AddChild(type);
                        AddChild(name);
                }
		//inserts any param list for any function
		void Insert(cParamListNode * list)
		{
			AddChild(list);
		}
		//get type of decl
		virtual cDeclNode * GetType()
		{
			return GetName()->GetDecl()->GetType();
		}
		//get the name of the child of the func
		virtual cSymbol * GetName() 
		{
			return static_cast<cSymbol *>(GetChild(0));
		}
		//return the ammount of children in this
		int GetNum()
		{
			return this->NumChildren();
		}
		//get the list of params to check the func params
		cParamListNode * GetParam() 
		{
			return static_cast<cParamListNode *>(GetChild(1));
		}	
		//get the name of the function
		virtual cFuncDeclNode * GetFunc()
		{
			return static_cast<cFuncDeclNode *>(GetName()->GetDecl());
		}

		virtual bool IsFunc() { return true;}
		
		virtual string NodeType() { return string("funcCall"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	protected:
	cSymbol * m_returnType;
};
