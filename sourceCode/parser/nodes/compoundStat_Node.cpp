/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: compoundStat_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "compoundStat_Node.h"

/*
Function: compoundStat_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
compoundStat_Node::compoundStat_Node(astNode* A, astNode* B) : astNode(){
	exprA = A;
	exprB = B;
	name = "compoundStat_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int compoundStat_Node::getID() const{
	return id;
}

/*
Function: gen3AC()

Description: 
*/
threeAC compoundStat_Node::gen3AC(){
	//std::cout << "Generate 3AC for compound stat node" << std::endl;
	threeAC temp; 
	temp.str = "";

	// nothing in {}
	if (exprA == NULL && exprB == NULL) {
		return temp; 
	}

	// declarations but no use (stupid)
	else if (exprA != NULL && exprB == NULL) {
		temp = exprA->gen3AC();
		return temp; 
	}
	
	// statements but no declarations 
	else if (exprA == NULL && exprB != NULL) {
		temp = exprB->gen3AC();
		return temp; 
	}

	// statements and declarations 
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
void compoundStat_Node::print(int indent){

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
Function: ~compoundStat_Node() (destructor) 

Description: 
*/
compoundStat_Node::~compoundStat_Node(){

}

