/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: unaryExpr_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the unary expression AST node class of our C compiler.

*/

// header guards
#ifndef UNARYEXPR_NODE_H
#define UNARYEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class unaryExpr_Node : public astNode {
    public:
        // constructors
        unaryExpr_Node(astNode* = NULL, astNode* = NULL, bool = false, bool = false);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~unaryExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        bool incOp;
        bool decOp; 
        int id;
};

#endif // UNARYEXPR_NODE_H