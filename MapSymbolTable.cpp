#include "MapSymbolTable.h"

cSymbol * MapSymbolTable::Insert(string symbol)
{
	//cout << symbol << "MapSymbolTable" << endl;
	cSymbol * insert = new cSymbol(symbol);
	std::pair<std::string,cSymbol*> mapSymbol (symbol, insert);
	return insert;
}

cSymbol * MapSymbolTable::lookup(string symbol)
{
	map<string, cSymbol*>::iterator it = mapSymbol.find(symbol);
	if(it == mapSymbol.end())
	{
		return nullptr;
	}
	else
	{
		return it->second;
	}
}

MapSymbolTable::MapSymbolTable(const map<string, cSymbol*> & copy)
{
	//cout << "Copy Constructor" << endl;
	mapSymbol = copy;
}
MapSymbolTable::MapSymbolTable()
{
}
