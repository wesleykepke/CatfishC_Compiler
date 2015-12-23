/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: registerTable.h
Created: December 12, 2015
Last Modified: December 12, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the register table of our C compiler.
*/

// header guards
#ifndef REGISTER_TABLE_H
#define REGISTER_TABLE_H

// includes
#include <unordered_map>
#include <string>
#include <iostream>

// typedefs
typedef std::unordered_map<std::string, std::string> tbl;
typedef std::unordered_map<std::string, std::string>::iterator tblItr;

// class declaration
class registerTable {
	public:
		// constructors
		registerTable();
		~registerTable(); 

		// register table functions 
		std::string getReg(std::string var, bool& newReg);


		void print();

	private:
		// object members
		tbl regTable;
		tblItr regTableItr; 

		// private object functions
		bool idInTable(std::string var, std::string& reg);
		bool findEmptyReg(std::string& reg);
		std::string spill(); 
		std::string parseString(std::string str);
};

#endif // REGISTER_TABLE_H