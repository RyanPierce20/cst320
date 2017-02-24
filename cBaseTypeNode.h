#pragma once

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
					
	protected:
		bool isFloat;
		string name;
		int size;
};
