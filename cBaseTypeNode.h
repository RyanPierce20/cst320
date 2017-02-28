#pragma once
//**************************************
//////// cBaseTypeNode.h
////////
//////// File to make another node for the base of the program
//////// 
////////
//////// Author: Ryan Pierce
//////// ryan.pierce@oit.edu
////////
//////// Date: February 26 2017
////////
//////
////
//
#include "cAstNode.h"
#include "cDeclNode.h"


class cBaseTypeNode : public cDeclNode
{
	public:
		cBaseTypeNode(string type, int num, bool yes);// : cDeclNode(); 
	
		virtual cSymbol * GetName();
	
		virtual cDeclNode * GetType();
		virtual string NodeType();// { return string("base"); }
		virtual void Visit(cVisitor * visitor);// { visitor->Visit(this); }
		virtual bool IsType();
		virtual string GetTypeName();		
		
		virtual bool IsInt();
		virtual bool IsChar();
		virtual bool IsFloat();
			
	protected:
		bool isFloat;
		string name;
		int size;
};
