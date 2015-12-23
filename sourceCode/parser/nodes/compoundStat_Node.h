/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: compoundStat_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef COMPOUNDSTAT_NODE_H
#define COMPOUNDSTAT_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class compoundStat_Node : public astNode {
    public:
        // constructors
        compoundStat_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~compoundStat_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // COMPOUNDSTAT_NODE_H