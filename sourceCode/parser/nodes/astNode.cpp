/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: astNode.cpp
Created: October 22, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "astNode.h"
int astNode::idNum = 0;
/*
Function: astNode() (constructor) 

Description: 
*/
astNode::astNode(){
	idNum++;
	source = sourceCode[yylineno - 1];
	//std::cout << "source code: " << source << std::endl; 
}

/*
Function: getSourceCode()  

Description: return source code
*/
std::string astNode::getSourceCode() const{
	return source;
}

/*
Function: getName()  

Description: return name
*/
std::string astNode::getName() const{
	return name;
}

/*
Function: getID()  

Description: return ID
*/

int astNode::getID() const{

}

/*
Function: gen3AC()  

Description: generate node's 3 address code
*/
threeAC astNode::gen3AC(){

}
/*
Function: getID()  

Description: print node info
*/
void astNode::print(int indent){

}

/*
Function: ~astNode() (destructor) 

Description: 
*/
astNode::~astNode(){
	std::cout << "AST Node destructor" << std::endl;

}


