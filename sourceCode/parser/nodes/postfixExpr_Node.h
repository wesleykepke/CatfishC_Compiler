/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: postfixExpr_Node.h
Created: October 27
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the postfix expression AST node class of our C compiler.

*/

// header guards
#ifndef POSTFIXEXPR_NODE_H
#define POSTFIXEXPR_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"

// class definition 
class postfixExpr_Node : public astNode {
    public:
        // constructors
        postfixExpr_Node(astNode* = NULL, astNode* = NULL, bool = false, bool = false);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~postfixExpr_Node();

    private:
        astNode* exprA;
        astNode* exprB;
        bool incOp;
        bool decOp;
        int id;
};

#endif // POSTFIXEXPR_NODE_H