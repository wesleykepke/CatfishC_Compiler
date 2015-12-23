/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: relationalExpr_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the postfix expression AST node class of our C compiler.

*/

// header guards
#ifndef RELATIONALEXPR_NODE_H
#define RELATIONALEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class relationalExpr_Node : public astNode {
    public:
        // constructors
        relationalExpr_Node(astNode* = NULL, astNode* = NULL, int = -1);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~relationalExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int type; 
        int id;
};

#endif // RELATIONALEXPR_NODE_H