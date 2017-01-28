#include "SymbolTable.h"
#include "MapSymbolTable.h"


//**************************************
//// SymbolTable.cpp
////
//// list for the symbol table.
////
//// Author: Ryan Pierce
//// ryan.pierce@oit.edu
////
//// Date: Jan, 28 2017
////
//

void SymbolTable::IncreaseScope()
{
	//create empty symbol table and place on stack of symbol
	MapSymbolTable map;
	mapList.push_front(map);
}

void SymbolTable::DecreaseScope()
{
	//pop the top table off the stack and the next one becomes default
	//dont free memory
	mapList.pop_front();
}	

cSymbol * SymbolTable::Insert(string symbol)
{
	//look for the inserted symbol	
	cSymbol * var = mapList.front().lookup(symbol);
	if(var == nullptr)//if not found then insert
	{
		return mapList.front().Insert(symbol);
	}
	else//else return the character
	{
		return var;
	}
}

