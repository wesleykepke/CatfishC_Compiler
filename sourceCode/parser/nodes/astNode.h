/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: astNode.h
Created: October 27
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the base AST node class of our C compiler.

*/

// header guards
#ifndef ASTNODE_H
#define ASTNODE_H

// includes
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include "../../classes/symbolTableEntry.h"

// externs
extern int intTicket; 
extern std::string intTC();
extern std::string labelTC(); 
extern std::ofstream out3AC;
extern std::vector<std::string> sourceCode;
//extern std::string sourceHistory; 
extern std::unordered_set<std::string> sourceHistory;
extern int yylineno;  
extern void output3AC(std::string type, std::string op3, std::string op1, std::string op2);
extern void outputSource(std::string source);
extern void outputLabel(std::string label);

// threeAC_Data
typedef struct {
    std::string str;
    symbolTableEntry ste;
} threeAC;

// class definition 
class astNode {
    public:
        // constructors
        astNode();

        // class functions 
        std::string getSourceCode() const; 
        std::string getName() const;
        virtual int getID() const;
        virtual threeAC gen3AC();
        virtual void print(int = 0);

        // destructor 
        virtual ~astNode();

    protected:
        // data members 
        std::string source;
        std::string name;
        static int idNum;
};

#endif // ASTNODE_H