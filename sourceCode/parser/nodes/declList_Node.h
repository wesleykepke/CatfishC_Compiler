/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declList_Node.h
Created: October 27
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the iteration AST node class of our C compiler.

*/

// header guards
#ifndef DECLLIST_NODE_H
#define DECLLIST_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"
#include "../cParser.tab.h"

// class definition 
class declList_Node : public astNode {
    public:
        // constructors
        declList_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~declList_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // DECLLIST_NODE_H