/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: symbolTable.cpp
Created: September 27, 2015
Last Modified: October 22, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the symbol table of our C compiler.  
*/

// includes
#include "symbolTable.h"

/*
Function: symbolTable() (constructor) 

Description: Allows for instantiation of a new symbol table object. A new 
scope level is added to the symbol table for global scope. 
*/
symbolTable::symbolTable() {
	// new level is pushed on in the constructor for global scope
	pushLevelOn(); 
}

/*
Function: pushLevelOn()

Description: This function pushes a new scope level onto the stack. 
*/
void symbolTable::pushLevelOn() {
	currentOffset = 0;  
	Bst* newTree = new Bst();
	int outer = table.size()-1;
	if(outer == -1){
		outer = 0;
	}
	scope* newScope = new scope(table.size(), outer, *newTree);
	table.push_back(*newScope);
}

/*
Function: pushLevelOn()

Description: This function pushes a new scope level onto the stack and
allows the caller to specify an outer scope. 

Parameter:
int outer: An integer which represents the outer scope level of the new scope
to be added to the symbol table. 
*/
void symbolTable::pushLevelOn(int outer) {
	Bst* newTree = new Bst();
	scope* newScope = new scope(table.size(), outer, *newTree);
	table.push_back(*newScope);
}

/*
Function: popLevelOff()

Description: This function pops a scope level off of the stack (assuming 
there is a level to pop off).

Note: This function does not return that scope level; instead; the scope
level is deleted entirely.  
*/
void symbolTable::popLevelOff() {
	if (table.size() > 0) {
		table.pop_back();
	}
}

/*
Function: insertNewSymbol(std::string name, int line)

Description: This function will add a new entry to the current scope level
on the stack. 

Parameters:
std::string name: The name of the identifier to be added to the current scope 
level. 
int line: The line number that the associated identifier is located at in the
source program. 
*/
symbolTableEntry* symbolTable::insertNewSymbol(std::string name, int line) {
	// allocate a new symbol table entry object and add it to the BST at
	// the current scope 
	symbolTableEntry* newEntry = new symbolTableEntry(name, line);
	newEntry->setOffset(currentOffset);
	Bst* currentVars = table[table.size() - 1].getBst();
	currentVars->insert(entry(name, *newEntry));
	
	// offset stuff
	incrementOffset(1);

	// search for and declare a pointer to the symbol table entry object in the
	// BST and NOT the one we just created in this function 
	bstItr bItr = currentVars->find(name);
	if(bItr != currentVars->end()) {
		return &bItr->second; 
	}
	else return NULL; 
}

/*
Function: symbolTableEntry* searchForSymbol(std::string symbolToSearch, 
											int& levelSymbolWasFound)

Description: This function will search the symbol table for the desired 
symbol and return a pointer to the corresponding symbol table entry. 

This function replies on the function searchHelper() to search for the
symbol. 

Parameters:
std::string symbolToSearch: The name of the identifier to be searched for.
int& levelSymbolWasFound: Will contain the scope level where symbolToSearch
was located. 
*/
symbolTableEntry* symbolTable::searchForSymbol(std::string symbolToSearch, 
												int& levelSymbolWasFound) {
	if(table.size() == 0){
		levelSymbolWasFound = -1;
		return NULL;
	}
	// recursively search the other scopes to see if the symbol can be located
	return searchHelper(symbolToSearch, levelSymbolWasFound, table.size()-1);
}

/*
Function: symbolTableEntry* searchHelper(std::string symbolToSearch, 
											int& levelSymbolWasFound,
											int searchLevel)

Description: This function will search through the binary seach tree at a 
specific scope level. If the identifier is not located within the current
binary search tree, the function will recursively check the outer scope levels
to see if the identifier can be located. 

Parameters:
std::string symbolToSearch: The name of the identifier to be searched for.
int& levelSymbolWasFound: Will contain the scope level where symbolToSearch
was located.
int searchLevel: Used to resursively check the outer scope levels of a given
scope.  
*/
symbolTableEntry* symbolTable::searchHelper(std::string symbolToSearch, 
											int&levelSymbolWasFound, 
											int searchLevel){
	// variables
	Bst* searchBst = table[searchLevel].getBst();
	bstItr scopeItr;

	// iterate through the current BST in the symbol table
	for (scopeItr = searchBst->begin(); scopeItr != searchBst->end(); scopeItr++) {
		// check for the desired symbol
		if (symbolToSearch == scopeItr->first) {
			levelSymbolWasFound = searchLevel;
			return &(scopeItr->second); 
		}
	}

	// if identifier not found and in global scope, there is nowhere else
	// to search
	if(searchLevel == 0){
		levelSymbolWasFound = -1;
		return NULL;
	}

	// check next outer scope
	else{
		return searchHelper(symbolToSearch, levelSymbolWasFound, 
							table[searchLevel].getOuterScope());
	}
}

