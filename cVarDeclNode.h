#pragma once
//
// Ryan Pierce
// ryan.pierce@oit.edu
//
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

	protected:
};
