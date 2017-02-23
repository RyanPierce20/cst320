#pragma once

//**************************************
////// cVarDeclNode.h
//////
////// Makes an ast node for a variable declartion
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
#include "cSymbol.h"

class cVarDeclNode : public cDeclNode
{
	public:
		cVarDeclNode(cSymbol * type, cSymbol * name) : cDeclNode()
		{
			AddChild(type);

			if(g_SymbolTable.Find(name->GetName()))
			{
				name = new cSymbol(name->GetName());
			}
						
			g_SymbolTable.Insert(name);
	
			AddChild(name);
		}
		
		virtual string NodeType() { return string("var_decl"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
		virtual cSymbol * GetName()
		{
			//return the decl associated with the type
			return static_cast<cSymbol *>(GetChild(1));
		}
		virtual cDeclNode * GetType()
		{
			//return the decl associated with the type
			return (static_cast<cSymbol *>(GetChild(0)))->GetDecl();
		}
		virtual bool IsType() { return true; }	
	protected:
};