/*
Function: searchForSymbol(std::string symbolToSearch)

Description: This function will only search the top of the symbol table
for a given variable. If this variable is found, a pointer to the symbol
table entry will be returned. Otherwise, if the function was unable to locate
the symbol table entry or if the symbol table is empty, the function will 
return NULL. 
*/
symbolTableEntry* symbolTable::searchTopOfStack(std::string symbolToSearch) {
	if (table.size() == 0) {
		return NULL; 
	}

	// variables
	Bst* topBst = table[table.size()-1].getBst();
	bstItr scopeItr;

	// iterate through the top BST in the symbol table
	for (scopeItr = topBst->begin(); scopeItr != topBst->end(); scopeItr++) {
		// check for the desired symbol
		if (symbolToSearch == scopeItr->first) {
			return &(scopeItr->second); 
		}
	}
	return NULL; 
}

/*
Function: getTableSize() const

Description: Returns the size (integer) of the symbol table to the caller. 
*/
int symbolTable::getTableSize() const {
	return table.size();
}

/*
Function: writeToFile()

Description: Will write the contents of the symbol table to a file that
will be located in the "outputFiles" directory.  
*/
void symbolTable::writeToFile() {
	// variables
	bstItr bstItr; 
	symTblItr symbolTableItr; 
	Bst* currentBst;
	std::ofstream outFile;
	outFile.open("../outputFiles/symbolTableContents.txt", std::ofstream::out); 
	int scopeLevel = table.size() - 1;  

	if (scopeLevel == -1) {
		outFile << "Symbol table is empty!" << std::endl;
	}

	else {
		outFile << "=== DISPLAYING SYMBOL TABLE ===" << std::endl;
		for (symbolTableItr = table.begin(); 
				symbolTableItr != table.end(); 
				symbolTableItr++) {
			currentBst = symbolTableItr->getBst();
			for (int i = 0; i <= symbolTableItr->getScopeLevel(); i++) {
				outFile << "\t";
			}

			outFile << ">> Scope level " << symbolTableItr->getScopeLevel() << " in scope ";
			outFile << symbolTableItr->getOuterScope() << "." << std::endl;
			if (currentBst->empty() ) {
				outFile << "\tNo identifiers in this scope." << std::endl; 
			}

			else {
				for (bstItr = currentBst->begin(); bstItr != currentBst->end(); bstItr++) {
					for (int i = 0; i < symbolTableItr->getScopeLevel(); i++) {
						outFile << "\t";
					}
					outFile << "\tVariable: " << bstItr->first << std::endl;
					for (int i = 0; i < symbolTableItr->getScopeLevel(); i++) {
						outFile << "\t";
					}
					//outFile << "\tType: " << bstItr->second.getTypeStr() << std:: endl;
				}
			}
		}
		outFile << "=== END OF SYMBOL TABLE DISPLAY ===" << std::endl;
	}

	// file writing complete 
	outFile.close(); 	
}

/*
Function: writeToFile()

Description: Will write the contents of the symbol table to the output stream. 
*/
void symbolTable::writeToScreen() {
	// variables
	bstItr bstItr; 
	symTblItr symbolTableItr; 
	Bst* currentBst;
	int scopeLevel = table.size() - 1; 

	if (scopeLevel == -1) {
		std::cout << "Symbol table is empty!" << std::endl;
	}

	else {
		std::cout << "=== DISPLAYING SYMBOL TABLE ===" << std::endl; 
		for (symbolTableItr = table.begin(); 
				symbolTableItr != table.end(); 
				symbolTableItr++) {
			currentBst = symbolTableItr->getBst();
			for (int i = 0; i < symbolTableItr->getScopeLevel(); i++) {
				std::cout << "\t";
			}

			std::cout << ">> Scope level " << symbolTableItr->getScopeLevel() << " in scope ";
			std::cout << symbolTableItr->getOuterScope() << "." << std::endl;
			if (currentBst->empty() ) {
				std::cout << "\tNo identifiers in this scope." << std::endl; 
			}
			else {
				for (bstItr = currentBst->begin(); bstItr != currentBst->end(); bstItr++) {
					bstItr->second.displayIdentifierAttributes(symbolTableItr->getScopeLevel()); 
				}
			}
		}
		std::cout << "=== END OF SYMBOL TABLE DISPLAY ===" << std::endl; 
	}
}

void symbolTable::setOffset(int oset) {
	currentOffset = oset;
}

int symbolTable::getOffset() const {
	return currentOffset; 
}

void symbolTable::incrementOffset(int inc) {
	currentOffset += 4*inc; 
}

void symbolTable::decrementOffset(int dec) {
	currentOffset -= 4*dec;
}

/*
Function: ~symbolTable() (destructor)

Description: The destructor for a symbol table object.  
*/
symbolTable::~symbolTable(){
	table.clear(); 
}