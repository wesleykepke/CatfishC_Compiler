/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: pointer_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef POINTER_NODE_H
#define POINTER_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class pointer_Node : public astNode {
    public:
        // constructors
        pointer_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~pointer_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // POINTER_NODE_H