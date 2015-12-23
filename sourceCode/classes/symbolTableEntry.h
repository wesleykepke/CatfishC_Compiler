/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: symbolTableEntry.h
Created: September 27, 2015
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the header file for the objects that will reside in the symbol table
of our ANSI C compiler. 
*/

// header guards
#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

// includes
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
#include <climits>
#include "../parser/cParser.tab.h" // used for token values and other elements 

// externs
extern int isValidType(std::vector<int> type);

// used to determine what the type specifier of an identifier is
enum Type{
    CHAR_T,
    DOUBLE_T,
    FLOAT_T,
    INT_T,
    LONG_T,
    LONG_LONG_T,
    LONG_DOUBLE_T,
    SHORT_T,
    STR_T,
    STE_T,
    VOID_T
};

// used to actually store the value associated with the identifier 
typedef union {
    char _char;
    long long _num;
    long double _dec; // decimal
    //char _str[256];    
} entryVals; 

// typdefs to reduce keystrokes
typedef std::pair<std::vector<int>, int> pair;

class symbolTableEntry {
    public:
        // constructors
        symbolTableEntry(); 
        symbolTableEntry(std::string name, int lineNumber);
        symbolTableEntry(const symbolTableEntry& other) ;
        symbolTableEntry& operator=(const symbolTableEntry& other);
        
        // basic functions
        bool setIdentifierType(std::vector<int> type);
        std::vector<int> getIdentifierType_Vector() const;
        int getIdentifierType_Enum() const;
        std::string getIdentifierType_String() const; 
        void setIdentifierName(std::string name);
        std::string getIdentifierName() const; 
        bool setIdentifierValue(const node& src, bool& warningFlag, std::string& message);
        node* getIdentifierValue() const; 
        void printIdentifierValue() const;
        int getScopeLevel() const;
        void setScopeLevel(int scopeLevel); 

        // functions required if the entry is a function
        bool isFunction() const;
        void setFunction();
        void addParameter(std::vector<int> parameterType);
        int getNumParams() const;
        void viewParams() const;
        std::vector< std::vector<int> > getParams() const; 
        bool checkParams(const std::vector<symbolTableEntry*>& callingParams,
                            std::string& errorMessage) const;  

        // functions required if the entry is a pointer
        bool isPointer() const;
        void setPointer(); 
        void setNumPtrs(int number);
        int getNumPtrs() const; 
        
        // functions required if the entry is an array
        void setArray();
        bool isArray() const;  
        void addArrayDimension(int size);
        std::vector<int> getArrayDimensions() const;
        void setArrayDimensions(std::vector<int> dims);
        int getNumArrDims() const;

        // offset functions
        int getOffset() const; 
        void setOffset(int oset); 

        // other functions that may come in handy 
        int getLineNumber() const;
        void displayIdentifierAttributes(int tabCount) const; 

        // destructor
        ~symbolTableEntry(); 

    private:
        // used to store and determine what type of data is associated with
        // the entry
        entryVals entryVal; 
        int entryType;
        int myScope; 

        // offset into activation frame
        int offset; 

        // attributes associated with a symbol table entry
        std::string identifierName;
        std::vector<int> identifierType;   
        int lineNum;
        bool isSigned;
        bool isUnsigned; 
        
        // attributes needed if entry is a pointer
        bool isPtr;
        int numPtrs;

        // attributes needed if entry is an array
        bool isArr;
        std::vector<int> arrayDimensions;

        // attributes needed if entry is a function  
        bool isFunc;
        std::vector< std::vector<int> > parameters;
 
        // private functions - used only by members of the class
        std::string intTypeToStr(int someType) const;
        void printTabs(int tabCount) const;  
};

#endif // SYMBOL_TABLE_ENTRY_H