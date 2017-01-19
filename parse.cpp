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
using std::cout;
using std::endl;
//*******************************************
// Find a PROG non-terminal
bool FindPROG()
{
	if(!FindSTMTS() && yylex() != END)
	{ //if doesnt find program and isnt at end then return false
		return false;
	}
	else{ //if at end of file then return true that it found program
		AdvanceToken();
		return true;
	}
}
bool FindSTMTS()
{
	while(PeekToken() != END && FindSTMT())//loop until its at the end 
	{
		
	}
	return true;//at end return true to FindPROG
}
bool FindSTMT()
{
	if(FindEXPR())//if its an EXPR then dive in
	{
		if(PeekToken()  == ';') 
		{
			AdvanceToken();//advance passed the semi colon
			cout << "Found a statement" << endl;
			return true;
		}
		else 
		{
			Error("';'");//show error that it found another semi-colon
			while(PeekToken() != 0 && PeekToken() != ';' && PeekToken() != END)
			{
				AdvanceToken();//advance until its not trash
			}
			if(PeekToken() == ';')
			{
				AdvanceToken();//advance if its another semi-colon
			}
			else if(PeekToken() == 0)
			{
				return false;//return false if end of file
			}
			return true;
		}
	}
	else
	{
			while(PeekToken() != 0 && PeekToken() != ';' && PeekToken() != END)
			{
                                AdvanceToken();
                        }
                        if(PeekToken() == ';')
                        {
                                AdvanceToken();
                        }
                        else if(PeekToken() == 0)
                        {
                                return false;
                        }
                        return true;
	}
	return true;//return true if its null
}
bool FindEXPR()
{
	if(PeekToken() == '(')//if its a left bracket because its expected, then dive in
	{
		AdvanceToken();//next token
		if (!FindEXPR()) return false;//if EXPR isnt found then return false
		
		if(PeekToken() == ')')//if next token is a closed paren then advcance token
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
	else if(FindTERM())//if its a term then return true
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
		if(PeekToken() == '(')//if parent then dive in
		{
			AdvanceToken();
		}
		else
		{	
			Error("'('");
			return false;
		}
		
		if(!FindEXPR()) return false;//if EXPR isnt found then its bad
		
		if(PeekToken() == ')')//we expect right paren and then advance
		{
			AdvanceToken();
		}
		else
		{
			Error("')'");
			return false;
		}
		if(!FindEXPR_P()) return false;
	}
	return true;
}
bool FindPLUSOP()
{
	if (PeekToken() == '+' || PeekToken() == '-')//expect the plus operation or minus op
	{
		AdvanceToken();//advance and return it was found
		return true;
	}
	else
	{
		return false;
	}	
}
bool FindTERM()
{
	if(PeekToken() == '[')//the left square bracket is expected
	{
		AdvanceToken();//advance

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
	else if(PeekToken() == NUM)
	{//if its a number, then advance and return true that it was found
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
			Error("'['");
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
	return true;//return true for null/lambda

}
bool FindTIMESOP()
{
	if(PeekToken() == '*' || PeekToken() == '/')
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

