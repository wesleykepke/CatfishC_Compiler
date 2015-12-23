/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: scope.h
Created: October 1, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the scope class of our C compiler.

The scope class contains two integers that refer to the current scope and 
and whatever scope is immediately outside of the current scope. This is used
to ensure that all scopes have the approprite outer scope.

In addition, the scope class contains a balanced binary search tree that is 
used to store all of the variables in a given scope. 
*/

// header guards
#ifndef SCOPE_H
#define SCOPE_H

// includes
#include <iostream>
#include "symbolTableEntry.h"
#include <map>

// symbol table and typedefs to reduce keystrokes 
typedef std::map<std::string, symbolTableEntry> Bst; 

// class definition 
class scope {
    public:
        // constructors
        scope();
        scope(int scopeLevel, int outerS, const Bst& bstMap);

        // class functions 
        Bst* getBst();
        int getScopeLevel() const;
        int getOuterScope() const;
	
        // destructor 
        ~scope();

    private:
        // data members 
        int scopeLevel;
        int outerScope;
        Bst bst; 

};

#endif // SCOPE_H