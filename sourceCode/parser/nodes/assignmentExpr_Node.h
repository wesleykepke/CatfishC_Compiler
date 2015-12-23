/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: assignmentExpr_Node.h
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the unary op AST node class of our C compiler.

*/

// header guards
#ifndef ASSIGNMENTEXPR_NODE_H
#define ASSIGNMENTEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class assignmentExpr_Node : public astNode {
    public:
        // constructors
        assignmentExpr_Node(astNode* = NULL, astNode* = NULL, int = -1);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~assignmentExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        int type;
        int id;
};

#endif // ASSIGNMENTEXPR_NODE_H