/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: unaryOp_Node.h
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the unary op AST node class of our C compiler.

*/

// header guards
#ifndef UNARYOP_NODE_H
#define UNARYOP_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class unaryOp_Node : public astNode {
    public:
        // constructors
        unaryOp_Node(int = -1);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~unaryOp_Node();

    private:
        int type;
        int id;
};

#endif // UNARYOP_NODE_H