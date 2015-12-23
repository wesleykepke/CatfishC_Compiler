/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declaration_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "declaration_Node.h"

/*
Function: declarator_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
declaration_Node::declaration_Node(astNode* A, astNode* B) : astNode(){

	exprA = A;
	exprB = B;
	name = "declaration_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int declaration_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC declaration_Node::gen3AC(){
	//std::cout << "Generate 3AC for declarator node" << std::endl;
	threeAC temp; 
	temp.str = "";
	if (exprA != NULL && exprB == NULL) {
		temp = exprA->gen3AC();
		return temp; 
	}
	 
	else if (exprA != NULL && exprB != NULL){
		temp = exprA->gen3AC();
		exprB->gen3AC(); 
	}

	return temp;
}

/*
Function: print(int indent)

Description: 
*/
void declaration_Node::print(int indent){

	
}

/*
Function: ~declaration_Node() (destructor) 

Description: 
*/
declaration_Node::~declaration_Node(){

}

