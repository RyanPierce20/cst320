#pragma once
//**************************************
////// SymbolTable.h
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
