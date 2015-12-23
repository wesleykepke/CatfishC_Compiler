/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declSpec_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the unary op AST node class of our C compiler.

*/

// header guards
#ifndef DECLSPEC_NODE_H
#define DECLSPEC_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class declSpec_Node : public astNode {
    public:
        // constructors
        declSpec_Node(astNode* = NULL, int = -1);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~declSpec_Node();

    private:
        astNode* exprA;
        int type;
        int id;
};

#endif // DECLSPEC_NODE_H