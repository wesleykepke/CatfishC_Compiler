/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: symbolTable.cpp
Created: September 28, 2015
Last Modified: October 16, 2015
Class: CS 460 (Compiler Construction)

This is the main file for the front end of our ANSI C compiler. 
*/

// includes
#include <iostream>
#include <fstream>
#include "../classes/symbolTable.h"
#include <stdlib.h>
#include "../classes/registerTable.h"
#include <unordered_set>
#include <unordered_map>
#include <cctype>
using namespace std;

#include "optionparser.h"

// Command line parser
enum  optionIndex { UNKNOWN, 
					HELP, 
					ASSEM, 
					AC,
					COMP,
					OUT,
					DEBUG };
const option::Descriptor usage[] =
{
	{HELP, 0,"", "help",option::Arg::None, "\t--help  \tPrint usage and exit." },
	{ASSEM, 0,"S","assembly",option::Arg::None, "\t--assembly, -S  \tOutput assembly." },
	{AC, 0, "q", "3AC", option::Arg::None,"\t--3AC, -q  \tOutput 3 address code."},
	{COMP, 0, "c", "compile", option::Arg::Required,"\t--compile <file>, -c <file> \tCompile <file>."},
	{OUT, 0, "o", "out", option::Arg::Required,"\t--output <file>, -o <file> \tOutput to <file>."},
	{DEBUG, 0, "d", "", option::Arg::Required,"\t-d[l|y|s] \tOutput lex/yacc/symbol table."},
	{0,0,0,0,0,0}
};

// externs 
extern int yyparse();
extern FILE* yyin; 
extern symbolTable table; 
extern std::string currentSourceCodeLine; 
extern int yylineno;
extern bool endline;

// Debug flags
bool LFLAG = false; 
bool YFLAG = false;
bool AFLAG = false;
bool ASMFLAG = false;

// File output
ofstream outL;
ofstream outY;
ofstream outG;
ofstream outA;
ofstream out3AC; 
FILE* out3ac;

// Source code
unordered_set<std::string> sourceHistory; 
vector<string> sourceCode;

// 3ac output functions
void outputASM(std::string command, std::string dest, std::string src1, 
					std::string src2, FILE* asmFile, registerTable& table);
void output3AC(std::string, std::string, std::string, std::string);
void outputSource(std::string source);
void outputLabel(std::string label);

// ASM functions
int asmLabelCount = 0; 
string parseString(string str); 
string getOffset(string str);
string getASMLabel(); 

