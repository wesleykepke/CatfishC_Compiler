/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: registerTable.cpp
Created: December 12, 2015
Last Modified: December 12, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the register table of our C compiler.  
*/

// includes
#include "registerTable.h"

/*
Function: registerTable (constructor) 

Description: Allows for instantiation of a new register table object.
*/
registerTable::registerTable() {
	// $v1
	regTable["$v1"] = "";

	// $a1 - $a3 
	regTable["$a1"] = "";
	regTable["$a2"] = "";
	regTable["$a3"] = "";

	// $t0 - $t9
	regTable["$t0"] = "";
	regTable["$t1"] = "";
	regTable["$t2"] = "";
	regTable["$t3"] = "";
	regTable["$t4"] = "";
	regTable["$t5"] = "";
	regTable["$t6"] = "";
	regTable["$t7"] = "";
	regTable["$t8"] = "";
	regTable["$t9"] = "";

	// $s0 - $s7
	regTable["$s0"] = "";
	regTable["$s1"] = "";
	regTable["$s2"] = "";
	regTable["$s3"] = "";
	regTable["$s4"] = "";
	regTable["$s5"] = "";
	regTable["$s6"] = "";
	regTable["$s7"] = "";

	// iterator 
	regTableItr = regTable.begin(); 					
}

/*
Function: ~registerTable

Description: Destructor of the register table object. 
*/
registerTable::~registerTable() {
	regTable.clear(); 
}

/*
Function: getReg

Parameters:
var: string


Description: Destructor of the register table object. 
*/
std::string registerTable::getReg(std::string var, bool& newReg) {
	// variables
	std::string currentReg = ""; 
	
	// check if variable is within the register table 
	if (idInTable(var, currentReg)) {
		newReg = false;
		return currentReg; 
	}
	else if (findEmptyReg(currentReg)) { // look for an empty location 
		newReg = true; 
		regTable[currentReg] = var;
		return currentReg;
	}
	else { // reg table is full
		//std::cout << "Reg. table is full." << std::endl;
		currentReg = spill(); 
		regTable[currentReg] = var;
		newReg = true;   
		return currentReg; 
	}
}

/*

*/
bool registerTable::idInTable(std::string var, std::string& reg) {
	// search for variable within register table 
	tblItr itr;
	for (itr = regTable.begin(); itr != regTable.end(); itr++) {
		if (itr->second == var) {
			reg = itr->first;
			return true; 
		}
	}

	// variable does not exist in the register table
	reg = "";
	return false; 
} 

/*

*/
bool registerTable::findEmptyReg(std::string& reg) {
	// search for empty variable within register table 
	tblItr itr;
	for (itr = regTable.begin(); itr != regTable.end(); itr++) {
		if (itr->second == "") {
			reg = itr->first;
			return true; 
		}
	}
	reg = "";
	return false;
}

/*

*/
void registerTable::print() {
	// search for empty variable within register table 
	tblItr itr;
	for (itr = regTable.begin(); itr != regTable.end(); itr++) {
		std::cout << itr->first << " =\t" << itr->second << std::endl;
	}
	std::cout << std::endl;
}

std::string registerTable::parseString(std::string str) {
	return str.substr(0, str.find("_")); 
}

/*

*/
std::string registerTable::spill() {
	while (parseString(regTableItr->second) == "LOCV") {
		regTableItr++;
		if (regTableItr == regTable.end()) {
			regTableItr = regTable.begin(); 
		}  
	}

	std::string availReg = regTableItr->first;
	regTableItr++;
	if (regTableItr == regTable.end()) {
			regTableItr = regTable.begin(); 
		} 
	return availReg; 
}