/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: leaf_Node.cpp
Created: October 22, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)
*/

#include "leaf_Node.h"

/*
Function: leaf_Node() (constructor) 

Description: 
*/
leaf_Node::leaf_Node(const vals& d, int dt, std::string n) : astNode(){
	data = d;
	dataType = dt;
	name = n;
	id = idNum;
	myOffset = 0;
	if (dataType == STE_T) {
		myScope = data._ste->getScopeLevel();
		myOffset = data._ste->getOffset(); 
		ste = *(data._ste);
		isArray = data._ste->isArray();
	} 
	else {
		myScope = -1; 
	}
}

/*
Function: getID() 

Description: returns ID
*/
int leaf_Node::getID() const{
	return id;
}

/*
Function: gen3AC() 

Description: 
*/
threeAC leaf_Node::gen3AC(){
	//std::cout << "Generate 3AC for leaf node" << std::endl;
	threeAC temp;
	switch(dataType) {
		case INT_T:
			temp.str = std::to_string(data._num);
			return temp;
		break;

		case FLOAT_T:
			temp.str = std::to_string(data._dec);
			return temp;
		break;

		case STE_T:
			if (myScope == 0) {
				temp.str = ("GLV_" + std::to_string(myOffset));
			}
			else {
				temp.str = ("LOCV_" + std::to_string(myOffset));
			}
			temp.ste = ste;

			return temp;
		break;

		default:
			//out3AC << "3AC not supported for this leaf node." << std::endl;
			temp.str = "";
			return temp;  
		break;
	} 

		/*
	temp.str = "";
	return temp; */
}

/*
Function: dataNode() (constructor) 

Description: 
*/
void leaf_Node::print(int indent){

	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
	std::cout << "Data Node:" << std::endl;
	
	
}

/*
Function: ~iterN() (destructor) 

Description: 
*/
leaf_Node::~leaf_Node(){
	std::cout << "Data Node destructor" << std::endl;

}



