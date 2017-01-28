#include "MapSymbolTable.h"
//**************************************
////// MapSymbolTable.cpp
//////
////// list for the symbol table.
//////
////// Author: Ryan Pierce
////// ryan.pierce@oit.edu
//////
////// Date: Jan, 28 2017
//////
////
//
cSymbol * MapSymbolTable::Insert(string symbol)
{
	//create new cSymbol to insert
	cSymbol * insert = new cSymbol(symbol);
	//make a pair out of the string and cSymbol location
	std::pair<string,cSymbol*> mapSymbols (symbol, insert);
	//insert the pair
	mapSymbol.insert(mapSymbols);
	return insert;
}

cSymbol * MapSymbolTable::lookup(string symbol)
{
	//find the symbol in table
	map<string, cSymbol*>::iterator it = mapSymbol.find(symbol);
	if(it == mapSymbol.end())//if not found return nullptr
	{
		return nullptr;
	}
	else//else return the cSymbol location
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
