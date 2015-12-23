/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: multExpr_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the mutl expression AST node class of our C compiler.

*/

// header guards
#ifndef MULTEXPR_NODE_H
#define MULTEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"
#include "../cParser.tab.h"

// class definition 
class multExpr_Node : public astNode {
    public:
        // constructors
        multExpr_Node(astNode* = NULL, astNode* = NULL, int = -1);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~multExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int type; 
        int id;
};

#endif // MULTEXPR_NODE_H