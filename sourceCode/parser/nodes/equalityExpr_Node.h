/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: equalityExpr_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef EQUALITYEXPR_NODE_H
#define EQUALITYEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class equalityExpr_Node : public astNode {
    public:
        // constructors
        equalityExpr_Node(astNode* = NULL, astNode* = NULL, int = -1);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~equalityExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int type; 
        int id;
};

#endif // EQUALITYEXPR_NODE_H