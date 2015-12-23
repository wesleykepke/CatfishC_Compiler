/*
File: cLexer.l
Created: September 27, 2015
Last Modified: October 28, 2015
Class: CS 460 (Compiler Construction)

This is the input file to Flex that will be used in the front end of our
compiler. 

The lexer is responsible for two main tasks:
1. Scan for tokens and pass these tokens to the parser for syntax analysis.
2. Place as much information into the symbol table as possible. Some of tihis
responsibility is left to the parser. 

Tokens have been declared by Bison and are included in the file 
"cParser.tab.h."
*/

/* lexer definitions */
%{
	/* includes */
	#include <iostream>
	#include <string>
	#include <climits>
	#include <stdlib.h>
	#include <cstdlib>
	#include <fstream>
	#include <algorithm>
	#include "Escape_Sequences_Colors.h"
	#include "../parser/cParser.tab.h"
	#include "../classes/symbolTable.h"


	#define MAX_ID_LEN 64
	#define MAX_STR_LEN 256

	/* externs */
	extern bool LFLAG; 
	extern bool YFLAG;
	extern std::ofstream outL; 

	extern std::ofstream outY; 
	extern void yyerror(const char* errorMsg);


	/* variables */
	node* nodeTemp = NULL; 
	bool inInsertMode = true; // false => "lookup mode"
	int colPosition = 0;
	int tabCount = 0; 
	symbolTable table;
	std::string currentSourceCodeLine = ""; 
	extern std::vector<std::string> sourceCode;
	std::vector<int> typeSpecifiers;   
	bool endline = false;
	bool tab = false;
	bool space = false;
	int numStar = 0;
	bool linePrinted = false;

	/* functions */
	int isValidType(std::vector<int> type);
%}

/* token definitions */
blankspace	[ ]
tab	[\t]
newline	[\n]
digit	[0-9]
number	{digit}+
decimal	{digit}+"."{digit}+
character [a-zA-Z]+
identifier [a-zA-Z][a-zA-Z0-9]*

/* tell flex to read only one input file - THIS COULD CHANGE */
%option noyywrap

/* rules and actions */
%% 
 endline = false;
 space = false;
 /*
 if( (LFLAG || YFLAG) && !linePrinted){
		
		if(LFLAG){
			outL << std::endl << "=================================================================" << std::endl;
			outL << "Line #" << yylineno << ": " << std::endl;
			outL << sourceCode[yylineno-1] << std::endl;
		}
		if(YFLAG){
			outY << std::endl <<"=================================================================" << std::endl;
			outY << "Line #" << yylineno << ": " << std::endl;
			outY << sourceCode[yylineno-1] << std::endl;
		}
		linePrinted = true;
 }*/

