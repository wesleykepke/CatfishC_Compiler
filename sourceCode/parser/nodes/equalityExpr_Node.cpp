/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: equalityExpr_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "equalityExpr_Node.h"

/*
Function: equalityExpr_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
equalityExpr_Node::equalityExpr_Node(astNode* A, astNode* B, int t) : astNode(){

	exprA = A;
	exprB = B;
	type = t; 
	name = "equalityExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int equalityExpr_Node::getID() const{
	return id;
}



/*
Function: gen3AC()

Description: 
*/
threeAC equalityExpr_Node::gen3AC(){
	//std::cout << "Generate 3AC for equality expression node" << std::endl;
	if (exprA != NULL && exprB == NULL) {
		return exprA->gen3AC(); 
	}

	threeAC tempA = exprA->gen3AC();
	threeAC tempB = exprB->gen3AC(); 
	std::string reg = ""; 
	switch(type) {
		case EQ_OP:
			reg = intTC();
			//out3AC << ("EQ " + reg + " " + tempA.str + " " + tempB.str) << std::endl
			output3AC("EQ", reg, tempA.str, tempB.str); 
		break;

		case NE_OP:
			reg = intTC();
			//out3AC << ("NE " + reg + " " + tempA.str + " " + tempB.str) << std::endl;  
			output3AC("NE", reg, tempA.str, tempB.str); 
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
void equalityExpr_Node::print(int indent){

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
Function: ~equalityExpr_Node() (destructor) 

Description: 
*/
equalityExpr_Node::~equalityExpr_Node(){

}

