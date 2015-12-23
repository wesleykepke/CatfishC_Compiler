/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: scope.cpp
Created: October 1, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the scope class of our C compiler.

BST: binary search tree
*/

// includes
#include "scope.h"

/*
Function: scope() (constructor) 

Description: Allows for instantiation of a new scope object. 
*/
scope::scope() {
	scopeLevel = 0;
	outerScope = 0;
	bst.clear();  
}

/*
Function: scope() (constructor) 

Description: Allows for instantiation of a new scope object
with corresponding parameters. 

Parameters:
int scopeLvl: Pertains to the current scope level.
int outerS: Pertains to the outer scope level.
Bst bstMap: 
*/
scope::scope(int scopeLvl, int outerS, const Bst& bstMap) {
	scopeLevel = scopeLvl; 
	outerScope = outerS;
	bst = bstMap;
}

/*
Function: getBst() 

Description: Allows caller to obtain the BST at the current scope level. 
*/
Bst* scope::getBst() {
	return &bst;
}

/*
Function: getOuterScope() 

Description: Returns the outer scope (integer) of the current scope.  
*/
int scope::getOuterScope() const{
	return outerScope;
}

/*
Function: getScopeLevel() 

Description: Returns the current scope (integer).  
*/
int scope::getScopeLevel() const{
	return scopeLevel;
}

/*
Function: ~scope() 

Description: Destructor for a scope entry.   
*/
scope::~scope(){
	scopeLevel = 0;
	outerScope = 0;
	bst.clear();   
}