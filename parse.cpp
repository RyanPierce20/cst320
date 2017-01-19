//**************************************
// parse.cpp
//
// Starting point for top-down recursive-descent parser
// Used in CST 320 Lab2
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Nov. 23, 2015
//

#include <iostream>
#include "lex.h"
#include "parse.h"
#include "utils.h"
#include "tokens.h"
using std::endl;
using std::cout;
//*******************************************
// Find a PROG non-terminal
bool FindPROG()
{
	if(FindSTMTS() && yylex() != END){
		return true;
	}
	else{
		return false;
	}
}
bool FindSTMTS()
{
	if(FindSTMT() && FindSTMTS())
	{
		return true;
	}
	return true;
}
bool FindSTMT()
{
	if(FindEXPR())
	{
		if(PeekToken()  == ';') {
		AdvanceToken();
		cout << "Found a statement" << endl;
		return true;
		}
		else {
			Error("';'");
			while(PeekToken() != ';'){
				AdvanceToken();
			}
			return true;
		}
	}
	else{
		return false;
	}
}
bool FindEXPR()
{
	if(PeekToken() == '(')
	{
		AdvanceToken();
		if (!FindEXPR()) return false;
		
		if(PeekToken() == ')')
		{
			AdvanceToken();
		}
		else {
			Error("')'");
			return false;
		}

		if(!FindEXPR_P()) return false;

		return true; 
	}
	else if(FindTERM())
	{
		 return true;
	}
	else 
	{
		return false;
	}
}

bool FindEXPR_P()
{
	if(FindPLUSOP())
	{
		if(PeekToken() == '(')
		{
			AdvanceToken();
		}
		else
		{	
			Error("'(' ");
			return false;
		}
		
		if(!FindEXPR()) return false;
		
		if(PeekToken() == ')')
		{
			AdvanceToken();
		}
		else
		{
			Error("')' ");
			return false;
		}
		if(!FindEXPR_P()) return false;
	}
	return true;
}
bool FindPLUSOP()
{
	if (PeekToken() == PLUSOP)
	{
		AdvanceToken();
		return true;
	}
	else
	{
		return false;
	}	
}
bool FindTERM()
{
	if(PeekToken() == '[')
	{
		AdvanceToken();

		if (!FindEXPR()) return false;
			
		if (PeekToken() == ']')
		{
			AdvanceToken();
		}
		else {
			Error("']'");
			return false;
		}

		if (!FindTERM_P()) return false;
		
		return true;
	}
	else if(PeekToken() == NUM){
		AdvanceToken();
		return true;
	}
	else {
		return false;
	}
	
}
bool FindTERM_P()
{
	if(FindTIMESOP()) 
	{
		if(PeekToken() == '[')
		{
			AdvanceToken();
		}
		else
		{
			Error("'[' ");
			return false;
		}
		if(!FindEXPR()) return false;
		
		if(PeekToken() == ']')
		{
			AdvanceToken();
		}
		else
		{
			Error(" ']' ");
			return false;
		}
		if(!FindTERM_P()) return false;
	}
	return true;

}
bool FindTIMESOP()
{
	if(PeekToken() == TIMESOP)
	{
		AdvanceToken();
		return true;
	}
	else 
	{
		return false;
	}
}

/*******************************************
bool FindExample()
{
    if (!FindPART1()) return false;
    
    int token = PeekToken();
    if (token != '+') return false;
    AdvanceToken();         // past '+'

    if (!FindPART2()) return false;

    return true;
}
*/

