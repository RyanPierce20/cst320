#pragma once

//
//
//
//
//
//
//
//

#include "cAstNode.h"
#include "cSymbol.h"
#include "cDeclsNode.h"
#include "cStmtsNode.h"
#include "cParamsNode.h"

class cFuncDeclNode : public cDeclNode
{
	public:
		cFuncDeclNode(cSymbol * type, cSymbol * name)
                {
			if(g_SymbolTable.Find(name->GetName()))
			{
				name = new cSymbol(name->GetName());
			}
			
			g_SymbolTable.Insert(name);			

                        AddChild(type);
                        AddChild(name);
                 
                }

		void Insert(cAstNode * anything)
		{
			AddChild(anything);
		}


		virtual string NodeType() { return string("func"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	protected:
};
	