int main(int argc, char* argv[]) {

	bool fileSpecified = false;
	char inputFile[256];
	string filename;
	ofstream outFile;
	int j;
	char input;

	// Command line parsing
	argc-=(argc>0); argv+=(argc>0);
	option::Stats  stats(usage, argc, argv);
	std::vector<option::Option> options(stats.options_max);
	std::vector<option::Option> buffer(stats.buffer_max);
  	option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

	if (parse.error())
		return 1;

	if (options[HELP] || argc == 0) {
	    option::printUsage(std::cout, usage);
	    return 0;
	}

	for (int i = 0; i < parse.optionsCount(); ++i)
	{
	    option::Option& opt = buffer[i];
	    switch (opt.index())
	    {
			case AC:
				AFLAG = true;
				out3AC.open("../outputImages/3AC.txt");
				out3ac = fopen("../outputFiles/3AC.txt", "w");
				break;

			case ASSEM:
				ASMFLAG = true;
				cout << "Assembly code TBD." << endl;
				break;
			case COMP:
				//inputFile = opt.arg;
				strcpy(inputFile, opt.arg);
				fileSpecified = true;
				break;
			case OUT:
				filename = opt.arg;
				filename += "../outputFiles/";
				outFile.open(filename.c_str());
				outFile << "Final output will be here." << endl;
				outFile.close();
				break;
			case DEBUG:
				j = 0;
				input = opt.arg[j];
				while(input != '\0'){
					switch(input){
						case 'l':
							LFLAG = true;
							outL.open("../outputFiles/tokens.txt", std::ofstream::out);
							break;
						case 'y':
							YFLAG = true;
							outY.open("../outputFiles/reductions.txt", std::ofstream::out);
							outG.open("graph.dot");
							outG << "digraph{\n";
							break;
						case 's':
							//TODO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
							break;
						default:
							break;
					}
					j++;
					input = opt.arg[j];
				}
				break;
	      	default:
	       		break;
	    }
	}
	// read input file

	if( !fileSpecified ){
		cout << "Error: Please enter file name (See --help)." << endl;
		return 0;
	}

	// Read in source code
	ifstream fin (inputFile);
	char str[256];
	while( fin.good() ){	
		fin.getline(str, 256);
		sourceCode.push_back((string)str);
		
	}
	fin.close();

	// Set lexer input
	yyin = fopen(inputFile, "r");

	// Prepare AST graph
	outA.open("ast.dot");
	outA << "digraph{\n" << "graph[ordering = out]\n";

	// Initialize output
	cout << "Main program - compiler driver." << endl;
	if(LFLAG){
		outL << std::endl << "=================================================================" << std::endl;
		outL << "Line #" << yylineno << ": " << std::endl;
		outL << sourceCode[0] << std::endl;
	}
	if(YFLAG){
		outY << std::endl <<"=================================================================" << std::endl;
		outY << "Line #" << yylineno << ": " << std::endl;
		outY << sourceCode[0] << std::endl;
	}


	// Parser
	cout << "Beginning parse" << endl;
	yyparse();  
	cout << "Parse complete" << endl;

	// Close files
	if (LFLAG) {
		outL.close();
	}
	if( YFLAG ){
		// Finish graph
		outG << "}" << endl;
		outG.close();
		system("rm -f graph.dot");
		//system("gnome-open graph.png");
		outY.close();
	}

	// Finish AST graph
	if( AFLAG )
	{
		outA << "}" << endl;
		outA.close();
		out3AC.close(); 
		fclose(out3ac); 
		cout << "Generating AST" << endl;
		system("dot -Tpng ast.dot -o ast.png");

		// Generate 3AC
		cout << "Generating 3AC" << endl;
		//system("gnome-open ast.png");
	}

	// Generate ASM
	string command;
	string dest;
	string src1;
	string src2;
	string dummy;
	registerTable regTbl;
	FILE* outASM = fopen("../outputFiles/ASM.txt", "w");  



	ifstream in3ac;
	in3ac.open("../outputFiles/3AC.txt");

	// Initialize ASM


		in3ac >> dummy;
	while(in3ac.good()) {
		if (dummy == "(") {
			in3ac >> command >> dest >> src1 >> src2 >> dummy;
			outputASM(command, dest, src1, src2, outASM, regTbl);
		}
		// Else if commented C code
		else if( dummy == "//") {
			getline(in3ac, dummy);
			fprintf(outASM, "# %s\n", dummy.c_str());

		}
		// Otherwise must be label
		else{
			fprintf(outASM, "%s:\n", dummy.c_str());
		}

		in3ac >> dummy;
	}


	// Finish ASM
		
		// Ending program

		fprintf(outASM, "%s", "li $v0 10\nsyscall\n");

	return 0; 
} 

/* Function Implementations */


