/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: iterStat_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the additive expression AST node class of our C compiler.

*/

// header guards
#ifndef ITERSTAT_NODE_H
#define ITERSTAT_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class iterStat_Node : public astNode {
    public:
        // constructors
        iterStat_Node(astNode* = NULL, astNode* = NULL, astNode* = NULL, astNode* = NULL, bool = false);

        // class functions 
	    int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~iterStat_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        astNode* exprC;
        astNode* exprD;
        bool isPostCheck;
        int id;
};

#endif // ITERSTAT_NODE_H