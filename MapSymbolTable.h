#pragma once

#include <iostream>
#include "cSymbol.h"
using namespace std;
#include <map>
#include <string>

class MapSymbolTable
{
	public:
		MapSymbolTable();
		cSymbol * Insert(string symbol);
		cSymbol * lookup(string symbol);
		MapSymbolTable(const map<string, cSymbol*> & copy);
	protected:
		map<string, cSymbol*> mapSymbol;
};
