/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: symbolTableEntry.cpp
Created: September 27, 2015
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the implementation file for the objects that will reside in the symbol
table of our C compiler. 
*/

// includes
#include "symbolTableEntry.h"

/*
Function: symbolTableEntry() (constructor) 

Description: Allows for instantiation of a new symbol table entry object.
All data attributes are initialized to default values.  
*/
symbolTableEntry::symbolTableEntry() {
	// entry data info
	entryType = -1;
	myScope = -1; 

	// offset stuff
	offset = 0;

	// entry data attributes
	identifierName = "default constructor!";
	identifierType.clear(); 
	lineNum = -1;
	isSigned = false;
	isUnsigned = false; 

	// entry pointer attributes
	isPtr = false; 
	numPtrs = -1; 

	// entry array attributes
	isArr = false;
	arrayDimensions.clear();  

	// entry function attributes
	isFunc = false;
	parameters.clear(); 
}

/*
Function: symbolTableEntry(int lineNumber) (constructor) 

Parameters:
int lineNumber: The line number that the identifier is located at. 

Description: Allows for instantiation of a new symbol table entry object (
with a specified line number. 
*/
symbolTableEntry::symbolTableEntry(std::string name, int lineNumber) {
	// entry data info
	entryType = -1;
	myScope = -1;

	// entry data attributes
	identifierName = name;
	identifierType.clear();
	lineNum = lineNumber;
	isSigned = false;
	isUnsigned = false; 

	// entry pointer attributes
	isPtr = false; 
	numPtrs = -1; 

	// entry array attributes
	isArr = false;
	arrayDimensions.clear();
	
	// entry function attributes
	isFunc = false;
	parameters.clear();
}
symbolTableEntry::symbolTableEntry(const symbolTableEntry& other) { 
	*this = other;
}
/*
Function: overloaded assignment operator
*/
symbolTableEntry& symbolTableEntry::operator=(const symbolTableEntry& other) { 
	if (this != &other) {
		entryVal = other.entryVal;
		entryType = other.entryType;
		myScope = other.myScope;
		offset = other.offset;
		identifierName = other.identifierName; 
		identifierType = other.identifierType;
		lineNum = other.lineNum;
		isSigned = other.isSigned;
		isUnsigned = other.isUnsigned;
		isPtr = other.isPtr;
		numPtrs = other.numPtrs;
		isArr = other.isArr;
		arrayDimensions = other.arrayDimensions;
		isFunc = other.isFunc;
		parameters = other.parameters;
	}
	return *this;
}

/*
Function: setIdentifierType(std::vector<int> type)

Parameters:
std::vector<int> type: A vector of tokens is used to determine the data type
of the current symbol. 

Description: Allows the caller to specify the data type of the symbol
table entry. This function will return false if the supplied vector contains
an invalid data type. 
*/
bool symbolTableEntry::setIdentifierType(std::vector<int> type) {
	// check if the incoming vector contains a valid data type
	entryType = isValidType(type);

	if(entryType != -1){
		identifierType = type;
		return true;
	}

	else return false;
}

/*
Function: getIdentifierType_Vector() const

Description: Returns to the caller the vectorized form of the entry
data type.
*/
std::vector<int> symbolTableEntry::getIdentifierType_Vector() const {
	return identifierType; 
}

/*
Function: getIdentifierType_Enum() const

Description: This function will return the corresponding token
value which depends on what type of value is stored in the symbol 
table entry object. 
*/
int symbolTableEntry::getIdentifierType_Enum() const {
	return entryType;
}

/*
Function: getIdentifierType_String() const

Description: This function will return the corresponding string
of the identifier's data type.
*/
std::string symbolTableEntry::getIdentifierType_String() const {
	std::string typeStr = "";
	for (unsigned int i = 0; i < identifierType.size(); i++) {
		typeStr += intTypeToStr(identifierType[i]);
	}
	return typeStr; 
}

/*
Function: setIdentifierName(std::string name)

Parameters:
std::string name: The new name of the symbol table entry. 

Description: Allows the caller to specify the name and/or rename 
the symbol table entry.  
*/
void symbolTableEntry::setIdentifierName(std::string name) {
	identifierName = name; 
}

/*
Function: getIdentifierName() const

Description: This function will return the name of the symbol
table entry.  
*/
std::string symbolTableEntry::getIdentifierName() const { 
	return identifierName; 
}

