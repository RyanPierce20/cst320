#pragma once

//**************************************
////// cParamsNode.h
//////
////// Makes an AST node for a paramerter of declarations only
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//
#include "cAstNode.h"
#include "cDeclNode.h"

class cParamsNode : public cDeclsNode
{
	public:
		cParamsNode(cDeclNode * multiple) : cDeclsNode(multiple)
		{
			AddChild(multiple);
		}
		//an insert for params for only declarations
		void Insert(cDeclNode * multiple)
		{
			AddChild(multiple);
		}
	
		virtual string NodeType() { return string("args"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
	protected:
};
