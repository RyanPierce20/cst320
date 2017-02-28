#include "cBaseTypeNode.h"
#include "cSymbolTable.h"
//**************************************
//////// cBaseTypeNode.cpp
////////
//////// The cpp for the cBaseTypeNode.h
//////// 
////////
//////// Author: Ryan Pierce
//////// ryan.pierce@oit.edu
////////
//////// Date: February 26 2017
////////
//////
////
//
cBaseTypeNode::cBaseTypeNode(string type, int num, bool yes) : cDeclNode()
{
	name = type;
        size = num;
        isFloat = yes;
}
string cBaseTypeNode::GetTypeName()
{	//get the string of the function so you can check the functions
	return name;
}
cSymbol * cBaseTypeNode::GetName()
{	
	return g_SymbolTable.Find(name);
}

cDeclNode * cBaseTypeNode::GetType()
{
        return g_SymbolTable.Find(name)->GetDecl();
}
string cBaseTypeNode::NodeType() { return string("base_type"); }
void cBaseTypeNode::Visit(cVisitor * visitor) { visitor->Visit(this); }
bool cBaseTypeNode::IsType() { return true; }
bool cBaseTypeNode::IsInt() { return false; }//make sure declared but setting false accusations of true
bool cBaseTypeNode::IsChar()	{ return false; }
bool cBaseTypeNode::IsFloat()	{ return false; }
