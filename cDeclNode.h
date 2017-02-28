#pragma once
//**************************************
// cDeclNode
//
// Defines base class for all declarations.
// Future labs will add features to this class.
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cAstNode.h"

class cDeclNode : public cAstNode
{
    public:
        cDeclNode() : cAstNode() {} 

	virtual int GetSize()	{ return 0;}
	virtual string GetTypeName() = 0;	//the name of the decl
	virtual cSymbol * GetName() = 0;
	virtual cDeclNode *GetType() = 0;
	virtual bool IsArray()	{ return false;}//almost every decl will need one of these
	virtual bool IsStruct()	{ return false;}
	virtual bool IsType()	{ return false;}
	virtual bool IsFunc()	{ return false;}
	virtual bool IsVar()	{ return false;}
	virtual bool IsFloat()	{ return false;}
	virtual bool IsInt()	{ return false;}
	virtual bool IsChar()	{ return false;}
};
