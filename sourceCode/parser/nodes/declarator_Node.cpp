/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declarator_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "declarator_Node.h"

/*
Function: declarator_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
declarator_Node::declarator_Node(astNode* A) : astNode(){ 
	exprA = A;
	name = A->getName();
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int declarator_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC declarator_Node::gen3AC(){
	//std::cout << "Generate 3AC for declarator node" << std::endl;
	threeAC temp; 
	temp.str = ""; 
	if (exprA != NULL) {
		return exprA->gen3AC();
	}
	return temp; 
}

/*
Function: print(int indent)

Description: 
*/
void declarator_Node::print(int indent){

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
Function: ~declarator_Node() (destructor) 

Description: 
*/
declarator_Node::~declarator_Node(){

}