/*
Function: setIdentifierValue(const node& src)

Parameters:
const node& src: The incoming object for our data. This object contains 
a specifier as to what the datatype of the value is and also includes
the actual value itself.  

Description: Sets the value of a corresponding identifier. 
*/
bool symbolTableEntry::setIdentifierValue(const node& src, bool& warningFlag,
											 std::string& message){
	int srcType = 0;
	if(src.valType == STE_T){
		srcType = src.val._ste->getIdentifierType_Enum();
	}
	else{
		srcType = src.valType;
	}
	// check the data type of the current identifier and continue processing 
	switch(entryType) {
		case LONG_LONG_T:
			// warning, up conversion
			if(srcType == LONG_T || srcType == INT_T || srcType == SHORT_T  ){
				// cout statements here?
				warningFlag = true;
				message = "Up conversion from integer to long long.";
			}

			// warning, converting character to integer
			else if(srcType == CHAR_T){
				warningFlag = true;
				message = "Conversion from char to long long.";
			}

			// warning, down conversion from float to long long
			else if(srcType == FLOAT_T || srcType == DOUBLE_T || srcType == LONG_DOUBLE_T){
				warningFlag = true;
				message = "Down conversion from decimal to long long.";
			}
		break;

		case LONG_T:
			// warning, up conversion
			if(srcType == INT_T || srcType == SHORT_T){
				warningFlag = true;
				message = "Up conversion from integer to long.";
			}

			// warning, converting character to integer
			else if(srcType == CHAR_T){
				warningFlag = true;
				message = "Conversion from character to long.";
			}

			// warning, down conversion from float to long
			else if(srcType == FLOAT_T || srcType == DOUBLE_T || srcType == LONG_DOUBLE_T){
				warningFlag = true;
				message = "Down conversion from decimal to long.";
			}

			// warning???
			else if(srcType == LONG_LONG_T){
				warningFlag = true;
				message = "Conversion from long long to long.";
			}

			// checking overflow
			if(src.val._num > LONG_MAX){
				return false;
			}
		break;

		case INT_T:
			// warning, up conversion
			if(srcType == SHORT_T  ){
				warningFlag = true;
				message = "Up conversion from short to integer.";
			}

			// warning, converting character to integer
			else if(srcType == CHAR_T){
				warningFlag = true;
				message = "Conversion from char to integer.";
			}

			// warning, down conversion from float to long long
			else if(srcType == FLOAT_T || srcType == DOUBLE_T || srcType == LONG_DOUBLE_T ){
				warningFlag = true; 
				message = "Down conversion from double to integer.";
			}

			// warning???
			else if(srcType == LONG_T ||  srcType == LONG_LONG_T ){
				warningFlag = true;
				message = "Down conversion from long to integer.";
			}

			// checking overflow
			if(src.val._num > INT_MAX){
				return false;
			}
		break;

		case SHORT_T:
			// warning, converting character to short
			if(srcType == CHAR_T){
				warningFlag = true;
				message = "Conversion from char to short.";
			}

			// warning, down conversion from float to long long
			else if(srcType == FLOAT_T || srcType == DOUBLE_T || srcType == LONG_DOUBLE_T){
				warningFlag = true;
				message = "Down conversion from decimal to short.";
			}

			// warning???
			else if(srcType == INT_T || srcType == LONG_T ||  srcType == LONG_LONG_T ){
				warningFlag = true;
				message = "Conversion from integer to short.";
			}

			// checking overflow
			if(src.val._num > SHRT_MAX){
				return false;
			}
		break;

		case FLOAT_T:
			// warning, converting character to float?
			if(srcType == CHAR_T){
				warningFlag = true;
				message = "Converting character to decimal.";
			}

			// warning, down conversion from float to long long
			else if(srcType == DOUBLE_T || srcType == LONG_DOUBLE_T){
				warningFlag = true;
				message = "Down conversion from double to decimal.";
			}

			// warning???
			else if(srcType == INT_T || srcType == LONG_T ||  srcType == LONG_LONG_T ){
				warningFlag = true;
				message = "Up conversion from integer to decimal.";
			}

			// checking overflow -- why just _num and not also _dec?
			if(src.val._num > SHRT_MAX){
				return false;
			}
		break;

		case LONG_DOUBLE_T:
			// warning, converting character to long double?
			if(srcType == CHAR_T){
				warningFlag = true;
				message = "Converting character to decimal.";
			}

			// warning, down conversion from float to long long
			else if(srcType == DOUBLE_T || srcType == FLOAT_T){
				warningFlag = true;
				message = "Down conversion from double to decimal.";
			}

			// warning???
			else if(srcType == INT_T || srcType == LONG_T ||  srcType == LONG_LONG_T ){
				warningFlag = true;
				message = "Up conversion from integer to decimal.";
			}

			// checking overflow -- why just _num and not also _dec?
			if(src.val._num > SHRT_MAX){
				return false;
			}
		break; 

		case DOUBLE_T:

		break; 

		case CHAR_T:
			if(src.val._char > CHAR_MAX){
				return false;
			}
		break;

		// should only occur if the symbol table entry has not been
		// assigned a data type
		default:
			// std::cout << "Inside of setIdentifierValue() in the case where";
			// std::cout << " the identifier does not have a data type." << std::endl; 
		break;	
	}
	// the identifier has successfully been assigned a new value
	return false;
}

