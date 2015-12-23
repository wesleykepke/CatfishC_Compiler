/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: postfixExpr_Node.cpp
Created: October 22, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the postfix expression AST node class of our C compiler.  
*/

#include "postfixExpr_Node.h"
#include "expr_Node.h"

/*
Function: postfixExpr_Node(astNode* A, astNode* B, bool inc, bool dec) (constructor) 

Description: 
*/
postfixExpr_Node::postfixExpr_Node(astNode* A, astNode* B, bool inc, bool dec) : astNode(){
	exprA = A;
	exprB = B;
	incOp = inc;
	decOp = dec;
	name = "postfixExpr_Node";
	id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int postfixExpr_Node::getID() const{
    return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC postfixExpr_Node::gen3AC(){
	threeAC temp;
	std::string reg = "";

	// check for simple case
	if (exprA != NULL && exprB == NULL && !incOp && !decOp) {
		return exprA->gen3AC(); 
	}

	temp = exprA->gen3AC();
	if (temp.ste.isArray()) {
		threeAC tempB = exprB->gen3AC(); 

		// 2D array
		std::vector<int> arrDims = temp.ste.getArrayDimensions();
		if (arrDims.size() == 3) {
			std::string t1 = intTC();
			std::string t2 = intTC(); 
			std::string offset = intTC(); 
			//out3AC << ("MUL " + t1 + " " + tempB.str + " 4") << std::endl;
			//out3AC << ("MUL " + t2 + " " + t1 + " " + std::to_string(arrDims[1])) << std::endl;
			//out3AC << ("ADD " + offset + " " + temp.str + " " + t2) << std::endl;
			output3AC("MULT", t1, tempB.str, "4"); 
			output3AC("MULT", t2, t1, std::to_string(arrDims[2])); 
			output3AC("ADD", offset, temp.str, t2); 
			reg = offset; 

			// decrement dimension count
			arrDims.pop_back(); 
			temp.ste.setArrayDimensions(arrDims);
		}
		else if (arrDims.size() == 2) {
			std::string t1 = intTC();
			std::string t2 = intTC(); 
			std::string offset = intTC(); 
			//out3AC << ("MUL " + t1 + " " + tempB.str + " 4") << std::endl;
			//out3AC << ("MUL " + t2 + " " + t1 + " " + std::to_string(arrDims[1])) << std::endl;
			//out3AC << ("ADD " + offset + " " + temp.str + " " + t2) << std::endl;
			output3AC("MULT", t1, tempB.str, "4"); 
			output3AC("MULT", t2, t1, std::to_string(arrDims[1])); 
			output3AC("ADD", offset, temp.str, t2); 
			reg = offset; 

			// decrement dimension count
			arrDims[0] = arrDims[1];
			arrDims.pop_back(); 
			temp.ste.setArrayDimensions(arrDims);
		}

		// 1D array
		else if (arrDims.size() == 1) {
			std::string t1 = intTC();
			std::string t2 = intTC();
			//out3AC << ("MUL " + t1 + " " + tempB.str  + " 4") << std::endl;
			//out3AC << ("ADD " + t2 + " " + temp.str + " " + t1) << std::endl;
			output3AC("MULT", t1, tempB.str, "4"); 
			output3AC("ADDO", t2, temp.str, t1);
			reg = t2;
		}
	}

	// check for increment
	if (incOp) {
		reg = intTC();
		temp = exprA->gen3AC();
		//out3AC << ("ADD " + reg + " " + temp.str + " 1") << std::endl;
		//out3AC << ("ASSIGN " + temp.str + " " + reg) << std::endl;   

		//output3AC("ADD", reg, temp.str, "1"); 
		output3AC("ADD", temp.str, temp.str, "1"); 
		//output3AC("ASSIGN", temp.str, reg, "-");
	} 

	// check for decrement
	else if (decOp) {
		reg = intTC(); 
		temp = exprA->gen3AC();
		//out3AC << ("SUB " + reg + " " + temp.str + " 1") << std::endl;
		//out3AC << ("ASSIGN " + temp.str + " " + reg) << std::endl; 

		//output3AC("SUB", reg, temp.str, "1"); 
		output3AC("SUB", temp.str, temp.str, "1"); 
		//output3AC("ASSIGN", temp.str, reg, "-");  
	} 

	temp.str = reg;
	return temp; 
}

/*
Function: print(int indent)

Description: 
*/
void postfixExpr_Node::print(int indent){

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

	std::cout << std::endl;
	for(int i = 0; i < indent; i++){
		std::cout << '\t';
	}
	if( incOp ){
		std::cout << "Inc operator (++)";
	}
	if( decOp ){
		std::cout << "Dec operator (--)";
	}
}

/*
Function: ~iterN() (destructor) 

Description: 
*/
postfixExpr_Node::~postfixExpr_Node(){
	std::cout << "Postfix Expression Node destructor" << std::endl;

}



/*
std::ostream &operator<<(std::ostream &out, const postfixExpr_Node& node){
	out << "Output Postfix Expr Node";

	out << "A: ";
	if( node.exprA != NULL ){
		//out << *(node.exprA) ;
		out << "Some ast node";
	}
	else{
		out << "NULL ";
	}
	if( node.exprB != NULL ){
		//out << *(node.exprB) ;
		out << "Some ast node";
	}
	else{
		out << "NULL ";
	}
	if( node.incOp ){
		out << "++";
	}
	if( node.decOp ){
		out << "--";
	}
	out << std::endl;
	return out;
}*/