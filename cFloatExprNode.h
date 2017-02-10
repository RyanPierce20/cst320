#pragma once
//**************************************
//// cFloatExprNode.h
////
//// Defines an AST node for an integer constant (literals).
////
//// Inherits from cExprNode so that integer constants can be used anywhere 
//// expressions are used.
////
//// Author: Ryan Pierce 
//// ryan.pierce@oit.edu
////
//// Date: February 9 2017
////
//
#include "cAstNode.h"
#include "cExprNode.h"

class cFloatExprNode : public cExprNode
{
	public:
		//output passed in float value
		cFloatExprNode(double value) : cExprNode()
		{
			m_value = value;
		}

		virtual string AttributesToString()
		{
			return " value=\"" + std::to_string(m_value) + "\"";
		}
		virtual string NodeType() { return string("float"); }
	        virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
		//made it a double because instructor prefered double over float
		double m_value;
}; 