// Output ASM
void outputASM(std::string command, std::string dest, std::string src1, 
					std::string src2, FILE* asmFile, registerTable& table){
	// variables
	string mipsCommand = "";
	bool opOneValid = true;
	bool opTwoValid = true;
	bool destValid = true;
	bool newReg = false;  
	bool conditional = false;
	bool foundArray = false; 
	bool output = true;
	string origSrc1 = ""; 
	string origSrc2 = "";
	string origDest = ""; 

	//table.print(); 
	//cin >> temp;

	// get mips command
	if (command == "ADD") {
		mipsCommand = "add";
	}
	else if (command == "ASSIGN") {
		mipsCommand = "move";
		opTwoValid = false; 
	}
	else if (command == "BR"){
		mipsCommand = "b";
		opOneValid = false;
		opTwoValid = false;
		destValid = false;
	}
	else if (command == "MULT"){
		mipsCommand = "mul";
	}
	else if (command == "SUB" ){
		mipsCommand = "sub";
	}
	else if (command == "DIV"){
		mipsCommand = "div";
	}
	else if (command == "BREQ"){
		mipsCommand = "beq";
	}
	else if (command == "BRNE"){
		mipsCommand = "bne";
	}
	else if (command == "EQ"){
		mipsCommand = "beq";
		conditional = true;
	}
	else if (command == "LT" ){
		mipsCommand = "blt";
		conditional = true; 
	}
	else if (command == "GT" ){
		mipsCommand = "bgt";
		conditional = true; 
	}
	else if (command == "LE") {
		mipsCommand = "ble";
		conditional = true; 
	}
	else if (command == "GE") {
		mipsCommand = "bge";
		conditional = true; 
	}
	else if (command == "ADDO") {
		mipsCommand = "add";
		foundArray = true; 

	}

	/*
	else if (command == "") {
		mipsCommand = "";
	} */

	// if src1 is not a constant
	if (opOneValid && (parseString(src1) != "Label") ) {
		origSrc1 = src1; 
		// if it is a variable
		if( (parseString(src1) == "LOCV") || (parseString(src1) == "GLV")){
			// check for location of variable from variable table

			// if it's not in memory
				
				
				// get new register for it
				string offset = getOffset(src1);
				string newReg1 = table.getReg(src1, newReg);

				// move value into register
				if( newReg ){
					//cout << "Variable at offset: " << offset << endl;
					src1 = offset + "($sp)";
					if (!foundArray) {
						fprintf(asmFile, "\t\t %8s %8s %8s\n", "lw", newReg1.c_str(), src1.c_str());
					}
				}
				src1 = newReg1;
				

				// update variable table
				
			
		}

		// if it is a temp int
		else if(isdigit(src1[0]) == 0) {
			// get src1 reg
			src1 = table.getReg(src1, newReg);
		}
		else{
			if( mipsCommand == "move"){
				mipsCommand = "li";
			}
			else{
				string newReg1 = table.getReg(src1, newReg);
				if( newReg ){
					fprintf(asmFile, "\t\t %8s %8s %8s\n", "li", newReg1.c_str(), src1.c_str());
				}
				src1 = newReg1;
			}
		}
	}
	else {
		src1 = "";
	}
		
	// if src2 is not a constant
	if (opTwoValid && (parseString(src2) != "Label") ) {
		origSrc2 = src2;
		// if it is a variable
		if( (parseString(src2) == "LOCV") || (parseString(src2) == "GLV")){
				// get new register for it
				string offset = getOffset(src2);
				string newReg1 = table.getReg(src2, newReg);

				// move value into register
				if( newReg ){
					//cout << "Variable at offset: " << offset << endl;
					src1 = offset + "($sp)";
					fprintf(asmFile, "\t\t %8s %8s %8s\n", "lw", newReg1.c_str(), src2.c_str());
				}
				src2 = newReg1;
				

				// update variable table
				
		}

		// if it is a temp int
		else if (isdigit(src2[0]) == 0) {
			// get src2 reg
			src2 = table.getReg(src2, newReg);
		}
		else{
			if( mipsCommand == "move"){
				mipsCommand = "li";
			}
		}
	}
	else if ((parseString(src2) != "Label")) {
		src2 = ""; 
	}

	// get reg for dest
	if( parseString(dest) != "Label") {
		origDest = dest;
		// if it is a variable
		if( (parseString(dest) == "LOCV") || (parseString(dest) == "GLV")){
							
				// get new register for it
				string offset = getOffset(dest);
				string newReg1 = table.getReg(dest, newReg);

				// move value into register
				if( newReg )
				{
					//cout << "Variable at offset: " << offset << endl;
					dest = offset + "($sp)";
					fprintf(asmFile, "\t\t %8s %8s %8s\n", "lw", newReg1.c_str(), dest.c_str());
				}
				dest = newReg1;

				// if move
				if( mipsCommand == "move"){
					// if src 1 is not a variable
					if( !(parseString(origSrc1) == "LOCV") && !(parseString(origSrc1) == "GLV")){

						fprintf(asmFile, "\t\t %8s %8s %8s\n", "lw", dest.c_str(), ("("+src1+")").c_str() );
						output = false;
					}
				}
		}
		else
		{
			string tempReg = table.getReg(dest+"_t", newReg);
			dest = table.getReg(dest, newReg);

			if (mipsCommand == "li") {
				fprintf(asmFile, "\t\t %8s %8s %8s\n", "li", tempReg.c_str(), src1.c_str());
				fprintf(asmFile, "\t\t %8s %8s %8s\n", "sw", tempReg.c_str(), ("("+dest+")").c_str() );
				output = false;
			}
			if(mipsCommand =="move"){
				// if src 1 is not a variable
					string tempReg = table.getReg(dest+"_t", newReg);
					if( !(parseString(origSrc1) == "LOCV") && !(parseString(origSrc1) == "GLV")){

						// call lw instead
						fprintf(asmFile, "\t\t %8s %8s %8s\n", "lw", tempReg.c_str(), ("("+src1+")").c_str() );
						fprintf(asmFile, "\t\t %8s %8s %8s\n", "sw", tempReg.c_str(), ("("+dest+")").c_str() );
						output = false;
					}
					else{
						fprintf(asmFile, "\t\t %8s %8s %8s\n", "sw", src1.c_str(), ("("+dest+")").c_str() );
						output = false;
					}

			}
		}
	}

	
	if (foundArray) {
		output = false;
		string arrTempReg1 = table.getReg(origSrc1 + "_a", newReg);
		string arrTempReg2 = table.getReg(origDest, newReg);
		fprintf(asmFile, "\t\t %8s %8s %8s %8s \n", "addu", arrTempReg1.c_str(), "$sp", getOffset(origSrc1).c_str());
		fprintf(asmFile, "\t\t %8s %8s %8s %8s \n", "addu", arrTempReg2.c_str(), arrTempReg1.c_str(), 
															src2.c_str());
	}
	else if(conditional){
		output = false;
		string tempLabel1 = getASMLabel();
		string tempLabel2 = getASMLabel(); 
		fprintf(asmFile, "\t\t %8s %8s %8s %8s \n", mipsCommand.c_str(), src1.c_str(), src2.c_str(), tempLabel1.c_str());
		fprintf(asmFile, "\t\t %8s %8s %8s \n", "li", dest.c_str(), "0");
		fprintf(asmFile, "\t\t %8s %8s \n", "b", tempLabel2.c_str());
		fprintf(asmFile, "%s:\n", tempLabel1.c_str());
		fprintf(asmFile, "\t\t %8s %8s %8s \n", "li", dest.c_str(), "1");
		fprintf(asmFile, "%s:\n", tempLabel2.c_str());
	}
	if (output) {
		fprintf(asmFile, "\t\t %8s %8s %8s %8s \n", mipsCommand.c_str(), dest.c_str(), src1.c_str(), src2.c_str() );
	}
}

// Output 3AC
void output3AC(std::string type, std::string dest, std::string src1, std::string src2){
	fprintf(out3ac, "\t\t( %8s %8s %8s %8s )\n", type.c_str(), dest.c_str(), src1.c_str(), src2.c_str() );
}

// Output source code
void outputSource(std::string source){
	fprintf(out3ac, "\t// %s\n", source.c_str());
}

// Output label
void outputLabel(std::string label){
	fprintf(out3ac, "%s\n", label.c_str());
}

// String parsing function
string parseString(string str) {
	return str.substr(0, str.find("_")); 
}

string getOffset(string str) {
	return str.substr(str.find("_") + 1, std::string::npos); 
}

string getASMLabel() {
	return "Label_T" + to_string(asmLabelCount++);
}