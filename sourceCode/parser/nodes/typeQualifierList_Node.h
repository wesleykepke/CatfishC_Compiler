/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: typeQualifierList_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the type qualifier list AST node class of our C compiler.

*/

// header guards
#ifndef TYPEQUALIFIERLIST_NODE_H
#define TYPEQUALIFIERLIST_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class typeQualifierList_Node : public astNode {
    public:
        // constructors
        typeQualifierList_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~typeQualifierList_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // TYPEQUALIFIERLIST_NODE_H