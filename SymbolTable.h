#pragma once

#include <iostream>
#include "cSymbol.h"
#include "MapSymbolTable.h"
using namespace std;
#include <map>
#include <list>
#include <string>

class SymbolTable
{
	public:
		void IncreaseScope();
		void DecreaseScope();
		cSymbol * Insert(string symbol);
		cSymbol * lookup(string symbol);
	protected:
		list<MapSymbolTable> mapList;
};
