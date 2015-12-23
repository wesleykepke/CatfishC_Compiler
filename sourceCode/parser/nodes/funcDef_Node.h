/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: funcDef_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef FUNCDEF_NODE_H
#define FUNCDEF_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class funcDef_Node : public astNode {
    public:
        // constructors
        funcDef_Node(astNode* = NULL, astNode* = NULL, astNode* = NULL, astNode* = NULL);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~funcDef_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        astNode* exprC;
        astNode* exprD;
        int id;
};

#endif // FUNCDEF_NODE_H