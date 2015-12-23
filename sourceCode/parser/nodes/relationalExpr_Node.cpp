/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: relationalExpr_Node.cpp
Created: November 1, 2015
Last Modified: November 1, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the mult expression AST node class of our C compiler.  
*/

#include "relationalExpr_Node.h"

/*
Function: relationalExpr_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
relationalExpr_Node::relationalExpr_Node(astNode* A, astNode* B, int t) : astNode(){

	exprA = A;
	exprB = B;
	type = t;
	name = "relationalExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int relationalExpr_Node::getID() const{
    return id;
}

/*
Function: gen3AC()

Description: 
*/
threeAC relationalExpr_Node::gen3AC(){
	//std::cout << "Generate 3AC for postfix expression node" << std::endl;
	if (exprA != NULL && exprB == NULL) {
		return exprA->gen3AC(); 
	}

	threeAC tempA = exprA->gen3AC();
	threeAC tempB = exprB->gen3AC(); 
	std::string reg = ""; 
	switch(type) {
		case LTHAN:
			reg = intTC();
			//out3AC << ("LT " + reg + " " + tempA.str + " " + tempB.str) << std::endl;  
			output3AC("LT", reg, tempA.str, tempB.str);
		break;

		case GTHAN:
			reg = intTC();
			//out3AC << ("GT " + reg + " " + tempA.str + " " + tempB.str) << std::endl;  
			output3AC("GT", reg, tempA.str, tempB.str);
		break;


		case LE_OP:
			reg = intTC();
			//out3AC << ("LE " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("LE", reg, tempA.str, tempB.str);
		break; 

		case GE_OP:
			reg = intTC();
			//out3AC << ("GE " + reg + " " + tempA.str + " " + tempB.str) << std::endl; 
			output3AC("GE", reg, tempA.str, tempB.str);
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
void relationalExpr_Node::print(int indent){

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
Function: ~relationalExpr_Node() (destructor) 

Description: 
*/
relationalExpr_Node::~relationalExpr_Node(){

}

