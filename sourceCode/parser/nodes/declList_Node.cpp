/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declList_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "declList_Node.h"

/*
Function: declaration_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
declList_Node::declList_Node(astNode* A, astNode* B) : astNode(){
	exprA = A;
	exprB = B;
	name = "declList_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int declList_Node::getID() const{
	return id;
}

/*
Function: gen3AC()

Description: 
*/
threeAC declList_Node::gen3AC(){
	//std::cout << "Generate 3AC for declaration list node" << std::endl;
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
void declList_Node::print(int indent){

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
Function: ~declarator_Node() (destructor) 

Description: 
*/
declList_Node::~declList_Node(){
	exprA = NULL;
	exprB = NULL; 
}