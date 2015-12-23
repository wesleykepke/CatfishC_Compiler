/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: additiveExpr_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef ADDITIVEEXPR_NODE_H
#define ADDITIVEEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class additiveExpr_Node : public astNode {
    public:
        // constructors
        additiveExpr_Node(astNode* = NULL, astNode* = NULL, int = -1);

        // class functions 
	
        threeAC gen3AC();
        void print(int = 0);

        int getID() const;

        // destructor 
        ~additiveExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int type; 
        int id;
};

#endif // ADDITIVEEXPR_NODE_H