#pragma once
//**************************************
////// MapSymbolTable.h
//////
////// map for the symbol table
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
