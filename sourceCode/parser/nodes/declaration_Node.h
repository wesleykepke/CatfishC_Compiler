/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declaration_Node.h
Created: November 4, 2015
Last Modified: November 4, 2015
Class: CS 460 (Compiler Construction)
*/

// header guards
#ifndef DECLARATION_NODE_H
#define DECLARATION_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class declaration_Node : public astNode {
    public:
        // constructors
        declaration_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
        int getID() const;
	    threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~declaration_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // DECLARATOR_NODE_H