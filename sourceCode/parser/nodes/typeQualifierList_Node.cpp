/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: typeQualifierList_Node.cpp
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the type qualifier list AST node class of our C compiler.  
*/

#include "typeQualifierList_Node.h"


/*
Function: typeQualifierList_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
typeQualifierList_Node::typeQualifierList_Node(astNode* A, astNode* B) : astNode(){

	exprA = A;
	exprB = B;
	name = "typeQualifierList_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int typeQualifierList_Node::getID() const{
    return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC typeQualifierList_Node::gen3AC(){
	//std::cout << "Generate 3AC for postfix expression node" << std::endl;
	threeAC temp; 
	temp.str = "";

	return temp;
}


/*
Function: print(int indent)

Description: 
*/
void typeQualifierList_Node::print(int indent){

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
Function: ~typeQualifierList_Node() (destructor) 

Description: 
*/
typeQualifierList_Node::~typeQualifierList_Node(){

}

