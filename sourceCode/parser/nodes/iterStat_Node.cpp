/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: iterStat_Node.cpp
Created: November 2, 2015
Last Modified: November 2, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the base AST node class of our C compiler.  
*/

#include "iterStat_Node.h"

/*
Function: iterStat_Node(astNode* A, astNode* B) (constructor) 

Description: 
*/
iterStat_Node::iterStat_Node(astNode* A, astNode* B, astNode* C, astNode* D, bool postCheck) : astNode(){
    exprA = A;
    exprB = B;
    exprC = C;
    exprD = D;
    isPostCheck = postCheck;
    name = "iterStat_Node";
    id = idNum;
}

/*
Function: getID() 

Description: returns ID
*/
int iterStat_Node::getID() const{
    return id;
}


/*
Function: gen3AC()

Description: 
*/
threeAC iterStat_Node::gen3AC(){
    //std::cout << "Generate 3AC for iteration stat node" << std::endl;

    // for do while loops 
    if (isPostCheck) {
        std::string label1 = labelTC();
        std::string tempCondition = intTC(); 
        threeAC tempB; 

        // generate 3AC for stuff inside of do/while loop
        //out3AC << label1 << std::endl; 
        outputLabel(label1);

        if (exprD != NULL) {
            exprD->gen3AC(); 
        }

        // if the user supplies a condition
        if (exprB != NULL) {
            tempB = exprB->gen3AC(); 
            //out3AC << ("ASSIGN " + tempCondition + " " + tempB.str) << std::endl; 
            //output3AC("ASSIGN", tempCondition, tempB.str, "-"); 
             tempCondition = tempB.str;
        }

        // no condition is supplied -> infinite loop
        else {
            //out3AC << ("ASSIGN " + tempCondition + " 1") << std::endl;   
            //output3AC("ASSIGN", tempCondition, "1", "-"); 
            tempCondition = "1";
        }

        // branch back of loop if condition is met
        //out3AC << ("BRNE " + tempCondition + " 0 " + label1) << std::endl;  
        output3AC("BRNE", tempCondition, "0", label1); 
    }

    // every other loop
    else {
        std::string label1 = labelTC(); 
        std::string label2 = labelTC(); 
        std::string label3 = labelTC();
        std::string tempCondition = intTC();  
        threeAC temp; 


        if (exprA != NULL) {
            exprA->gen3AC();
        }

        //out3AC << label1 << std::endl; 
        outputLabel(label1);
     
        // if the user supplies a condition
        if (exprB != NULL) {
            temp = exprB->gen3AC(); 
            //out3AC << ("ASSIGN " + tempCondition + " " + temp.str) << std::endl; 
            //output3AC("ASSIGN", tempCondition, temp.str, "-"); 
            tempCondition = temp.str;
        }

        // no condition is supplied -> infinite loop
        else {
            //out3AC << ("ASSIGN " + tempCondition + " 1") << std::endl;  
            //output3AC("ASSIGN", tempCondition, "1", "-"); 
            tempCondition = "1";
        } 

        // branch out of loop if condition is met
        //out3AC << ("BREQ " + tempCondition + " 0 " + label2) << std::endl;
        output3AC("BREQ", tempCondition, "0", label2);
        // label3 ?

        if (exprD != NULL) {
            exprD->gen3AC(); 
        } 

        // increment/decrement
        if (exprC != NULL) {
            exprC->gen3AC(); 
        }

        // back to loop condition
        //out3AC << ("BR " + label1) << std::endl; 
        output3AC("BR", label1, "-", "-");
        //out3AC << label2 << std::endl; 
        outputLabel(label2);
    }
    threeAC temp;
    temp.str = "";
    return temp;
}

/*
Function: print(int indent)

Description: 
*/
void iterStat_Node::print(int indent){

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

    for(int i = 0; i < indent; i++){
        std::cout << '\t';
    }
    std::cout << "C: ";
    if( exprC != NULL ){
        exprC->print(indent + 1);
        //std::cout << "AST Node";
    }
    else{
        std::cout << "NULL ";
    }

    std::cout << std::endl;
    for(int i = 0; i < indent; i++){
        std::cout << '\t';
    }
    std::cout << "D: ";
    if( exprD != NULL ){
        exprD->print(indent+1) ;
        //std::cout << "AST Node";
    }
    else{
        std::cout << "NULL ";
    }
}

/*
Function: ~iterStat_Node() (destructor) 

Description: 
*/
iterStat_Node::~iterStat_Node(){

}

