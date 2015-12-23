/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: initializer_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the initializer AST node class of our C compiler.

*/

// header guards
#ifndef INITIALIZER_NODE_H
#define INITIALIZER_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class initializer_Node : public astNode {
    public:
        // constructors
        initializer_Node(astNode* = NULL);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~initializer_Node();

    private:
        astNode* exprA;
        int id;
};

#endif // INITIALIZER_NODE_H