/*
Function: getIdentifierValue() const

Description: This function creates a new node object and initializes it to 
contain both the data and an indicator as to the type of data. 
*/
node* symbolTableEntry::getIdentifierValue() const {
	node* n = new node();
	n->astPtr = NULL;
	n->valType = entryType;
	switch(entryType) {
		case LONG_LONG_T:
		case LONG_T:
		case INT_T:
		case SHORT_T:
			n->val._num = entryVal._num;
			break;

		case FLOAT_T:
		case DOUBLE_T:
		case LONG_DOUBLE_T:
			n->val._dec = entryVal._dec;
			break;

		case CHAR_T:
			n->val._char = entryVal._char;
			break;

		case STR_T:
			//strcpy(n->val._str, entryVal._str);
			break;

		// should only occur if the symbol table entry has not been
		// assigned a data type
		default:
			std::cout << "Inside of getIdentifierValue() in the case where";
			std::cout << " the identifier does not have a data type." << std::endl;
			return NULL;  
			break;		
	}

	return n; 
} 

/*
Function: printIdentifierValue() const

Descrition: Prints the value of a corresponding identifier. 
*/
void symbolTableEntry::printIdentifierValue() const {
	switch(entryType) {
		case LONG_LONG_T:
		case LONG_T:
		case INT_T:
		case SHORT_T:
 			std::cout << entryVal._num << std::endl; 
			break;

		case FLOAT_T:
		case DOUBLE_T:
		case LONG_DOUBLE_T:
			std::cout << entryVal._dec << std::endl; 
			break;

		case CHAR_T:
			std::cout << entryVal._char << std::endl; 
			break;

		case VOID_T:
			std::cout << "Identifier is void and does not have a value";
			std::cout << std::endl; 
			break;

		default:
			std::cout << "Inside of printIdentifierValue() in the case where";
			std::cout << " the identifier does not have a data type." << std::endl;
			break;
	} 
}

/*
Function: getScopeLevel() const

Description: Allows the caller to receive the scope level that 
the current symbol table entry is located. 
*/
int symbolTableEntry::getScopeLevel() const {
	return myScope; 
}

/*
Function: setScopeLevel() const

Description: Allows the caller to set the scope level. 
*/
void symbolTableEntry::setScopeLevel(int scopeLevel) {
	myScope = scopeLevel; 
} 

/*
Function: isFunction() const

Description: Allows the caller to determine if the entry is a 
function or not. 
*/
bool symbolTableEntry::isFunction() const {
	return isFunc; 
}

/*
Function: setFunction()

Description: Allows the caller to inform the symbol table entry that the 
current identifier is indeed a function. 
*/
void symbolTableEntry::setFunction() {
	isFunc = true;  
}

/*
Function: addParameter(int token)

Parameters:
vector<int> parameterType: A vector of tokens (integers).

Description: Allows the caller to add a formal parameter to
the symbol table entry. 
*/
void symbolTableEntry::addParameter(std::vector<int> parameterType) {
	parameters.push_back(parameterType);
}

/*
Function: getNumberOfParams() const

Description: Returns the number of formal parameters for a function. 
*/
int symbolTableEntry::getNumParams() const {
	return parameters.size(); 
}

