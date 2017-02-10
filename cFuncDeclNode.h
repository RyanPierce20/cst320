#pragma once

//**************************************
////// cFuncDeclNode.h
//////
////// Make an ast node for any functions and 
//     make it inherit from DeclNode for any declarations
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: February 9 2017
//////
////
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
		//insert any kind of node for thr ast so we dont have to make multiple functions to insert 
		//different types of nodes
		void Insert(cAstNode * anything)
		{
			AddChild(anything);
		}


		virtual string NodeType() { return string("func"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	protected:
};
	
