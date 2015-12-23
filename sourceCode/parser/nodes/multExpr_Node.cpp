/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: multExpr_Node.cpp
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the mult expression AST node class of our C compiler.  
*/

#include "multExpr_Node.h"

/*
Function: multExpr_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
multExpr_Node::multExpr_Node(astNode* A, astNode* B, int t) : astNode(){

	exprA = A;
	exprB = B;
	type = t; 
	name = "multExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int multExpr_Node::getID() const{
    return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC multExpr_Node::gen3AC(){
	//std::cout << "Generate 3AC for postfix expression node" << std::endl;
	if (exprA != NULL && exprB == NULL) {
		return exprA->gen3AC(); 
	}

	threeAC tempA = exprA->gen3AC();
	threeAC tempB = exprB->gen3AC(); 
	std::string reg = "";  
	switch(type) {
		case MULT:
			reg = intTC();
			//out3AC << ("MULT " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("MULT", reg, tempA.str, tempB.str); 
		break; 

		case DIV:
			reg = intTC();
			//out3AC << ("DIV " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("DIV", reg, tempA.str, tempB.str); 
		break;

		default:
			reg = ""; 
		break;
	}

	tempA.str = reg;
	return tempA; 
}


/*
Function: print(int indent)

Description: 
*/
void multExpr_Node::print(int indent){

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
Function: ~multExpr_Node() (destructor) 

Description: 
*/
multExpr_Node::~multExpr_Node(){

}

