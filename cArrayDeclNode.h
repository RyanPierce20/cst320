#pragma once

//**************************************
//// cArrayDeclNode.h
////
//// Makes sure that you can make arrays 
//// with the compiler
////
//// Author: Ryan Pierce
//// ryan.pierce@oit.edu
////
//// Date: February 9 2017
////
//
#include "cAstNode.h"
#include "cDeclNode.h"
#include "cSymbol.h"

class cArrayDeclNode : public cDeclNode
{
	public:
		cArrayDeclNode(cSymbol * type, int count, cSymbol * name) : cDeclNode()
		{
			//name->SetType();
			value = count;
			AddChild(type);
			//check if its already in scope and if is then make new and insert that else insert passed in
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
			
			AddChild(name);
		}
		//output the correct string that output wants
		virtual string AttributesToString()
		{
			string result(" count='");
			result += std::to_string(value);
			result += "'";
			return result;
		}

		virtual string NodeType() { return string("array_decl"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	
		virtual cSymbol * GetName()	
		{
			return static_cast<cSymbol *>(GetChild(1));			
		}
		virtual cDeclNode * GetType()
		{
			return this;	
		}

		virtual bool IsType() { return true; }
		virtual bool IsArray() { return true; }
		virtual string GetTypeName() { return type->GetName();}

	protected:
	int value;
	cSymbol * type;
};
