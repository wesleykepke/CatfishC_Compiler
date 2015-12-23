/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: paramDecl_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "paramDecl_Node.h"

/*
Function: paramDecl_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
paramDecl_Node::paramDecl_Node(astNode* A, astNode* B) : astNode(){

	exprA = A;
	exprB = B;
	name = "paramDecl_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int paramDecl_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC paramDecl_Node::gen3AC(){
	//std::cout << "Generate 3AC for declarator node" << std::endl;
	threeAC temp;
	temp.str = "";
	return temp;
}

/*
Function: print(int indent)

Description: 
*/
void paramDecl_Node::print(int indent){

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
	std::cout << "B: ";
	if( exprB != NULL ){
		exprB->print(indent+1) ;
		//std::cout << "AST Node";
	}
	else{
		std::cout << "NULL ";
	}
}

/*
Function: ~paramDecl_Node() (destructor) 

Description: 
*/
paramDecl_Node::~paramDecl_Node(){

}

