#pragma once
//**************************************
// cExprNode.h
//
// Defines base class for all expressions
//
// This is a pure virtual class because there is no definition for
// cAstNode::ToString()
//
// Author: Phil Howard 
// phil.howard@oit.edu
//
// Date: Jan. 18, 2015
//

#include "cStmtNode.h"

class cExprNode : public cStmtNode
{
    public:
        cExprNode() : cStmtNode() {}
	virtual cDeclNode *GetType() = 0;
	virtual cSymbol * GetName() = 0;
	virtual bool IsArray()  { return false;}
        virtual bool IsStruct() { return false;}
        virtual bool IsType()   { return false;}
        virtual bool IsFunc()   { return false;}
        virtual bool IsVar()    { return false;}
        virtual bool IsFloat()  { return false;}
        virtual bool IsInt()    { return false;}
        virtual bool IsChar()   { return false;}
	
	//bool checkAssignment(cExprNode * other)
	//{
	//	bool works = true;
		
	//	if(!GetType()->IsInt() != !other->GetType()->IsInt())
	//	{
	//		works = false;
	//	}
	//	if((!GetType()->IsInt() != !other->GetType()->IsInt()) &&
          //      (GetType()->GetSize() < other->GetType()->GetSize()))
            //    {
	//		works = false;
	//	}

         //	if(!GetType()->IsFloat() && other->GetType()->IsFloat())
           //    	{
	//		works = false;
          //  	}
            //return works;
	//}
};
