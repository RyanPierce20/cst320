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
			m_name = name;
			m_returnType = type;
			m_params = nullptr;
			m_other = nullptr;
			m_isDefined = false;

			//cSymbol * sym = g_SymbolTable.FindLocal(name->GetName());

			if(g_SymbolTable.Find(name->GetName()))
			{
				if(g_SymbolTable.FindLocal(name->GetName()))
				{
					cFuncDeclNode *copy = static_cast<cFuncDeclNode *>(g_SymbolTable.FindLocal(name->GetName())->GetDecl());
                                                m_other = copy;

					if(!g_SymbolTable.FindLocal(name->GetName())->GetDecl()->IsFunc())
					{
						SemanticError(name->GetName() + " previously declared as other than a function");
					}
					else
					{
						if(copy->GetType() != this->GetType())
						{						
							SemanticError(name->GetName() + " previously declared with different return type");
						}
						
					}	
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

                        AddChild(type);
                        AddChild(name);
                 
                }

		cParamsNode * GetParams()
		{
			return m_params;
		}
		//insert any kind of node for thr ast so we dont have to make multiple functions to insert 
		//different types of nodes
		void Insert(cAstNode * anything)
		{
			AddChild(anything);
		}

		void InsertParams(cParamsNode * params)
		{
			if((m_other != nullptr) && (m_other->GetParams() != nullptr) && (params != nullptr))
			{
				if(m_other->GetParams()->NumChildren() != params->NumChildren())
				{
					SemanticError(m_name->GetName() + " previously declared with a different number of parameters");
				}
				else
				{
					bool flag = false;

					for(int i =0; (i < params->NumChildren()) && (flag == false); i++)
					{
						cDeclNode * param = static_cast<cDeclNode *>(params->GetChild(i));
						cDeclNode * otherParam = static_cast<cDeclNode *>(m_other->GetParams()->GetChild(i));

						if (param->GetType() != otherParam->GetType())
						{
							flag = true;
						}
					}
				
					if(flag == true)
					{
						SemanticError(m_name->GetName() + " previously declared with different parameters");
					}
				}
			
			}
			AddChild(params);
			m_params = params;			
		}

		virtual string NodeType() { return string("func"); }
                virtual void Visit(cVisitor *visitor) { visitor->Visit(this); }
	
		virtual cSymbol * GetName()
		{
			return static_cast<cSymbol *>(GetChild(1));	
		}

		virtual cDeclNode * GetType()
		{
			return m_returnType->GetDecl();
		}
		virtual bool IsFunc() { return true; }
	protected:
	cSymbol *m_name;
	cSymbol *m_returnType;
	cParamsNode *m_params;
	cFuncDeclNode *m_other;
	bool m_isDefined;
};
	
