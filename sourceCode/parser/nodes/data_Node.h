/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: data_Node.h
Created: October 27
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the iteration AST node class of our C compiler.

*/

// header guards
#ifndef DATA_NODE_H
#define DATA_NODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include "astNode.h"
#include "../cParser.tab.h"

// class definition 
class data_Node : public astNode {
    public:
        // constructors
        data_Node(const vals&, int);

        // class functions 
        int getID() const;
        threeAC gen3AC();
        void print(int = 0);


        // destructor 
        ~data_Node();

    private:
        vals data;
        int dataType;
        int id;
};

#endif // DATA_NODE_H