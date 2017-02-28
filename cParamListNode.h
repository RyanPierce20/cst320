#pragma once

//**************************************
////// cParamListNodeNode.h
//////
////// Makes an ast node for a list of parameters for 
//	any expression
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
#include "cSymbol.h"

class cParamListNode : public cAstNode
{
	public: 
		cParamListNode(cExprNode * multiple) : cAstNode()
		{
			AddChild(multiple);
		}
		//has an insert so you can insert any cExprNode
		void Insert(cExprNode * multiple)
		{
			AddChild(multiple);
		}
		//get the list of params and use index for the for loop to go through each param		
		cExprNode * GetParams(int index)
                {
                        return static_cast<cExprNode *>(GetChild(index));
                }
		//get the number of params in the list
		int GetNumParam()
		{
			return this->NumChildren();
		}

				
		virtual string NodeType() { return string("params"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
