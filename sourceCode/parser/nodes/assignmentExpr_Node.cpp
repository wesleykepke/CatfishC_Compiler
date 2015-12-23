/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: assignmentExpr_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the declaration specifier AST node class of our C compiler.  
*/

#include "assignmentExpr_Node.h"

/*
Function: assignmentExpr_Node(int t) (constructor) 

Description: 
*/
assignmentExpr_Node::assignmentExpr_Node(astNode* A, astNode* B, int t) : astNode(){
	exprA = A;
	exprB = B;
	type = t;
	name = "assignmentExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int assignmentExpr_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC assignmentExpr_Node::gen3AC(){
	//std::cout << "Generate 3AC for assignment expression node" << std::endl;
	if (exprA != NULL && exprB == NULL) {
		return exprA->gen3AC(); 
	}

	threeAC tempA = exprA->gen3AC();
	threeAC tempB = exprB->gen3AC(); 
	std::string reg = ""; 
	switch(type) {
		case ASSIGN:
			//out3AC << ("ASSIGN " + tempA.str + " " + tempB.str) << std::endl;
			output3AC("ASSIGN", tempA.str, tempB.str, "-");  
		break;

		case MUL_ASSIGN:
			reg = intTC();
			//out3AC << ("MUL " + reg + " " + tempA.str + " " + tempB.str) << std::endl;
			//out3AC << ("ASSIGN " + tempA.str + " " + reg) << std::endl;   
			output3AC("MUL", reg, tempA.str, tempB.str);  
			output3AC("ASSIGN", tempA.str, reg, "-");  
		break;

		case DIV_ASSIGN:
			reg = intTC();
			//out3AC << ("DIV " + reg + " " + tempA.str + " " + tempB.str) << std::endl;
			//out3AC << ("ASSIGN " + tempA.str + " " + reg) << std::endl;   
			output3AC("DIV", reg, tempA.str, tempB.str);  
			output3AC("ASSIGN", tempA.str, reg, "-");
		break;

		case ADD_ASSIGN:
			reg = intTC();
			//out3AC << ("ADD " + reg + " " + tempA.str + " " + tempB.str) << std::endl;
			//out3AC << ("ASSIGN " + tempA.str + " " + reg) << std::endl;  
			output3AC("ADD", reg, tempA.str, tempB.str);  
			output3AC("ASSIGN", tempA.str, reg, "-"); 
		break;

		case SUB_ASSIGN:
			reg = intTC();
			//out3AC << ("SUB " + reg + " " + tempA.str + " " + tempB.str) << std::endl;
			//out3AC << ("ASSIGN " + tempA.str + " " + reg) << std::endl;   
			output3AC("SUB", reg, tempA.str, tempB.str);  
			output3AC("ASSIGN", tempA.str, reg, "-");
		break;

		default:
			reg = "";
		break; 
	}
	 
	return tempA; 
}


/*
Function: print(int indent)

Description: 
*/
void assignmentExpr_Node::print(int indent){

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

	std::cout << "B: ";
	if( exprB != NULL ){
		exprB->print(indent + 1);
		//std::cout << "AST Node";
	}
	else{
		std::cout<< "NULL ";
	}

}

/*
Function: ~assignmentExpr_Node() (destructor) 

Description: 
*/
assignmentExpr_Node::~assignmentExpr_Node(){

}

