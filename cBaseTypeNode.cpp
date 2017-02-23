#include "cBaseTypeNode.h"
#include "cSymbolTable.h"

cBaseTypeNode::cBaseTypeNode(string type, int num, bool yes) : cDeclNode()
{
	name = type;
        size = num;
        isFloat = yes;
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
