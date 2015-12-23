/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: directDecl_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "directDecl_Node.h"

/*
Function: directDecl_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
directDecl_Node::directDecl_Node(astNode* A, astNode* B) : astNode(){
	exprA = A;
	exprB = B;
	name = A->getName();
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int directDecl_Node::getID() const{
	return id;
}



/*
Function: gen3AC()

Description: 
*/
threeAC directDecl_Node::gen3AC(){
	//std::cout << "Generate 3AC for direct declaration node" << std::endl;
	threeAC temp = exprA->gen3AC(); 
	return temp;
}

/*
Function: print(int indent)

Description: 
*/
void directDecl_Node::print(int indent){

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
Function: ~directDecl_Node() (destructor) 

Description: 
*/
directDecl_Node::~directDecl_Node(){

}

