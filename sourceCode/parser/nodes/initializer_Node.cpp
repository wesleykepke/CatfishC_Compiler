/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: initializer_Node.cpp
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the initializer AST node class of our C compiler.  
*/

#include "initializer_Node.h"


/*
Function: initializer_Node(astNode* A) (constructor) 

Description: 
*/
initializer_Node::initializer_Node(astNode* A) : astNode(){

	exprA = A;
	name = "initializer_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int initializer_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC initializer_Node::gen3AC(){
	//std::cout << "Generate 3AC for postfix expression node" << std::endl;
	if (exprA != NULL) {
		return exprA->gen3AC(); 
	}
}

/*
Function: print(int indent)

Description: 
*/
void initializer_Node::print(int indent){

	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
	std::cout << "Prefix Expression Node:" << std::endl;
	
	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
	std::cout << "A: ";
	if( exprA != NULL ){
		exprA->print(indent + 1);
		//std::cout << "AST Node";
	}
	else{
		std::cout << "NULL ";
	}

	std::cout << std::endl;
	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
}

/*
Function: ~initializer_Node() (destructor) 

Description: 
*/
initializer_Node::~initializer_Node(){
	std::cout << "Postfix Expression Node destructor" << std::endl;

}