/*
Function: viewParams() const

Description: This function is used to print the data types of the
parameters to the output stream. 
*/
void symbolTableEntry::viewParams() const {
	std::string outputStr = "";
	std::vector<int> tempVec; 
	for(unsigned int i = 0; i < parameters.size(); i++) {
		tempVec = parameters[i];
		for(unsigned int j = 0; j < tempVec.size(); j++) {
			outputStr += intTypeToStr(tempVec[j]);
		}
		std::cout << "Formal parameter: " << outputStr << std::endl; 
		outputStr = ""; 
		tempVec.clear(); 
	}
}

/*
Function: getParams() const

Description: This function is used to obtain the data types of the
formal parameters of a function. 
*/
std::vector< std::vector<int> > symbolTableEntry::getParams() const {
	return parameters; 
} 

/*
Function: checkParams() const

Parameters: 
const std::vector<symbolTableEntry*>& callingParams: This is an array of
symbol table pointers. Using the pointers in this array, the function is
able to obtain the data type of each formal parameter. This is how the 
type checking occurs. 

Description: This function is used to check if a vector of input parameters
(symbol table entries) matches the parameters that are stored in the current
symbol table entry. 
*/
bool symbolTableEntry::checkParams(const std::vector<symbolTableEntry*>& callingParams,
									std::string& errorMessage) const {
	// if there is a different number of actual params compared to 
	// the number of formal parameters stored in the symbol table entry,
	// the parameters cannot match up
	if (callingParams.size() != parameters.size()) {
		return false; 
	}

	// if they are the same size, we must check the data type of each parameter
	std::vector<int> myParameterType;
	std::vector<int> guestsParameterType;
	for(unsigned int i = 0; i < parameters.size(); i++) {
		myParameterType = parameters[i]; 
		guestsParameterType = callingParams[i]->getIdentifierType_Vector(); 
		if (myParameterType != guestsParameterType) {
			errorMessage = "Expected function parameter of type ";
			for (unsigned int j = 0; j < myParameterType.size(); j++) {
				errorMessage += intTypeToStr(myParameterType[j]);
				if ( (j + 1) != myParameterType.size()) {
					errorMessage += " ";
				}
			}
			errorMessage += " but received ";
			for (unsigned int j = 0; j < guestsParameterType.size(); j++) {
				errorMessage += intTypeToStr(guestsParameterType[j]);
				if ( (j + 1) != guestsParameterType.size()) {
					errorMessage += " ";
				}
			}
			errorMessage += "."; 
			return false; 
		}
		myParameterType.clear();
		guestsParameterType.clear(); 
	} 
 
	// if each parameter was the same, the parameters then match
	return true; 
} 

/*
Function: isPointer() const

Description: This function will return whether or not the associated identifier
is a pointer or not. 
*/
bool symbolTableEntry::isPointer() const {
	return isPtr;
};

/*
Function: setPointer()

Description: This function will assign the flag which indicates that the 
current symbol table entry is an identifier. 
*/
void symbolTableEntry::setPointer() {
	isPtr = true; 
};

/*
Function: setNumPtrs(int number)

Description: Assigns the number of pointers associated with a symbol 
table entry. 
*/
void symbolTableEntry::setNumPtrs(int number) {
	numPtrs = number;
}

/*
Function: getNumPtrs() const

Description: Returns the number of pointers associated with a symbol 
table entry. 
*/
int symbolTableEntry::getNumPtrs() const {
	return numPtrs;
}

/*
Function: setArray()

Description: This function will assign the flag which indicates that the 
current symbol table entry is an array. 
*/
void symbolTableEntry::setArray() {
	isArr = true;
}

/*
Function: isArray() const

Description: This function will return whether or not the associated identifier
is a array or not.  
*/
bool symbolTableEntry::isArray() const {
	return isArr; 
}

/*
Function: addArrayDimension(int size)

Parameters:
int size: The size of the new array dimension. 

Description: Will create a new dimension for the array based on the size passed
to the function.  
*/
void symbolTableEntry::addArrayDimension(int size) {
	if (isArr) {arrayDimensions.push_back(size);} 
}

/*
Function: getArrayDimensions() const

Description: Returns a vector filled with the sizes of the array dimensions.
*/
std::vector<int> symbolTableEntry::getArrayDimensions() const {
	return arrayDimensions; 
} 

