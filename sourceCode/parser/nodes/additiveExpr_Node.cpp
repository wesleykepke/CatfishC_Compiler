/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: additiveExpr_Node.cpp
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "additiveExpr_Node.h"

// Intialize static ID number for this node type

/*
Function: additiveExpr_Node(astNode* A, astNode* B) (constructor) 

Description: Constructor
*/
additiveExpr_Node::additiveExpr_Node(astNode* A, astNode* B, int t) : astNode(){

	exprA = A;
	exprB = B;
	type = t;
	name = "additiveExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int additiveExpr_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: generate 3AC
*/
threeAC additiveExpr_Node::gen3AC(){
	//std::cout << "Generate 3AC for postfix expression node" << std::endl;
	if (exprA != NULL && exprB == NULL) {
		return exprA->gen3AC(); 
	}

	threeAC tempA = exprA->gen3AC();
	threeAC tempB = exprB->gen3AC(); 
	std::string reg = "";  
	switch(type) {
		case PLUS:
			reg = intTC();
			//out3AC << ("PLUS " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("ADD", reg, tempA.str, tempB.str);
		break; 

		case MINUS:
			reg = intTC();
			//out3AC << ("MINUS " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("SUB", reg, tempA.str, tempB.str);
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
void additiveExpr_Node::print(int indent){

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
Function: ~additiveExpr_Node() (destructor) 

Description: 
*/
additiveExpr_Node::~additiveExpr_Node(){

}

