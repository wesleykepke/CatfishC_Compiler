/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: declSpec_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the declaration specifier AST node class of our C compiler.  
*/

#include "declSpec_Node.h"

/*
Function: declSpec_Node(int t) (constructor) 

Description: 
*/
declSpec_Node::declSpec_Node(astNode* A, int t) : astNode(){
	exprA = A;
	type = t;
	id = idNum;
	name = "declSpec_Node";
}

/*
Function: getID() 

Description: returns ID
*/
int declSpec_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC declSpec_Node::gen3AC(){
	//std::cout << "Generate 3AC for declaration specifier node" << std::endl;
	//out3AC << source << std::endl; 
	outputSource(source);
	threeAC temp;
	temp.str = ""; 
	return temp; 
}


/*
Function: print(int indent)

Description: 
*/
void declSpec_Node::print(int indent){

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
		std::cout<< "NULL ";
	}

}

/*
Function: ~declSpec_Node() (destructor) 

Description: 
*/
declSpec_Node::~declSpec_Node(){

}

