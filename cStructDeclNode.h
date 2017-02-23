#pragma once

//**************************************
////// cStructDeclNode.h
//////
////// Makes an ast node for any struct but
//     only for declarations
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
//
#include "cDeclsNode.h"
#include "cSymbol.h"
#include "cDeclNode.h"
#include "cSymbol.h"

class cStructDeclNode : public cDeclNode
{
	public:
		cStructDeclNode(cDeclsNode * declNode, cSymbol * name) : cDeclNode()
		{
			AddChild(declNode);
			//adds the node and if its find then insert new as a new symbol
			if(g_SymbolTable.Find(name->GetName()))
			{
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
			//set type so we know which type to DO_RETURN
			//name->SetType();	
			AddChild(name);
		}
	
		virtual string NodeType() { return string("struct_decl"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
		
		virtual cSymbol * GetName()
		{
			return static_cast<cSymbol *>(GetChild(1));
		}
		virtual cDeclNode * GetType()
		{
			return (static_cast<cSymbol *>(GetChild(0)))->GetDecl();
		}
		
		virtual bool IsType() { return true; }
		virtual bool IsStruct() { return true; }
	protected:
};
