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
		//	AddChild(multiple);
		}
		//an insert for params for only declarations
		void Insert(cDeclNode * multiple)
		{
			AddChild(multiple);
		}
		//get the amount of children in the parameter list		
		int GetTotal()
		{
			return this->NumChildren();
		} 
		//get the decl of the param so you can compare them
		cVarDeclNode * GetParamNode(int index) 
		{
			return static_cast<cVarDeclNode *>(GetChild(index));
		}
	
		virtual string NodeType() { return string("args"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
	protected:
};
