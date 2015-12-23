/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: selectionStat_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef SELECTIONSTAT_NODE_H
#define SELECTIONSTAT_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class selectionStat_Node : public astNode {
    public:
        // constructors
        selectionStat_Node(astNode* = NULL, astNode* = NULL, astNode* = NULL);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~selectionStat_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        astNode* exprC;
        int id;
};

#endif // SELECTIONSTAT_NODE_H