"auto"			{
					if(LFLAG){
						outL << "< AUTO >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return AUTO; 
				}
"break"			{
					if(LFLAG){
						outL << "< BREAK >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return BREAK; 
				}
"case"			{
					if(LFLAG){
						outL << " < CASE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return CASE; 
				}
"char"			{
					if(LFLAG){
						outL << "< CHAR >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(CHAR_T); 
					return CHAR; 
				}
"const"			{
					if(LFLAG){
						outL << "< CONST >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return CONST; 
				}
"continue"		{
					if(LFLAG){
						outL << "< CONTINUE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return CONTINUE; 
				}
"default"		{
					if(LFLAG){
						outL << "< DEFAULT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DEFAULT; 
				}
"do"			{
					if(LFLAG){
						outL << "< DO >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DO; 
				}
"double"		{
					if(LFLAG){
						outL << "< DOUBLE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(DOUBLE_T);
					return DOUBLE; 
				}	
"else"			{
					if(LFLAG){
						outL << "< ELSE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return ELSE; 
				}
"enum"			{
					if(LFLAG){
						outL << "< ENUM >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return ENUM; 
				}
"extern"		{
					if(LFLAG){
						outL << "< EXTERN >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return EXTERN; 
				}
"float"			{
					if(LFLAG){
						outL << "< FLOAT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(FLOAT_T);
					return FLOAT; 
				}
"for"			{
					if(LFLAG){
						outL << "< FOR >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return FOR; 
				}
"goto"			{
					if(LFLAG){
						outL << "< GOTO >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return GOTO; 
				}
"if"			{
					if(LFLAG){
						outL << "< IF >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return IF;  
				}
"int"			{
					if(LFLAG){
						outL << "< INT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(INT_T);
					return INT; 	
				}
"long"			{
					if(LFLAG){
						outL << "< LONG >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(LONG_T);
					return LONG; 
				}
"register"		{
					if(LFLAG){
						outL << "< REGISTER >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return REGISTER; 
				}
"return"		{
					if(LFLAG){
						outL << "< RETURN >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return RETURN; 
				}
"short"			{
					if(LFLAG){
						outL << "< SHORT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(SHORT_T);
					return SHORT; 
				}
"signed"		{
					if(LFLAG){
						outL << "< SIGNED >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return SIGNED; 
				}
"sizeof"		{
					if(LFLAG){
						outL << "< SIZEOF >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return SIZEOF; 
				}	
"static"		{
					if(LFLAG){
						outL << "< STATIC >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return STATIC; 
				}
"struct"		{
					if(LFLAG){
						outL << "< STRUCT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return STRUCT; 
				}
"switch"		{
					if(LFLAG){
						outL << "< SWITCH >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return SWITCH; 
				}
"typedef"		{
					if(LFLAG){
						outL << "< TYPEDEF >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return TYPEDEF; 
				}
"union"			{
					if(LFLAG){
						outL << "< UNION >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return UNION; 
				}
"unsigned"		{
					if(LFLAG){
						outL << "< UNSIGNED >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return UNSIGNED; 
				}
"void"			{
					if(LFLAG){
						outL << "< VOID >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					typeSpecifiers.push_back(VOID_T);
					return VOID; 
				}
"volatile"		{
					if(LFLAG){
						outL << "< VOLATILE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return VOLATILE; 
				}
"while"			{
					if(LFLAG){
						outL << "< WHILE >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return WHILE; 
				}
{identifier}	{ 
					if(LFLAG){
						outL << "< IDENTIFIER >";
					}

					if(yyleng > MAX_ID_LEN){
						std::cout << COLOR_MAGENTA_NORMAL << "WARNING:" << COLOR_NORMAL << " Identifier ";
						std::cout << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << yytext << COLOR_NORMAL;
						std::cout << " exceeds maximum name length" << std::endl;
					}

					std::string newEntry(yytext);
					currentSourceCodeLine += newEntry;
					symbolTableEntry* searchResult = NULL;
					int level;

					if(typeSpecifiers.size()==0){
						inInsertMode = false;
					}

					if (inInsertMode) {
						searchResult = table.searchTopOfStack(newEntry);
						if (searchResult != NULL) {
							char lineNum[15];
							sprintf(lineNum, "%d", yylineno);
							std::cout << COLOR_NORMAL;
							std::cout << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Redeclaration of Variable " << COLOR_BOLD << COLOR_RED_NORMAL << newEntry << COLOR_NORMAL << " declared here: \n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine " << (std::string)lineNum << ": " << COLOR_NORMAL << COLOR_WHITE_NORMAL << sourceCode[yylineno - 1] << COLOR_NORMAL << "\n";
							sprintf(lineNum, "%d", searchResult->getLineNumber());
							std::cout << COLOR_NORMAL;
							std::cout << "Previously declared here: \n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine " << (std::string)lineNum << ": " << COLOR_NORMAL << COLOR_WHITE_NORMAL << sourceCode[searchResult->getLineNumber() - 1] << COLOR_NORMAL << "\n";
							yyerror("");
						}

						if( (searchResult = table.searchForSymbol(newEntry, level)) != NULL) {
							char lineNum[15];
							sprintf(lineNum, "%d", yylineno);
							std::cout << COLOR_NORMAL;
							std::cout << COLOR_MAGENTA_NORMAL << "WARNING:" << COLOR_NORMAL << " Variable " << COLOR_BOLD << COLOR_RED_NORMAL <<  newEntry << COLOR_NORMAL << " declared here: \n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine " << (std::string)lineNum << ": " << COLOR_NORMAL << COLOR_WHITE_NORMAL << sourceCode[yylineno - 1] << COLOR_NORMAL << "\n";
							sprintf(lineNum, "%d", searchResult->getLineNumber());
							std::cout << COLOR_NORMAL;
							std::cout << "Shadows variable previously declared here: \n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine " << (std::string)lineNum << ": " << COLOR_NORMAL << COLOR_WHITE_NORMAL << sourceCode[searchResult->getLineNumber() - 1] << COLOR_NORMAL << "\n";
							searchResult->setNumPtrs(numStar);
							numStar = 0;
							if(!searchResult->setIdentifierType(typeSpecifiers) && (typeSpecifiers.size() != 0)){
								char lineNum[15];
								sprintf(lineNum, "%d", yylineno);
								std::cout << COLOR_NORMAL;
								std::cout << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Invalid data type used here:\n";
								std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
								std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1] << "\n";
								std::cout << COLOR_NORMAL;
								yyerror("");
							}
							searchResult = table.insertNewSymbol(newEntry, yylineno);
							yylval.n = new node();
							yylval.n->val._ste = searchResult;
							yylval.n->valType = STE_T;
							typeSpecifiers.clear();						
							return IDENTIFIER;
						}

						else{
							searchResult = table.insertNewSymbol(newEntry, yylineno);
							searchResult->setNumPtrs(numStar);
							numStar = 0;

							if(!searchResult->setIdentifierType(typeSpecifiers) && (typeSpecifiers.size() != 0)){
								char lineNum[15];
								sprintf(lineNum, "%d", yylineno);
								std::cout << COLOR_NORMAL;
								std::cout << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Invalid data type used here:\n";
								std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
								std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1] << COLOR_NORMAL << "\n";
								yyerror("");
							} 
							colPosition += strlen(yytext);
							yylval.n = new node();
							yylval.n->val._ste = searchResult;
							yylval.n->valType = STE_T;
							typeSpecifiers.clear();			
							return IDENTIFIER;
						}
					}
					else{
						searchResult = table.searchForSymbol(newEntry, level);
						if(searchResult == NULL){
							char lineNum[15];
							sprintf(lineNum, "%d", yylineno);
							std::cout << COLOR_NORMAL;
							std::cout << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << newEntry << COLOR_NORMAL << " was not declared in this scope." << "\n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
							std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1] << COLOR_NORMAL << "\n";
							yyerror("");
						}
						else{
							yylval.n = new node();
							yylval.n->val._ste = searchResult;
							yylval.n->valType = STE_T;
							return IDENTIFIER;
						}
					}
				}
{number}		{
					if(LFLAG){
						outL << "< INTEGER_CONSTANT >";
					}
					std::string strTemp(yytext);
					std::string MAX_NUM = "18446744073709551615";

					if( strTemp.length() > MAX_NUM.length() ){
						char lineNum[15];
						sprintf(lineNum, "%d", yylineno);
						std::cout << COLOR_NORMAL;
						std::cout << COLOR_CYAN_NORMAL << "ERROR: ";
						std::cout << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << strTemp << COLOR_NORMAL << " exceeds maximum number value.\n";
						std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
						std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1] << COLOR_NORMAL << "\n";
						yyerror("");	
					}
					else if(strTemp.length() == MAX_NUM.length()){
						if( strTemp > MAX_NUM ){
						char lineNum[15];
						sprintf(lineNum, "%d", yylineno);
						std::cout << COLOR_NORMAL;
						std::cout << COLOR_CYAN_NORMAL << "ERROR: ";
						std::cout << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << strTemp << COLOR_NORMAL << " exceeds maximum number value.\n";
						std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
						std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1] << COLOR_NORMAL << "\n";
						yyerror("");							}
					}
					
   					currentSourceCodeLine += strTemp;
   					nodeTemp = new node;
   					nodeTemp->valType = LONG_LONG_T;
   					nodeTemp->val._num = atoll(yytext);
					yylval.n = nodeTemp;
					nodeTemp = NULL;  
					return INTEGER_CONSTANT; 						
				}
{decimal}		{
					if(LFLAG){
						outL << "< FLOATING_CONSTANT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					nodeTemp = new node;
   					nodeTemp->valType = LONG_DOUBLE_T;
   					nodeTemp->val._dec = strtold(yytext, NULL);
					yylval.n = nodeTemp;
					nodeTemp = NULL;  
					return FLOATING_CONSTANT; 		
				}
"'"[a-zA-Z]"'"	{
					if(LFLAG){
						outL << "< CHARACTER_CONSTANT >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
   					nodeTemp = new node;
   					nodeTemp->valType = CHAR_T;
   					nodeTemp->val._char = yytext[1];
					yylval.n = nodeTemp;
					nodeTemp = NULL;  
					return CHARACTER_CONSTANT; 		
				}
				/* don't know what this is 
{
						if(LFLAG){
						outL << "< ENUMERATION_CONSTANT >";
					}
					return ENUMERATION_CONSTANT; 		
}
			*/
\"[^\"]*\"	{
					
					if(LFLAG){
						outL << "< STRING_LITERAL > ";
					}
					if( yyleng > MAX_STR_LEN ){
						std::cout << COLOR_MAGENTA_NORMAL << "WARNING:" << COLOR_NORMAL << " String exceeds maximum string length" << std::endl;
						yyerror("");
					}

   					nodeTemp = new node;
   					nodeTemp->valType = STR_T;
   					strncpy(nodeTemp->val._str, yytext, yyleng);
					nodeTemp->val._str[yyleng]='\0';
					yylval.n = nodeTemp;
					nodeTemp = NULL;  
					return STRING_LITERAL;
				}
"->"			{
					if(LFLAG){
						outL << "< -> > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return PTR_OP;
				}
"++"			{
					if(LFLAG){
						outL << "< ++ > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return INC_OP;
				}
"--"			{
					if(LFLAG){
						outL << "< -- > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DEC_OP;
				}
"<<"			{
					if(LFLAG){
						outL << "< << > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LEFT_OP;
				}
">>"			{
					if(LFLAG){
						outL << "< -> > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return RIGHT_OP;
				}
"<="			{
					if(LFLAG){
						outL << "< <= > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LE_OP;
				}
">="			{
					if(LFLAG){
						outL << "< >= > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return GE_OP;
				}
"=="			{
					if(LFLAG){
						outL << "< == > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return EQ_OP;
				}
"!="			{
					if(LFLAG){
						outL << "< != >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return NE_OP;
				}
"&&"			{
					if(LFLAG){
						outL << "< && >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return AND_OP;
				}
"||"			{
					if(LFLAG){
						outL << "< || >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return OR_OP;
				}
"*="			{
					if(LFLAG){
						outL << "< *= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return MUL_ASSIGN;
				}
"/="			{
					if(LFLAG){
						outL << "< /= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DIV_ASSIGN;
				}
"%="			{
					if(LFLAG){
						outL << "< %= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return MOD_ASSIGN;
				}
"+="			{
					if(LFLAG){
						outL << "< += >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return ADD_ASSIGN;
				}
"-="			{
					if(LFLAG){
						outL << "< -= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return SUB_ASSIGN;
				}
"<<="			{
					if(LFLAG){
						outL << "< <<= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LEFT_ASSIGN;
				}
">>="			{
					if(LFLAG){
						outL << "< >>= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return RIGHT_ASSIGN;
				}
"&="			{
					if(LFLAG){
						outL << "< &= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return AND_ASSIGN;
				}
"^="			{
					if(LFLAG){
						outL << "< ^= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return XOR_ASSIGN;
				}
"|="			{
					if(LFLAG){
						outL << "< |= >";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return XOR_ASSIGN;
				}
"+"				{
					if(LFLAG){
						outL << "< + > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return PLUS;
				}
"-"				{
					if(LFLAG){
						outL << "< - > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return MINUS;
				}
"*"				{
					if(LFLAG){
						outL << "< * > ";
					}
					numStar++;
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return MULT;
				}
"/"				{
					if(LFLAG){
						outL << "< / > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DIV;
				}
"%"				{
					if(LFLAG){
						outL << "< % > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return MOD;
				}
";"				{
					if(LFLAG){
						outL << "< ; > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return SEMI;
				}
":"				{
					if(LFLAG){
						outL << "< : > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return COLON;
				}
","				{
					if(LFLAG){
						outL << "< , > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return COMMA;
				}
"&"				{
					if(LFLAG){
						outL << "< & > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return AMP;
				}
"="				{
					if(LFLAG){
						outL << "< = > ";
					}					
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return ASSIGN;
				}
"~"				{
					if(LFLAG){
						outL << "< ~ > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return TILDE;
				}
"|"				{
					if(LFLAG){
						outL << "< | > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return PIPE;
				}
"^"				{
					if(LFLAG){
						outL << "< ^ > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return CARROT;
				}
"."				{
					if(LFLAG){
						outL << "< . > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return DOT;
				}
"!"				{
					if(LFLAG){
						outL << "< ! > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return BANG;
				}
"?"				{
					if(LFLAG){
						outL << "< ? > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return QUESTION;
				}
"("				{
					if(LFLAG){
						outL << "< ( > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LPAREN;
				}
"["				{
					if(LFLAG){
						outL << "< [ > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LBRACK;
				}
"{"				{
					if(LFLAG){
						outL << "< { > ";
					}
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LCURL;
				}
")"				{
					if(LFLAG){
						outL << "< ) > ";
					} 
					if(isValidType(typeSpecifiers) == -1 && (typeSpecifiers.size() != 0)){
							char lineNum[15];
							sprintf(lineNum, "%d", yylineno);
							std::cout << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Invalid data type used here:\n";
							std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
							std::cout << COLOR_WHITE_NORMAL << sourceCode[yylineno-1];
					   		std::cout << COLOR_NORMAL;
							yyerror("");

					}

					typeSpecifiers.clear();
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;

					return RPAREN;
				}
"]"				{
					if(LFLAG){
						outL << "< ] > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return RBRACK;
				}
"}"				{
					if(LFLAG){
						outL << "< } > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return RCURL;
				}
"<"				{
					if(LFLAG){
						outL << "< < > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return LTHAN;
				}
">"				{
					if(LFLAG){
						outL << "< > > ";
					} 
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
					return GTHAN;
				}
{blankspace}	{
					space = true;
					colPosition += yyleng;
					std::string strTemp(yytext);
   					currentSourceCodeLine += strTemp;
				}
{tab}			{

					colPosition ++;
					currentSourceCodeLine += ' ';
				}
{newline}		{

					//sourceCode.push_back(currentSourceCodeLine);
					currentSourceCodeLine = "";  
					yylineno++; 
					colPosition = 0;
					endline = true;
					if(LFLAG){
						outL << std::endl << "=================================================================" << std::endl;
						outL << "Line #" << yylineno << ": " << std::endl;
						outL << sourceCode[yylineno-1] << std::endl;
					}
					if(YFLAG){
						outY << std::endl <<"=================================================================" << std::endl;
						outY << "Line #" << yylineno << ": " << std::endl;
						outY << sourceCode[yylineno-1] << std::endl;
					}
				}
"!!S"			{outY << "READ !!S" << std::endl;
					table.writeToScreen(); 
				}

"/*"[^"*/"]*"*/"	{	
					std::string comment(yytext);
					yylineno += std::count(comment.begin(), comment.end(), '\n');

				}
"//"(.)*		{
				}
.				{
						std::string token(yytext);
						char temp[256];
						char lineNum[15];
						strcpy(temp, sourceCode[yylineno-1].c_str());
						sprintf(lineNum, "%d", yylineno);
						int iter = 0;
						std::cout << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << "Unexpected character " << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << token << COLOR_NORMAL;
						std::cout << " here:" << (std::string)"\n";
						while(temp[iter] != '\0')
						{
							if( iter == 0 ){
								std::cout << COLOR_GREEN_NORMAL << "\tLine #" << (std::string)lineNum << (std::string)": " << COLOR_NORMAL;
							}
							if(temp[iter] == yytext[0])
							{
								std::cout << COLOR_NORMAL << COLOR_BOLD_RED_NORMAL << token << COLOR_NORMAL;
							}
							else{
								std::cout << COLOR_WHITE_NORMAL << temp[iter];
							}
							iter++;
						}
						std::cout << COLOR_NORMAL;
						yyerror("");
				}		
%%

/* user code */

/*
Function: isValidType(std::vector<int> type)

Description: This function will check to see if a supplied vector of 
tokens matches any of the allowable datatypes in C. If the supplied vector
contains an allowable data type, the function will return the enumerated
integer of the associated data type. If the incoming vector contains tokens
in an invalid order, the function will return -1. 

Parameters:
std::vector<int> type: This is the incoming vector of tokens that will be
used to determine if the compiler has encountered a valid datatype. 
*/
int isValidType(std::vector<int> type){
	// populate the map for each symbol table entry
	// ex: "long long, long int, etc."
	std::map<std::vector<int>, int> validTypes; 
	std::map<std::vector<int> , int>::iterator mapItr;
	std::vector<int> validType;

	// char
	validType.push_back(CHAR_T);
	validTypes.insert(pair(validType, CHAR_T));
	validType.clear();

	// double
	validType.push_back(DOUBLE_T);
	validTypes.insert(pair(validType, DOUBLE_T));
	validType.clear();

	// float
	validType.push_back(FLOAT_T);
	validTypes.insert(pair(validType, FLOAT_T));
	validType.clear();

	// int 
	validType.push_back(INT_T);
	validTypes.insert(pair(validType, INT_T));
	validType.clear();

	// long
	validType.push_back(LONG_T);
	validTypes.insert(pair(validType, LONG_T));
	validType.clear();

	// long int
	validType.push_back(LONG_T);
	validType.push_back(INT_T);
	validTypes.insert(pair(validType, LONG_T));
	validType.clear();

	// long long
	validType.push_back(LONG_T);
	validType.push_back(LONG_T);
	validTypes.insert(pair(validType, LONG_LONG_T));
	validType.clear();	

	// long long int
	validType.push_back(LONG_T);
	validType.push_back(LONG_T);
	validType.push_back(INT_T);
	validTypes.insert(pair(validType, LONG_LONG_T));
	validType.clear();

	// long double
	validType.push_back(LONG_T);
	validType.push_back(DOUBLE_T);
	validTypes.insert(pair(validType, LONG_DOUBLE_T));
	validType.clear();

	// short
	validType.push_back(SHORT_T);
	validTypes.insert(pair(validType, SHORT_T));
	validType.clear();	

	// short int
	validType.push_back(SHORT_T);
	validType.push_back(INT_T);
	validTypes.insert(pair(validType, SHORT_T));
	validType.clear();	

	// void
	validType.push_back(VOID_T);
	validTypes.insert(pair(validType, VOID_T));
	validType.clear();	

	// search for the vector in the predefined map of data types
	mapItr = validTypes.find(type);
	if(mapItr != validTypes.end()){
		// if found, return the enumerated integer used to identify the 
		// data type
		return mapItr->second;
	}

	// if unable to locate, indicate to the caller. 
	return -1;
}
