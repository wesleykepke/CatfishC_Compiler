/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: data_Node.cpp
Created: October 22, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "data_Node.h"

/*
Function: dataNode() (constructor) 

Description: 
*/
data_Node::data_Node(const vals& d, int dt) : astNode(){
	data = d;
	dataType = dt;
	name = "data_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int data_Node::getID() const{
	return id;
}

/*
Function: gen3AC() 

Description: 
*/
threeAC data_Node::gen3AC(){
	std::cout << "Generate 3AC for data node" << std::endl;
}

/*
Function: dataNode() (constructor) 

Description: 
*/
void data_Node::print(int indent){

	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
	std::cout << "Data Node:" << std::endl;
	
	
}

/*
Function: ~iterN() (destructor) 

Description: 
*/
data_Node::~data_Node(){
	std::cout << "Data Node destructor" << std::endl;

}



