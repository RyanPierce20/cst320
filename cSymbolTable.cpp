//#include "cBaseTypeNode.h"
#include "cSymbolTable.h"

cSymbolTable::cSymbolTable()
{
            IncreaseScope();
            //insert types of declarations in table so the compiler knows its built in language
            cSymbol * char_sym = new cSymbol("char");
            //char_sym->SetType();
            char_sym->SetDecl(new cBaseTypeNode("char", 1, false));
            Insert(char_sym);
            cSymbol * int_sym = new cSymbol("int");
            //int_sym->SetType();
            int_sym->SetDecl(new cBaseTypeNode("int", 4, false));
            Insert(int_sym);
            
	    cSymbol * float_sym = new cSymbol("float");
            //float_sym->SetType();
            float_sym->SetDecl(new cBaseTypeNode("float", 8, true));
            Insert(float_sym);
}
            //

