#include "SymbolTable.h"

void SymbolTable::IncreaseScope()
{
	//create empty symbol table and place on stack of symbol
	//cout << "IncreaseScope" << endl;
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
	cSymbol * var = mapList.front().lookup(symbol);
	if(var == nullptr)
	{
		return mapList.front().Insert(symbol);
	}
	else
	{
		return var;
	}
	//cSymbol * returnValue
	//return returnValue;
}

