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
				if(g_SymbolTable.FindLocal(name->GetName()))
				{
					SemanticError("Symbol " + name->GetName() + " already defined in current scope");
				}
				name = new cSymbol(name->GetName());
				g_SymbolTable.Insert(name);
				name->SetDecl(this);
			}
			else
			{
				g_SymbolTable.Insert(name);
                                name->SetDecl(this);
			}
						
			//g_SymbolTable.Insert(name);
				
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
		
		virtual bool IsVar() { return true; }	
		virtual string GetTypeName() { return type->GetName();}
	protected:
	cSymbol * type;
};
