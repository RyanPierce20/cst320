#pragma once

//
//
//
//
//
//
//
//
//
//
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
			
			if(g_SymbolTable.Find(name->GetName()))
			{
				name = new cSymbol(name->GetName());
			}
			
			g_SymbolTable.Insert(name);
			name->SetType();	
			AddChild(name);
		}
	
		virtual string NodeType() { return string("struct_decl"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }

	protected:
};