/*
Function: setArrayDimensions()

Description: Allows the caller to specify the dimensions of the array through
a vector.
*/
void symbolTableEntry::setArrayDimensions(std::vector<int> dims) {
	arrayDimensions = dims; 
}

/*
Function: getNumArrDims() const

Description: Returns an integer which represents the total number of dimensions
associated with an array.
*/
int symbolTableEntry::getNumArrDims() const {
	if (isArr) {return arrayDimensions.size();}
	else return 0; 
} 

int symbolTableEntry::getOffset() const {
	return offset; 
} 

void symbolTableEntry::setOffset(int oset) {
	offset = oset; 
}

/*
Function: getLineNumber() const

Description: This function will return the line number that the associated 
identifier was located on from the source program. 
*/
int symbolTableEntry::getLineNumber() const {
	return lineNum; 
}

/*
Function: displayIdentifierAttributes() const

Description: This function will print out all of the attributes associated 
with a symbol table entry. 
*/
void symbolTableEntry::displayIdentifierAttributes(int tabCount) const {
	int idNumTemp = 0;
	std::string idTemp = getIdentifierName();
	printTabs(tabCount);
	std::cout << "Identifier name: " << idTemp << std::endl;
	idTemp = getIdentifierType_String();
	printTabs(tabCount);
	std::cout << "Identifier type: " << idTemp << std::endl;
	printTabs(tabCount);
	std::cout << "Identifier value: ";
	printIdentifierValue(); 
	std::cout << std::endl;
	//!!!!!!!!!!!!!!!!! CHECK THIS LATER !!!!!!!!!!!
	
	if (isFunc) {
		idNumTemp = getNumParams(); 
		std::cout << "Identifier is a function." << std::endl;
		std::cout << "Identifier has " << idNumTemp << " parameters.";
		std::cout << std::endl; 
		std::cout << "Identifier parameters: " << std::endl;
		viewParams(); 
	}

	else if (isPtr) {
		idNumTemp = getNumPtrs();
		std::cout << "Identifier is a pointer." << std::endl;
		std::cout << "Identifier has " << idNumTemp << " parameters.";
		std::cout << std::endl; 
	}

	else if (isArr) {
		idNumTemp = getNumArrDims();
		std::cout << "Identifier is an array." << std::endl;
		std::cout << "Identifier has " << idNumTemp << " dimensions.";
		std::cout << std::endl;
		std::cout << "Identifier dimensions: " << std::endl;
		for (unsigned int i = 0; i < arrayDimensions.size(); i++) {
			std::cout << "Dimension #" << i << " :" << arrayDimensions[i] << std::endl; 
		} 
	}
}

/*
Function: ~symbolTableEntry() (desctuctor)

Descrition: This is the destructor for a symbol table entry object.  
*/
symbolTableEntry::~symbolTableEntry() {
	// entry data info
	entryType = -1;

	// entry data attributes
	identifierName = "";
	identifierType.clear(); 
	lineNum = -1;
	isSigned = false;
	isUnsigned = false; 

	// entry pointer attributes
	isPtr = false; 
	numPtrs = -1; 

	// entry array attributes
	isArr = false;
	arrayDimensions.clear();  

	// entry function attributes
	isFunc = false;
	parameters.clear();  
}

/*
Function: intTypeToStr(Type someType) const

Parameter:
int someType: An token value (an integer). 

Description: Takes in an integer type which will convert that type
to a string object.  
*/
std::string symbolTableEntry::intTypeToStr(int someType) const {
	std::string str; 
	switch(someType) {
		case CHAR_T:
			str = "char";
			break;

		case DOUBLE_T:
			str = "double";
			break;

		case FLOAT_T:
			str = "float";
			break;

		case INT_T:
			str = "int";
			break;

		case LONG_T:
			str = "long";
			break;

		case LONG_LONG_T:
			str = "long long";
			break;

		case LONG_DOUBLE_T:
			str = "long double";
			break;

		case SHORT_T:
			str = "short";
			break;

		case VOID_T:
			str = "void";
			break;

		default:
			str = "invalid type";
			break;
	}
	return str; 
}

/*
Function: printTabs(int tabCount) const

Parameters:
int tabCount: Represents the number of tabs to output to the console.

Descriptions: Prints tabs. 
*/
void symbolTableEntry::printTabs(int tabCount) const {
	for (int i = 0; i < tabCount; i++) {
		std::cout << "\t"; 
	}
} 