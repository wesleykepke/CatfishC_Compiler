/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: leaf_Node.h
Created: October 27
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the iteration AST node class of our C compiler.

*/

// header guards
#ifndef LEAF_NODE_H
#define LEAF_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"
#include "../cParser.tab.h"
//#include "../../classes/symbolTableEntry.h"

// class definition 
class leaf_Node : public astNode {
    public:
        // constructors
        leaf_Node(const vals&, int, std::string);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);

        // destructor 
        ~leaf_Node();

    private:
        vals data;
        int dataType;
        int id;
        int myScope;
        int myOffset; 
        bool isArray; 
        symbolTableEntry ste;
};

#endif // LEAF_NODE_H