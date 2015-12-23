/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: paramDecl_Node.h
Created: November 4, 2015
Last Modified: November 4, 2015
Class: CS 460 (Compiler Construction)
*/

// header guards
#ifndef PARAMDECL_NODE_H
#define PARAMDECL_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class paramDecl_Node : public astNode {
    public:
        // constructors
        paramDecl_Node(astNode* = NULL, astNode* = NULL);

        // class functions 
        int getID() const;
	    threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~paramDecl_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int id;
};

#endif // PARAMDECL_NODE_H