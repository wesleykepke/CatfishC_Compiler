/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: funcDef_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "funcDef_Node.h"

/*
Function: funcDef_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
funcDef_Node::funcDef_Node(astNode* A, astNode* B, astNode* C, astNode* D) : astNode(){
	exprA = A;
	exprB = B;
	exprC = C;
	exprD = D;
	name = "funcDef_Node";
	source = exprB->getSourceCode(); 
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int funcDef_Node::getID() const{
	return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC funcDef_Node::gen3AC(){
	//std::cout << "Generate 3AC for function definition node" << std::endl;
	threeAC temp;
	//out3AC << "Label_" << exprB->getName() << std::endl;
	outputLabel("Label_"+exprB->getName());
	outputSource(source);
	//out3AC << source << std::endl; 
	temp = exprD->gen3AC(); 
	return temp; 
}

/*
Function: print(int indent)

Description: 
*/
void funcDef_Node::print(int indent){

	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
}

/*
Function: ~funcDef_Node() (destructor) 

Description: 
*/
funcDef_Node::~funcDef_Node(){

}

