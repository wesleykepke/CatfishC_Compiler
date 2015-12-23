/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declarator_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef DECLARATOR_NODE_H
#define DECLARATOR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class declarator_Node : public astNode {
    public:
        // constructors
        declarator_Node(astNode* = NULL);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~declarator_Node();

    private:
        astNode* exprA;
        int id;
};

#endif // DECLARATOR_NODE_H