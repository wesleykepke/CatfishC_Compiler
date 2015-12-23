/*
Name: Renee Iinuma, Kyle Lee, and Wesley Kepke. 
File: symbolTable.cpp
Created: September 28, 2015
Last Modified: October 27, 2015
Class: CS 460 (Compiler Construction)

This is the input file to Bison that will be used in the front end of our
compiler. 

The parser is responsible for two main tasks:
1. Checking for syntax analysis as the tokens are passed from the lexer to the
parser.
2. Performing the appropriate semantic action for each production of the ANSI C
grammar. 

This file is used to created cParser.tab.h, the header file containing all of 
the token declarations that will be used in the lexer.  
*/

/* start of declarations and definitions */
%{
	// # includes 
	#include <climits>
	#include <fstream>
	#include <iostream>
	#include <string>
	#include "../classes/symbolTableEntry.h"
	#include "../classes/symbolTable.h"
	#include "../lexer/Escape_Sequences_Colors.h"
	#include "../parser/nodes/nodeClassList.h"

	// extern variables and forward declarations 
	extern int yylineno;
	extern int colPosition;  
	extern bool YFLAG; 
	extern std::ofstream outY;
	extern std::ofstream outG;
	extern std::ofstream outA;
	extern bool inInsertMode;
	extern symbolTable table;
	std::string intTC();
	std::string labelTC();
	int yylex(void);
	void yyerror(const char* errorMsg);
	void registerNode(std::ofstream &out, astNode* ptr);
	void outputNode(std::ofstream &out, astNode* ptr);
	void outputTerminal(std::ofstream &out, std::string name, int id);

	// global variables 
	std::vector< std::vector<int> > funcParams;
	std::vector<symbolTableEntry*> funcCallingParams; 
	int unaryOperatorChosen = -1;
	symbolTableEntry* currentFunc;
	int intTicket = 0;
	int labelCount = 0; 

	// root of the ast
	astNode* astRoot = NULL; 
	int unique = 0;
%}
/* end of declarations and definitions */

/*

*/
%code requires {
	typedef union {
		char _char;
		long long _num;
		long double _dec; // decimal
		char _str[256];
		class symbolTableEntry* _ste;   
	} vals;

	typedef struct {
		int valType; 
		vals val;
		class astNode* astPtr;
	} node;
}

/*
The datatype of YYSTYPE will be a union that contains a single element,
which is a pointer to a node object. 
*/
%union {
	node* n;
}

/* inform bison that there will be 1 shift-reduce conflict */
%expect 1

/* catfishC tokens */
%token <n> IDENTIFIER
%token <n> INTEGER_CONSTANT 
%token <n> FLOATING_CONSTANT 
%token <n> ENUMERATION_CONSTANT 
%token <n> CHARACTER_CONSTANT 
%token <n> STRING_LITERAL 
%token <n> SIZEOF
%token <n> PTR_OP 
%token <n> INC_OP DEC_OP 
%token <n> LEFT_OP RIGHT_OP 
%token <n> LE_OP GE_OP EQ_OP NE_OP
%token <n> AND_OP OR_OP 
%token <n> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN 
%token <n> LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN 
%token <n> TYPEDEF_NAME
%token <n> PLUS MINUS MULT DIV MOD
%token <n> SEMI COLON COMMA AMP
%token <n> ASSIGN TILDE PIPE CARROT DOT
%token <n> BANG QUESTION
%token <n> LPAREN LBRACK LCURL
%token <n> RPAREN RBRACK RCURL
%token <n> LTHAN GTHAN
%token <n> TYPEDEF EXTERN STATIC AUTO REGISTER
%token <n> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token <n> STRUCT UNION ENUM ELIPSIS RANGE
%token <n> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

/* catfishC starting left hand side */
%start start_unit
%type <n> translation_unit
%type <n> external_declaration
%type <n> assignment_expression
%type <n> postfix_expression
%type <n> cast_expression
%type <n> unary_expression
%type <n> multiplicative_expression
%type <n> additive_expression
%type <n> parameter_declaration
%type <n> declarator
%type <n> direct_declarator
%type <n> constant_expression
%type <n> initializer
%type <n> init_declarator
%type <n> identifier
%type <n> primary_expression
%type <n> argument_expression_list
%type <n> string 
%type <n> constant
%type <n> unary_operator
%type <n> relational_expression
%type <n> shift_expression
%type <n> equality_expression
%type <n> assignment_operator
%type <n> conditional_expression
%type <n> expression
%type <n> iteration_statement
%type <n> statement
%type <n> selection_statement
%type <n> statement_list
%type <n> declaration_list
%type <n> compound_statement
%type <n> initializer_list
%type <n> type_qualifier_list
%type <n> type_qualifier
%type <n> pointer
%type <n> identifier_list
%type <n> parameter_type_list
%type <n> storage_class_specifier
%type <n> type_specifier
%type <n> declaration_specifiers
%type <n> declaration
%type <n> init_declarator_list
%type <n> function_definition
%type <n> expression_statement

/* start of ANSI C grammar and actions */
%%

start_unit
	:	translation_unit	
		{
			table.popLevelOff();
			outG << "start_unit -> translation_unit;" << std::endl;
			astRoot = $1->astPtr;
			astRoot->gen3AC(); 
		}
	;

translation_unit
	: external_declaration
		{
			// create ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new translationUnit_Node($1->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "translation_unit : external_declaration;" << std::endl;
				outG << "translation_unit -> external_declaration;" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| translation_unit external_declaration
		{
			// create ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new translationUnit_Node($1->astPtr, $2->astPtr);

			// output data 
			if(YFLAG){
				outY << "translation_unit : translation_unit external_declaration;" << std::endl;
				outG << "translation_unit -> {translation_unit external_declaration};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	;

external_declaration
	: function_definition
		{
			// output data 
			if(YFLAG){
				outY << "external_declaration : function_definition;" << std::endl;
				outG << "external_declaration -> function_definition;" << std::endl;
			}
		}
	| declaration
		{
			// output data 
			if(YFLAG){
				outY << "external_declaration : declaration;" << std::endl;
				outG << "external_declaration -> declaration;" << std::endl;
			}
		}
	;

/*
Have stuff for going into the symbol table here. 
*/
function_definition
	: declarator compound_statement
		{
			// create ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new funcDef_Node(NULL, $1->astPtr, NULL, $2->astPtr);

			// output data 
			if(YFLAG){
				outY << "function_definition : declarator compound_statement;" << std::endl;
				outG << "function_definition -> {declarator compound_statement};" << std::endl;
			}
			

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| declarator declaration_list compound_statement
		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new funcDef_Node(NULL, $1->astPtr, $2->astPtr, $3->astPtr);

			// output data 
			if(YFLAG){
				outY << "function_definition : declarator declaration_list compound_statement;" << std::endl;
				outG << "function_definition -> {declarator declaration_list compound_statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| declaration_specifiers declarator compound_statement
		{
			// output data 
			if(YFLAG){
				outY << "function_definition : declaration_specifiers declarator compound_statement;" << std::endl;
				outG << "function_definition -> {declaration_specifiers declarator compound_statement};" << std::endl;
			}

			// create ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new funcDef_Node($1->astPtr, $2->astPtr, NULL, $3->astPtr);



			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| declaration_specifiers declarator declaration_list compound_statement
		{
			// output data 
			if(YFLAG){
				outY << "function_definition : declaration_specifiers declarator declaration_list compound_statement;" << std::endl;
				outG << "function_definition -> {declaration_specifiers declarator declaration_list compound_statement};" << std::endl;
			}

			// create ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new funcDef_Node($1->astPtr, $2->astPtr, $3->astPtr, $4->astPtr);



			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";
		}
	;

/*

*/
declaration
	: declaration_specifiers SEMI
		{	
			// output data
			if(YFLAG){
				outY << "declaration : declaration_specifiers SEMI;" << std::endl;
				outG << "declaration -> {declaration_specifiers SEMI};" << std::endl;
			}		
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declaration_Node($1->astPtr, NULL);

	

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
	| declaration_specifiers init_declarator_list SEMI
		{
			// output data 
			if(YFLAG){
				outY << "declaration : declaration_specifiers init_declarator_list SEMI;" << std::endl;
				outG << "declaration -> {declaration_specifiers init_declarator_list SEMI};" << std::endl;
			}

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declaration_Node($1->astPtr, $2->astPtr);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
	;

declaration_list
	: set_insert declaration set_lookup
		{
			// create ast node 
			$$ = new node(); 
			$$->val = $2->val;
			$$->valType = $2->valType;
			$$->astPtr = new declList_Node($2->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "declaration_list : declaration;" << std::endl;
				outG << "declaration_list -> declaration;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";

		}
	| declaration_list set_insert declaration set_lookup
		{
			// create new ast node 
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declList_Node($1->astPtr, $3->astPtr);

			// output data 
			if(YFLAG){
				outY << "declaration_list : declaration_list declaration;" << std::endl;
				outG << "declaration_list -> {declaration_list declaration};" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

declaration_specifiers
	: storage_class_specifier
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : storage_class_specifier;" << std::endl;
				outG << "declaration_specifiers -> storage_class_specifier;" << std::endl; 
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node(NULL, $1->val._num);
			
			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| storage_class_specifier declaration_specifiers
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : storage_class_specifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {storage_class_specifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node($2->astPtr, $1->val._num);
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| type_specifier
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_specifier;" << std::endl;
				outG << "declaration_specifiers -> type_specifier;" << std::endl;
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node(NULL, $1->val._num);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| type_specifier declaration_specifiers
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_specifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {type_specifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node($2->astPtr, $1->val._num);
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| type_qualifier 
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_qualifier;" << std::endl;
				outG << "declaration_specifiers -> type_qualifier;" << std::endl;
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node(NULL, $1->val._num);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| type_qualifier declaration_specifiers
		{
			// output data 
			if(YFLAG){
				outY << "declaration_specifiers : type_qualifier declaration_specifiers;" << std::endl;
				outG << "declaration_specifiers -> {type_qualifier declaration_specifiers};" << std::endl;
			}

			// create AST node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declSpec_Node($2->astPtr, $1->val._num);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	;

storage_class_specifier
	: AUTO
		{
			// create ast node 
			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = AUTO; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "auto");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : AUTO;" << std::endl;
				outG << "storage_class_specifier -> AUTO;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| REGISTER
		{
			// create ast node 
			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = REGISTER; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "register");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : REGISTER;" << std::endl;
				outG << "storage_class_specifier -> REGISTER;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| STATIC
		{
			// create ast node 
			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = STATIC; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "static");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : STATIC;" << std::endl;
				outG << "storage_class_specifier -> STATIC;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| EXTERN
		{
			// create ast node 
			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = EXTERN; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "extern");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : EXTERN;" << std::endl;
				outG << "storage_class_specifier -> EXTERN;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| TYPEDEF
		{
			// create ast node 
			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = TYPEDEF; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "typedef");

			// output data 
			if(YFLAG){
				outY << "storage_class_specifier : TYPEDEF;" << std::endl;
				outG << "storage_class_specifier -> TYPEDEF;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	;

type_specifier
	: VOID
		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = VOID; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "VOID");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : VOID;" << std::endl;
				outG << "type_specifier -> VOID;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| CHAR
		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = CHAR; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "CHAR");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : CHAR;" << std::endl;
				outG << "type_specifier -> CHAR;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| SHORT
		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = SHORT; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "SHORT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : SHORT;" << std::endl;
				outG << "type_specifier -> SHORT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| INT
		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = INT; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "INT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : INT;" << std::endl;
				outG << "type_specifier -> INT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| LONG
		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = LONG; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "LONG");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : LONG;" << std::endl;
				outG << "type_specifier -> LONG;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| FLOAT
 		{
 			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = FLOAT; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "FLOAT");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : FLOAT;" << std::endl;
				outG << "type_specifier -> FLOAT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| DOUBLE
 		{
			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = DOUBLE; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "DOUBLE");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : DOUBLE;" << std::endl;
				outG << "type_specifier -> DOUBLE;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);

		}
	| SIGNED
 		{
 			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = SIGNED; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "SIGNED");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : SIGNED;" << std::endl;
				outG << "type_specifier -> SIGNED;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| UNSIGNED
 		{
 			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = UNSIGNED; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "UNSIGNED");
			
			// output data 
			if(YFLAG){
				outY << "type_specifier : UNSIGNED;" << std::endl;
				outG << "type_specifier -> UNSIGNED;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| struct_or_union_specifier
 		{
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : struct_or_union_specifier;" << std::endl;
				outG << "type_specifier -> struct_or_union_specifier;" << std::endl;
			}
		}
	| enum_specifier
 		{
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : enum_specifier;" << std::endl;
				outG << "type_specifier -> enum_specifier;" << std::endl;
			}
		}
	| TYPEDEF_NAME
 		{
 			/* not implementing */
			if(YFLAG){
				outY << "type_specifier : TYPEDEF_NAME;" << std::endl;
				outG << "type_specifier -> TYPEDEF_NAME;" << std::endl;
			}
		}
	;

type_qualifier
	: CONST
 		{
 			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = CONST; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "CONST");
			
			// output data
			if(YFLAG){
				outY << "type_qualifier : CONST;" << std::endl;
				outG << "translation_unit -> CONST;" << std::endl;
			}

			registerNode(outA, $$->astPtr);

		}
	| VOLATILE
 		{
 			// create ast node
 			$$ = new node();
			$$->valType = LONG_LONG_T;
			$$->val._num = VOLATILE; 
			$$->astPtr = new leaf_Node($$->val, $$->valType, "VOLATILE");
			
			// output data
			if(YFLAG){
				outY << "type_qualifier : VOLATILE;" << std::endl;
				outG << "translation_unit -> VOLATILE;" << std::endl;
			}

			registerNode(outA, $$->astPtr);
		}
	;

struct_or_union_specifier
	: struct_or_union identifier LCURL struct_declaration_list RCURL
 		{
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union identifier LCURL struct_declaration_list RCURL;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union identifier LCURL struct_declaration_list RCURL};" << std::endl;
			}
		}
	| struct_or_union LCURL struct_declaration_list RCURL
 		{
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union LCURL struct_declaration_list RCURL;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union LCURL struct_declaration_list RCURL};" << std::endl;
			}
		}
	| struct_or_union identifier
 		{
 			// output data
			if(YFLAG){
				outY << "struct_or_union_specifier : struct_or_union identifier;" << std::endl;
				outG << "struct_or_union_specifier -> {struct_or_union identifier};" << std::endl;
			}
		}
	;

struct_or_union
	: STRUCT
 		{
 			// output data
			if(YFLAG){
				outY << "struct_or_union : STRUCT;" << std::endl;
				outG << "struct_or_union -> STRUCT;" << std::endl;
			}
		}
	| UNION
 		{
 			// output data
			if(YFLAG){
				outY << "struct_or_union : UNION;" << std::endl;
				outG << "struct_or_union -> UNION;" << std::endl;
			}
		}
	;

struct_declaration_list
	: struct_declaration
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declaration_list : struct_declaration;" << std::endl;
				outG << "struct_declaration_list -> struct_declaration;" << std::endl;
			}
		}
	| struct_declaration_list struct_declaration
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declaration_list : struct_declaration_list struct_declaration;" << std::endl;
				outG << "struct_declaration_list -> {struct_declaration_list struct_declaration};" << std::endl;
			}
		}
	;

init_declarator_list
	: init_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "init_declarator_list : init_declarator;" << std::endl;
			outG << "init_declarator_list -> init_declarator;" << std::endl;
			}
		}
	| init_declarator_list COMMA init_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "init_declarator_list : init_declarator_list COMMA init_declarator;" << std::endl;
				outG << "init_declarator_list -> {init_declarator_list COMMA init_declarator};" << std::endl;
			}
		}
	;

init_declarator
	: declarator
 		{
			// output data
			if(YFLAG){
				outY << "init_declarator : declarator;" << std::endl;
				outG << "init_declarator -> declarator;" << std::endl; 
			}

 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new initDecl_Node($1->astPtr, NULL); 

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n"; 
		}
	| declarator ASSIGN set_lookup initializer set_insert
 		{ 
 			// create ast node
			$$ = new node();
			
			//std::cout << "$1 datatype: " << $1->val._ste->getIdentifierType_String() << std::endl; 
 			//std::cout << "$4 datatype: " << $4->valType << std::endl; 

			// perform checking for assignment mismatching 
 			bool warningFlag = false;
 			std::string message = ""; 
 			bool fatalAssignment = $1->val._ste->setIdentifierValue((*$4), warningFlag, message); 			
 			if (warningFlag) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "WARNING: " << COLOR_NORMAL << message << std::endl; 
 			}

 			else if (fatalAssignment) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR:" << COLOR_NORMAL << " Invalid assignment." << std::endl;
 				yyerror("");
 			}


 			// assign ast node attributes
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new initDecl_Node($1->astPtr, $4->astPtr);
			//$$->astPtr->gen3AC(); 
			 
			// output data
 			if(YFLAG){
				outY << "init_declarator : declarator ASSIGN initializer;" << std::endl;
				outG << "init_declarator -> {declarator ASSIGN initializer};" << std::endl; 
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "ASSIGN", unique);
 			unique++;
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";

 		}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMI
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declaration : specifier_qualifier_list struct_declarator_list SEMI;" << std::endl;
				outG << "struct_declaration -> {specifier_qualifier_list struct_declarator_list SEMI};" << std::endl;
			}
		}
	;

specifier_qualifier_list
	: type_specifier
 		{
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_specifier;" << std::endl;
				outG << "specifier_qualifier_list -> type_specifier;" << std::endl;
			}
		}
	| type_specifier specifier_qualifier_list
 		{
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_specifier specifier_qualifier_list;" << std::endl;
				outG << "specifier_qualifier_list -> {type_specifier specifier_qualifier_list};" << std::endl;
			}
		}
	| type_qualifier
 		{
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_qualifier;" << std::endl;
				outG << "specifier_qualifier_list -> type_qualifier;" << std::endl;
			}
		}
	| type_qualifier specifier_qualifier_list
 		{
 			// output data
			if(YFLAG){
				outY << "specifier_qualifier_list : type_qualifier specifier_qualifier_list;" << std::endl;
				outG << "specifier_qualifier_list -> {type_qualifier specifier_qualifier_list};" << std::endl;
			}
		}
	;

struct_declarator_list
	: struct_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declarator_list : struct_declarator;" << std::endl;
				outG << "struct_declarator_list -> struct_declarator;" << std::endl;
			}
		}
	| struct_declarator_list COMMA struct_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declarator_list : struct_declarator_list COMMA struct_declarator;" << std::endl;
				outG << "struct_declarator_list -> {struct_declarator_list COMMA struct_declarator};" << std::endl;
			}
		}
	;

struct_declarator
	: declarator
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declarator : declarator;" << std::endl;
				outG << "struct_declarator -> declarator;" << std::endl;
			}
		}
	| COLON constant_expression
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declarator : COLON constant_expression;" << std::endl;
				outG << "struct_declarator -> COLON constant_expression;" << std::endl;
			}
		}
	| declarator COLON constant_expression
 		{
 			// output data
			if(YFLAG){
				outY << "struct_declarator : declarator COLON constant_expression;" << std::endl;
				outG << "struct_declarator -> {declarator COLON constant_expression};" << std::endl;
			}
		}
	;

enum_specifier
	: ENUM LCURL enumerator_list RCURL
 		{
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM LCURL enumerator_list RCURL;" << std::endl;
				outG << "enum_specifier -> {ENUM LCURL enumerator_list RCURL};" << std::endl;
			}
		}
	| ENUM identifier LCURL enumerator_list RCURL
 		{
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM identifier LCURL enumerator_list RCURL;" << std::endl;
				outG << "enum_specifier -> {ENUM identifier LCURL enumerator_list RCURL};" << std::endl;
			}
		}
	| ENUM identifier
 		{
 			// output data
			if(YFLAG){
				outY << "enum_specifier : ENUM identifier;" << std::endl;
				outG << "enum_specifier -> {ENUM identifier};" << std::endl;
			}
		}
	;

enumerator_list
	: enumerator
 		{
 			// output data
			if(YFLAG){
				outY << "enumerator_list : enumerator;" << std::endl;
				outG << "enumerator_list -> enumerator;" << std::endl;
			}
		}
	| enumerator_list COMMA enumerator
 		{
 			// output data
			if(YFLAG){
				outY << "enumerator_list : enumerator_list COMMA enumerator;" << std::endl;
				outG << "enumerator_list -> {enumerator_list COMMA enumerator};" << std::endl;
			}
		}
	;

enumerator
	: identifier
 		{
 			// output data
			if(YFLAG){
				outY << "enumerator : identifier;" << std::endl;
				outG << "enumerator -> identifier;" << std::endl;
			}
		}
	| identifier ASSIGN constant_expression
 		{
 			// output data
			if(YFLAG){
				outY << "enumerator : identifier ASSIGN constant_expression;" << std::endl;
				outG << "enumerator -> {identifier ASSIGN constant_expression};" << std::endl;
			}
		}
	;

declarator
	: direct_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "declarator : direct_declarator;" << std::endl;
				outG << "declarator -> direct_declarator;" << std::endl;
			}			

			// create ast node
			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
			$$->astPtr = new declarator_Node($1->astPtr);
			//$1->astPtr->gen3AC();

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| pointer direct_declarator
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new declarator_Node($2->astPtr);

			// output data 
			if(YFLAG){
				outY << "declarator : pointer direct_declarator;" << std::endl;
				outG << "declarator -> {pointer direct_declarator};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	;

direct_declarator
	: identifier
 		{
			// output data 
 			if(YFLAG){
				outY << "direct_declarator : identifier;" << std::endl;
				outG << "direct_declarator -> identifier;" << std::endl;
			}

			// create ast node
			/*
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType; */
			$$ = $1;
/*
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";*/
		}
	| LPAREN declarator RPAREN
 		{
			// output data 
			if(YFLAG){
				outY << "direct_declarator : LPAREN declarator RPAREN;" << std::endl;
				outG << "direct_declarator -> {LPAREN declarator RPAREN};" << std::endl;
			}

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($2->astPtr, NULL);
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
		}
	| direct_declarator LBRACK RBRACK 
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LBRACK RBRACK;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LBRACK RBRACK};" << std::endl;
			}	

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($1->astPtr, NULL);

			// register data for graphviz 
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
	| direct_declarator LBRACK constant_expression RBRACK
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LBRACK constant_expression RBRACK;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LBRACK constant_expression RBRACK};" << std::endl;
			}

 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($1->astPtr, $3->astPtr);

			// assign array attributes
 			$1->val._ste->setArray();
 			$1->val._ste->addArrayDimension($3->val._num); 
 			std::vector<int> arrayDims = $1->val._ste->getArrayDimensions();
 			if(arrayDims.size()==1) {
 				table.incrementOffset(arrayDims[0]-1);
 			}
 			else if(arrayDims.size() == 2) {
 				table.decrementOffset(arrayDims[0]-1);
 				table.incrementOffset(arrayDims[0]*arrayDims[1]-1);
			}
			else if(arrayDims.size() == 3) {
 				table.decrementOffset(arrayDims[0]*arrayDims[1]-1);
 				table.incrementOffset(arrayDims[0]*arrayDims[1]*arrayDims[2]-1);
			}
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
	| direct_declarator LPAREN RPAREN
 		{
			// output data 
			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN RPAREN};" << std::endl;
			}	

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($1->astPtr, NULL);		
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
	| direct_declarator LPAREN parameter_type_list RPAREN
 		{
 			// output data 
 			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN parameter_type_list RPAREN};" << std::endl;
			}

 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($1->astPtr, $3->astPtr);

			// assign function attributes 
			$1->val._ste->setFunction(); 
			for (unsigned int i = 0; i < funcParams.size(); i++) {
				$1->val._ste->addParameter(funcParams[i]);
			}
			funcParams.clear();
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
	| direct_declarator LPAREN set_lookup identifier_list RPAREN 
 		{
			// output data 
 			if(YFLAG){
				outY << "direct_declarator : direct_declarator LPAREN identifier_list RPAREN;" << std::endl;
				outG << "direct_declarator -> {direct_declarator LPAREN identifier_list RPAREN};" << std::endl;
			}	

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new directDecl_Node($1->astPtr, $4->astPtr);		
	 		
			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;

		}
	;

pointer
	: MULT
 		{		
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new pointer_Node($1->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT;" << std::endl;
				outG << "pointer -> MULT;" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;

		}
	| MULT type_qualifier_list
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new pointer_Node($2->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT type_qualifier_list;" << std::endl;
				outG << "pointer -> {MULT type_qualifier_list};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| MULT pointer
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new pointer_Node($2->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT pointer;" << std::endl;
				outG << "pointer -> {MULT pointer};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| MULT type_qualifier_list pointer
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new pointer_Node($2->astPtr, $3->astPtr);

			// output data 
			if(YFLAG){
				outY << "pointer : MULT type_qualifier_list pointer;" << std::endl;
				outG << "pointer -> {MULT type_qualifier_list pointer};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "STAR", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

type_qualifier_list
	: type_qualifier
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new typeQualifierList_Node($1->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "type_qualifier_list : type_qualifier;" << std::endl;
				outG << "type_qualifier_list -> type_qualifier;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| type_qualifier_list type_qualifier
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new typeQualifierList_Node($1->astPtr, $2->astPtr);

 			// output data
			if(YFLAG){
				outY << "type_qualifier_list : type_qualifier_list type_qualifier;" << std::endl;
				outG << "type_qualifier_list -> {type_qualifier_list type_qualifier};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}	
	;

parameter_type_list
	: parameter_list
 		{
 			// output data
			if(YFLAG){
				outY << "parameter_type_list : parameter_list;" << std::endl;
				outG << "parameter_type_list -> parameter_list;" << std::endl;
			}
		}	
	| parameter_list COMMA ELIPSIS
 		{
 			// output data
			if(YFLAG){
				outY << "parameter_type_list : parameter_list COMMA ELIPSIS;" << std::endl;
				outG << "parameter_type_list -> {parameter_list COMMA ELIPSIS};" << std::endl;
			}
		}	
	;

parameter_list
	: parameter_declaration
 		{
 			// output data
 			if(YFLAG){
				outY << "parameter_list : parameter_declaration;" << std::endl;
				outG << "parameter_list -> parameter_declaration;" << std::endl;
			}
		}	
	| parameter_list COMMA parameter_declaration
 		{
 			// output data
			if(YFLAG){
				outY << "parameter_list : parameter_list COMMA parameter_declaration;" << std::endl;
				outG << "parameter_list -> {parameter_list COMMA parameter_declaration};" << std::endl;
			}
		}	
	;

parameter_declaration
	: declaration_specifiers declarator
 		{	
 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers declarator;" << std::endl;
				outG << "parameter_declaration -> {declaration_specifiers declarator};" << std::endl;
			}

 			// store integer data types of parameters 
 			std::vector<int> formalParamType;
 			formalParamType = $2->val._ste->getIdentifierType_Vector();
			funcParams.push_back(formalParamType);

			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new paramDecl_Node($1->astPtr, $2->astPtr);



			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| declaration_specifiers
 		{
 			 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers;" << std::endl;
				outG << "parameter_declaration -> declaration_specifiers;" << std::endl;
			}
 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new paramDecl_Node($1->astPtr, NULL);



			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| declaration_specifiers abstract_declarator
 		{
 			// output data
			if(YFLAG){
				outY << "parameter_declaration : declaration_specifiers abstract_declarator;" << std::endl;
				outG << "parameter_declaration -> {declaration_specifiers abstract_declarator};" << std::endl;
			}
		}
	;

identifier_list
	: identifier
 		{
 			// output data
			if(YFLAG){
				outY << "identifier_list : identifier;" << std::endl;
				outG << "identifier_list -> identifier;" << std::endl;
			}
		}
	| identifier_list COMMA identifier
 		{
 			// output data
			if(YFLAG){
				outY << "identifier_list : identifier_list COMMA identifier;" << std::endl;
				outG << "identifier_list -> {identifier_list COMMA identifier};" << std::endl;
			}
		}
	;

initializer
	: assignment_expression
 		{
 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new initializer_Node($1->astPtr);

			// output data 
			if(YFLAG){
				outY << "initializer : assignment_expression;" << std::endl;
				outG << "initializer -> assignment_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| LCURL initializer_list RCURL
 		{
 			// create ast node
			$$ = new node();
			$$->val = $2->val;
			$$->valType = $2->valType;
			$$->astPtr = new initializer_Node($2->astPtr);

			// output data 
			if(YFLAG){
				outY << "initializer : LCURL initializer_list RCURL;" << std::endl;
				outG << "initializer -> {LCURL initializer_list RCURL};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
	| LCURL initializer_list COMMA RCURL
 		{
			// create ast node
			$$ = new node();
			$$->val = $2->val;
			$$->valType = $2->valType;
			$$->astPtr = new initializer_Node($2->astPtr);

 			// output data 
			if(YFLAG){
				outY << "initializer : LCURL initializer_list COMMA RCURL;" << std::endl;
				outG << "initializer -> {LCURL initializer_list COMMA RCURL};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "COMMA", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}
	;

initializer_list
	: initializer
 		{
 			// output data 
			if(YFLAG){
				outY << "initializer_list : initializer;" << std::endl;
				outG << "initializer_list -> initializer;" << std::endl;
			}
		}
	| initializer_list COMMA initializer
 		{
 			// output data 
			if(YFLAG){
				outY << "initializer_list : initializer_list COMMA initializer;" << std::endl;
				outG << "initializer_list -> {initializer_list COMMA initializer};" << std::endl;
			}
		}
	;

type_name
	: specifier_qualifier_list
 		{
 			// output data 
			if(YFLAG){
				outY << "type_name : specifier_qualifier_list;" << std::endl;
				outG << "type_name -> specifier_qualifier_list;" << std::endl;
			}
		}
	| specifier_qualifier_list abstract_declarator
 		{
 			// output data 
			if(YFLAG){
				outY << "type_name : specifier_qualifier_list abstract_declarator;" << std::endl;
				outG << "type_name -> {specifier_qualifier_list abstract_declarator};" << std::endl;
			}
		}
	;

abstract_declarator
	: pointer
 		{
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : pointer;" << std::endl;
				outG << "abstract_declarator -> pointer;" << std::endl;
			}
		}
	| direct_abstract_declarator
 		{
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : direct_abstract_declarator;" << std::endl;
				outG << "abstract_declarator -> direct_abstract_declarator;" << std::endl;
			}
		}
	| pointer direct_abstract_declarator
 		{
 			// output data 
			if(YFLAG){
				outY << "abstract_declarator : pointer direct_abstract_declarator;" << std::endl;
				outG << "abstract_declarator -> {pointer direct_abstract_declarator};" << std::endl;
			}
		}
	;

direct_abstract_declarator
	: LPAREN abstract_declarator RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN abstract_declarator RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN abstract_declarator RPAREN};" << std::endl;
			}
		}
	;
	| LBRACK RBRACK
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LBRACK RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {LBRACK RBRACK};" << std::endl;
			}
		}
	| LBRACK constant_expression RBRACK
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LBRACK constant_expression RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {LBRACK constant_expression RBRACK};" << std::endl;
			}
		}
	| direct_abstract_declarator LBRACK RBRACK
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LBRACK RBRACK;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LBRACK RBRACK};" << std::endl;
			}
		}
	| direct_abstract_declarator LBRACK constant_expression RBRACK
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LBRACK constant_expression;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LBRACK constant_expression};" << std::endl;
			}
		}
	| LPAREN RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN RPAREN};" << std::endl;
			}
		}
	| LPAREN parameter_type_list RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {LPAREN parameter_type_list RPAREN};" << std::endl;
			}
		}
	| direct_abstract_declarator LPAREN RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LPAREN RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LPAREN RPAREN};" << std::endl;
			}
		}
	| direct_abstract_declarator LPAREN parameter_type_list RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "direct_abstract_declarator : direct_abstract_declarator LPAREN parameter_type_list RPAREN;" << std::endl;
				outG << "direct_abstract_declarator -> {direct_abstract_declarator LPAREN parameter_type_list RPAREN};" << std::endl;
			}
		}
	;

statement
	:  labeled_statement
 		{
 			// output data 
			if(YFLAG){
				outY << "statement : labeled_statement;" << std::endl;
				outG << "statement -> labeled_statement;" << std::endl;
			}
		}
	| compound_statement
 		{
 			// output data 
			if(YFLAG){
				outY << "statement : compound_statement;" << std::endl;
				outG << "statement -> compound_statement;" << std::endl;
			}
		}
	| expression_statement
 		{
 			// output data 
			if(YFLAG){
				outY << "statement : expression_statement;" << std::endl;
				outG << "statement -> expression_statement;" << std::endl;
			}
		}
	| selection_statement
 		{
 			// output data 
			if(YFLAG){
				outY << "statement : selection_statement;" << std::endl;
				outG << "statement -> selection_statement;" << std::endl;
			}
		}
	| iteration_statement
 		{
 
 			// output data 
			if(YFLAG){
				outY << "statement : iteration_statement;" << std::endl;
				outG << "statement -> iteration_statement;" << std::endl;
			}
		}
	| jump_statement
 		{
 			// output data 
			if(YFLAG){
				outY << "statement : jump_statement;" << std::endl;
				outG << "statement -> jump_statement;" << std::endl;
			}
		}
	;

labeled_statement
	: identifier COLON statement
 		{
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : identifier COLON statement;" << std::endl;
				outG << "labeled_statement -> {identifier COLON statement};" << std::endl;
			}
		}
	| CASE constant_expression COLON statement
 		{
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : CASE constant_expression COLON statement;" << std::endl;
				outG << "labeled_statement -> {CASE constant_expression COLON statement};" << std::endl;
			}
		}
	| DEFAULT COLON statement
 		{
 			// output data 
			if(YFLAG){
				outY << "labeled_statement : DEFAULT COLON statement;" << std::endl;
				outG << "labeled_statement -> {DEFAULT COLON statement};" << std::endl;
			}
		}
	;

expression_statement
	: SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "expression_statement : SEMI;" << std::endl;
				outG << "expression_statement -> SEMI;" << std::endl;
			}
		}
	| expression SEMI
 		{
 			// create ast node and assign attributes	
			$$ = $1; 

			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;

 			// output data 
			if(YFLAG){
				outY << "expression_statement : expression SEMI;" << std::endl;
				outG << "expression_statement -> {expression SEMI};" << std::endl;
			}
		}
	;

compound_statement
	: LCURL RCURL 
 		{
			// output data 
			if(YFLAG){
				outY << "compound_statement : LCURL RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL RCURL};" << std::endl;
			}
 			
 			// create ast node and assign attributes
			$$ = new node();
			$$->astPtr = new compoundStat_Node(NULL, NULL);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}						
	| LCURL open_curl set_lookup statement_list RCURL close_curl
 		{
			// output data 
 			if(YFLAG){
				outY << "compound_statement : LCURL statement_list RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL statement_list RCURL};" << std::endl;
			}

 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new compoundStat_Node(NULL, $4->astPtr);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}					
	| LCURL set_insert_push declaration_list RCURL set_lookup_pop	
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new compoundStat_Node($3->astPtr, NULL);

			// output data
 			if(YFLAG){
				outY << "compound_statement : LCURL declaration_list RCURL;" << std::endl;
				outG << "compound_statement -> {LCURL declaration_list RCURL};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
		}				
	| LCURL set_insert_push declaration_list set_lookup statement_list RCURL set_lookup_pop 
		{
			// create ast node and assign attributes
			$$ = new node();
			$$->astPtr = new compoundStat_Node($3->astPtr, $5->astPtr);

			// output data 
			if(YFLAG){
				outG << "compound_statement -> {LCURL declaration_list statement_list RCURL};" << std::endl;
				outY << "compound_statement : LCURL declaration_list statement_list RCURL;" << std::endl;
		    }     
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LCURL", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RCURL", unique);
 			unique++;
	    } 
	;

set_insert_push
	:	{
		table.pushLevelOn();
		inInsertMode = true;
		outY << "set_insert_push : inInsertMode = true" << std::endl;
		}
	;

set_lookup_pop
	:	{
		table.popLevelOff(); 
		inInsertMode = false;  
		outY << "set_lookup_pop : inInsertMode = false" << std::endl;
		}
	;

set_lookup
	:	{
		outY << "set_lookup : inInsertMode = false" << std::endl; 
		inInsertMode = false; 
		}
	;

set_insert
	:	{
		outY << "set_insert : inInsertMode = true" << std::endl; 
		inInsertMode = true; 
		}
	;

open_curl
	:  {
		table.pushLevelOn();
	   }
	;

close_curl
	:	{
		table.popLevelOff();  
		}
	;

statement_list
	: statement
 		{
			// output data 
			if(YFLAG){
				outY << "statement_list : statement;" << std::endl;
				outG << "statement_list -> statement;" << std::endl;
			}	

 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new statList_Node($1->astPtr, NULL);
			
			// register data for graphviz			
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";	
		}
	| statement_list statement
 		{
			// output data 
			if(YFLAG){
				outY << "statement_list : statement_list statement;" << std::endl;
				outG << "statement_list -> {statement_list statement};" << std::endl;
			}

			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new statList_Node($1->astPtr, $2->astPtr);

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";	
		}
	;

selection_statement
	: IF LPAREN expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new selectionStat_Node($3->astPtr, $5->astPtr, NULL);

			// output pasta
			if(YFLAG){
				outY << "selection_statement : IF LPAREN expression RPAREN statement;" << std::endl;
				outG << "selection_statement -> {IF LPAREN expression RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "IF", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
		}
	| IF LPAREN expression RPAREN statement ELSE statement
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new selectionStat_Node($3->astPtr, $5->astPtr, $7->astPtr);

			// output data 
			if(YFLAG){
				outY << "selection_statement : IF LPAREN expression RPAREN statement ELSE statement;" << std::endl;
				outG << "selection_statement -> {IF LPAREN expression RPAREN statement ELSE statement};" << std::endl;
			}
		
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "IF", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "ELSE", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $7->astPtr);
 			outA << ";\n";	
		}
	| SWITCH LPAREN expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new selectionStat_Node($3->astPtr, $5->astPtr, NULL);

			// output data 
			if(YFLAG){
				outY << "selection_statement : SWITCH LPAREN expression RPAREN statement;" << std::endl;
				outG << "selection_statement -> {SWITCH LPAREN expression RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SWITCH", unique);
 			unique++;

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
		}
	;

iteration_statement
	: WHILE LPAREN expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->astPtr = new iterStat_Node(NULL, $3->astPtr, NULL, $5->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : WHILE LPAREN expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {WHILE LPAREN expression RPAREN statement};" << std::endl; 
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "WHILE", unique);
 			unique++;

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
		}
	| DO statement WHILE LPAREN expression RPAREN SEMI
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->val = $2->val;
			$$->valType = $2->valType;
			$$->astPtr = new iterStat_Node(NULL, $5->astPtr, NULL, $2->astPtr, true);

			// output data
			if(YFLAG){
				outY << "iteration_statement : DO statement WHILE LPAREN expression RPAREN SEMI;" << std::endl;
				outG << "iteration_statement -> {DO statement WHILE LPAREN expression RPAREN SEMI};" << std::endl; 
			}

			// register data for graphviz and assign attributes
			registerNode(outA, $$->astPtr);
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DO", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr); 
 						outA << " -> ";
 			outputTerminal(outA, "WHILE", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr); 
 						outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
		}
	| FOR LPAREN SEMI SEMI RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $6->val;
			$$->valType = $6->valType;
			$$->astPtr = new iterStat_Node(NULL, NULL, NULL, $6->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI SEMI RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $6->astPtr);
 			outA << ";\n";	
		}
	| FOR LPAREN SEMI SEMI expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $5->val;
			$$->valType = $5->valType;
			$$->astPtr = new iterStat_Node(NULL, NULL, $5->astPtr, $7->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI SEMI expression RPAREN statement};" << std::endl;
			}
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";	
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $7->astPtr);
 			outA << ";\n";		
		}
	| FOR LPAREN SEMI expression SEMI RPAREN statement
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->val = $4->val;
			$$->valType = $4->valType;
			$$->astPtr = new iterStat_Node(NULL, $4->astPtr, NULL, $7->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI expression SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI expression SEMI RPAREN statement};" << std::endl;
			}			
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $7->astPtr);
 			outA << ";\n";
		}
	| FOR LPAREN SEMI expression SEMI expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $4->val;
			$$->valType = $4->valType;
			$$->astPtr = new iterStat_Node(NULL, $4->astPtr, $6->astPtr, $8->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN SEMI expression SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN SEMI expression SEMI expression RPAREN statement};" << std::endl;
			
			}		
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $6->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $8->astPtr);
 			outA << ";\n";
		}
	| FOR LPAREN expression SEMI SEMI RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new iterStat_Node($3->astPtr, NULL, NULL, $7->astPtr, false);

 			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI SEMI RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $7->astPtr);
 			outA << ";\n";
		}
	| FOR LPAREN expression SEMI SEMI expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new iterStat_Node($3->astPtr, NULL, $6->astPtr, $8->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI SEMI expression RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $6->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $8->astPtr);
 			outA << ";\n";
		}
	| FOR LPAREN expression SEMI expression SEMI RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new iterStat_Node($3->astPtr, $5->astPtr, NULL, $8->astPtr, false);

			// output data S
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI expression SEMI RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI expression SEMI RPAREN statement};" << std::endl;
			}	
			
			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $8->astPtr);
 			outA << ";\n";
		}
	| FOR LPAREN expression SEMI expression SEMI expression RPAREN statement
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $3->val;
			$$->valType = $3->valType;
			$$->astPtr = new iterStat_Node($3->astPtr, $5->astPtr, $7->astPtr, $9->astPtr, false);

			// output data 
			if(YFLAG){
				outY << "iteration_statement : FOR LPAREN expression SEMI expression SEMI expression RPAREN statement;" << std::endl;
				outG << "iteration_statement -> {FOR LPAREN expression SEMI expression SEMI expression RPAREN statement};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "FOR", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $5->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "SEMI", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $7->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $9->astPtr);
 			outA << ";\n";
		}
	;

jump_statement
	: GOTO identifier SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "jump_statement : GOTO identifier SEMI;" << std::endl;
				outG << "jump_statement -> {GOTO identifier SEMI};" << std::endl;
			}
		}
	| CONTINUE SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "jump_statement : CONTINUE SEMI;" << std::endl;
				outG << "jump_statement -> {CONTINUE SEMI};" << std::endl;
			}
		}
	| BREAK SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "jump_statement : BREAK SEMI;" << std::endl;
				outG << "jump_statement -> {BREAK SEMI};" << std::endl;
			}
		}
	| RETURN SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "jump_statement : RETURN SEMI;" << std::endl;
				outG << "jump_statement -> {RETURN SEMI};" << std::endl;
			}
		}
	| RETURN expression SEMI
 		{
 			// output data 
			if(YFLAG){
				outY << "jump_statement : RETURN expression SEMI;" << std::endl;
				outG << "jump_statement -> {RETURN expression SEMI};" << std::endl;
			}
		}
	;

expression
	: assignment_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new expr_Node($1->astPtr, NULL);	

			// output data 
			if(YFLAG){
				outY << "expression : assignment_expression;" << std::endl;
				outG << "expression -> assignment_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| expression COMMA assignment_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new expr_Node($1->astPtr, $3->astPtr);

			// output data 
			if(YFLAG){
				outY << "expression : expression COMMA assignment_expression;" << std::endl;
				outG << "expression -> {expression COMMA assignment_expression};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "COMMA", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

assignment_expression
	: conditional_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new assignmentExpr_Node($1->astPtr, NULL, -1);

			// output data 
			if(YFLAG){
				outY << "assignment_expression : conditional_expression;" << std::endl;
				outG << "assignment_expression -> conditional_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| unary_expression assignment_operator assignment_expression
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
			$$->astPtr = new assignmentExpr_Node($1->astPtr, $3->astPtr, $2->val._num);

			// output data 
			if(YFLAG){
				outY << "assignment_expression : unary_expression assignment_operator assignment_expression;" << std::endl;
				outG << "assignment_expression -> {unary_expression assignment_operator assignment_expression};" << std::endl;
			}

			// register data for graphviz			
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

assignment_operator
	: ASSIGN
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = ASSIGN;
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "ASSIGN"); 
 			registerNode(outA, $$->astPtr);
 			// output data  
			if(YFLAG){
				outY << "assignment_operator : ASSIGN;" << std::endl;
				outG << "assignment_operator -> ASSIGN;" << std::endl;
			}
		}
	| MUL_ASSIGN
 		{
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = MUL_ASSIGN; 
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "MUL_ASSIGN"); 
 			registerNode(outA, $$->astPtr);
			if(YFLAG){
				outY << "assignment_operator : MUL_ASSIGN;" << std::endl;
			outG << "assignment_operator -> MUL_ASSIGN;" << std::endl;
			}
		}
	| DIV_ASSIGN
 		{
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = DIV_ASSIGN; 
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "DIV_ASSIGN"); 
 			registerNode(outA, $$->astPtr);
			if(YFLAG){
				outY << "assignment_operator : DIV_ASSIGN;" << std::endl;
			outG << "assignment_operator -> DIV_ASSIGN;" << std::endl;
			}
		}
	| MOD_ASSIGN
 		{
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = MOD_ASSIGN; 
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "MOD_ASSIGN"); 
 			registerNode(outA, $$->astPtr);
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : MOD_ASSIGN;" << std::endl;
				outG << "assignment_operator -> MOD_ASSIGN;" << std::endl;
			}
		}
	| ADD_ASSIGN
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = ADD_ASSIGN;
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "ADD_ASSIGN"); 
 			registerNode(outA, $$->astPtr);

 			// output data 
			if(YFLAG){
				outY << "assignment_operator : ADD_ASSIGN;" << std::endl;
				outG << "assignment_operator -> ADD_ASSIGN;" << std::endl;
			}
		}
	| SUB_ASSIGN
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->valType = LONG_LONG_T;
 			$$->val._num = SUB_ASSIGN;
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "SUB_ASSIGN"); 
 			registerNode(outA, $$->astPtr);

 			// output data 
			if(YFLAG){
				outY << "assignment_operator : SUB_ASSIGN;" << std::endl;
				outG << "assignment_operator -> SUB_ASSIGN;" << std::endl;
			}
		}
	| LEFT_ASSIGN
 		{
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : LEFT_ASSIGN;" << std::endl;
				outG << "assignment_operator -> LEFT_ASSIGN;" << std::endl;
			}
		}
	| RIGHT_ASSIGN
 		{
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : RIGHT_ASSIGN;" << std::endl;
				outG << "assignment_operator -> RIGHT_ASSIGN;" << std::endl;
			}
		}
	| AND_ASSIGN
 		{
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : AND_ASSIGN;" << std::endl;
				outG << "assignment_operator -> AND_ASSIGN;" << std::endl;
			}
		}
	| XOR_ASSIGN
 		{
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : XOR_ASSIGN;" << std::endl;
				outG << "assignment_operator -> XOR_ASSIGN;" << std::endl;
			}
		}
	| OR_ASSIGN
 		{
 			// output data 
			if(YFLAG){
				outY << "assignment_operator : OR_ASSIGN;" << std::endl;
				outG << "assignment_operator -> OR_ASSIGN;" << std::endl;
			}
		}
	;

conditional_expression
	: logical_or_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "conditional_expression : logical_or_expression;" << std::endl;
				outG << "conditional_expression -> logical_or_expression;" << std::endl;
			}
		}
	| logical_or_expression QUESTION expression COLON conditional_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "conditional_expression : logical_or_expression QUESTION expression COLON conditional_expression;" << std::endl;
				outG << "conditional_expression -> {logical_or_expression QUESTION expression COLON conditional_expression;" << std::endl;
			}
		}
	;

constant_expression
	: conditional_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "constant_expression : conditional_expression;" << std::endl;
				outG << "constant_expression -> conditional_expression;" << std::endl;
			}
		}
	;

logical_or_expression
	: logical_and_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "logical_or_expression : logical_and_expression;" << std::endl;
				outG << "logical_or_expression -> logical_and_expression;" << std::endl;
			}
		}
	| logical_or_expression OR_OP logical_and_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "logical_or_expression : logical_or_expression OR_OP logical_and_expression;" << std::endl;
				outG << "logical_or_expression -> {logical_or_expression OR_OP logical_and_expression};" << std::endl;
			}
		}
	;

logical_and_expression
	: inclusive_or_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "logical_and_expression : inclusive_or_expression;" << std::endl;
				outG << "logical_and_expression -> inclusive_or_expression;" << std::endl;
			}
		}
	| logical_and_expression AND_OP inclusive_or_expression
 		{
			if(YFLAG){
				// output data 
				outY << "logical_and_expression : logical_and_expression AND_OP inclusive_or_expression;" << std::endl;
				outG << "logical_and_expression -> {logical_and_expression AND_OP inclusive_or_expression};" << std::endl;
			}

		}
	;

inclusive_or_expression
	: exclusive_or_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "inclusive_or_expression : exclusive_or_expression;" << std::endl;
				outG << "inclusive_or_expression -> exclusive_or_expression;" << std::endl;
			}
		}
	| inclusive_or_expression PIPE exclusive_or_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "inclusive_or_expression : inclusive_or_expression PIPE exclusive_or_expression;" << std::endl;
				outG << "inclusive_or_expression -> {inclusive_or_expression PIPE exclusive_or_expression};" << std::endl;
			}
		}
	;

exclusive_or_expression
	: and_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "exclusive_or_expression : and_expression;" << std::endl;
				outG << "exclusive_or_expression -> and_expression;" << std::endl;
			}
		}
	| exclusive_or_expression CARROT and_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "exclusive_or_expression : exclusive_or_expression CARROT and_expression;" << std::endl;
				outG << "exclusive_or_expression -> {exclusive_or_expression CARROT and_expression};" << std::endl;
			}
		}
	;

and_expression
	: equality_expression
 		{
			// output data 
			if(YFLAG){
				outY << "and_expression : equality_expression;" << std::endl;
				outG << "and_expression -> equality_expression;" << std::endl;
			}
		}
	| and_expression AMP equality_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "and_expression : and_expression AMP equality_expression;" << std::endl;
				outG << "and_expression -> {and_expression AMP equality_expression};" << std::endl;
			}
		}
	;

equality_expression
	: relational_expression
 		{
 			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new equalityExpr_Node($1->astPtr, NULL, -1);

	 		// output data 
			if(YFLAG){
				outY << "equality_expression : relational_expression;" << std::endl;
	 			outG << "equality_expression -> relational_expression;" << std::endl;
			}
			
			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";

		}
	| equality_expression EQ_OP relational_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new equalityExpr_Node($1->astPtr, $3->astPtr, EQ_OP);

	 		// output data 
			if(YFLAG){
				outY << "equality_expression : equality_expression EQ_OP relational_expression;" << std::endl;
				outG << "equality_expression -> {equality_expression EQ_OP relational_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "EQ_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| equality_expression NE_OP relational_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new equalityExpr_Node($1->astPtr, $3->astPtr, NE_OP);

 			// output data 
			if(YFLAG){
				outY << "equality_expression : equality_expression NE_OP relational_expression;" << std::endl;
	 			outG << "equality_expression -> {equality_expression LTHAN relational_expression};" << std::endl;
			}

			// register data for graphviz			
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "NE_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

relational_expression
	: shift_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new relationalExpr_Node($1->astPtr, NULL, -1);

	 		// output data
			if(YFLAG){
				outY << "relational_expression : shift_expression;" << std::endl;
	 			outG << "relational_expression -> shift_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| relational_expression LTHAN shift_expression
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new relationalExpr_Node($1->astPtr, $3->astPtr, LTHAN);

	 		// output data
			if(YFLAG){
				outY << "relational_expression : relational_expression LTHAN shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression LTHAN shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LTHAN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| relational_expression GTHAN shift_expression
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new relationalExpr_Node($1->astPtr, $3->astPtr, GTHAN);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression GTHAN shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression GTHAN shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "GTHAN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| relational_expression LE_OP shift_expression
 		{
			// create ast node
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new relationalExpr_Node($1->astPtr, $3->astPtr, LE_OP);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression LE_OP shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression LE_OP shift_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LE_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| relational_expression GE_OP shift_expression
 		{
 			// create ast node and assign attributes
 			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new relationalExpr_Node($1->astPtr, $3->astPtr, GE_OP);

	 		// output data 
			if(YFLAG){
				outY << "relational_expression : relational_expression GE_OP shift_expression;" << std::endl;
	 			outG << "relational_expression -> {relational_expression GE_OP shift_expression};" << std::endl;
			}

			// create ast node
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "GE_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

shift_expression
	: additive_expression
 		{
 			// output data
			if(YFLAG){
				outY << "shift_expression : additive_expression;" << std::endl;
				outG << "shift_expression -> additive_expression;" << std::endl;
			}
		}
	| shift_expression LEFT_OP additive_expression
 		{
 			// output data
			if(YFLAG){
				outY << "shift_expression : shift_expression LEFT_OP additive_expression;" << std::endl;
				outG << "shift_expression -> {shift_expression LEFT_OP additive_expression};" << std::endl;
			}
		}
	| shift_expression RIGHT_OP additive_expression
 		{
 			// output data
			if(YFLAG){
				outY << "shift_expression : shift_expression RIGHT_OP additive_expression;" << std::endl;
				outG << "shift_expression -> {shift_expression RIGHT_OP additive_expression};" << std::endl;
			}
		}
	;

additive_expression
	: multiplicative_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->val = $1->val;
			$$->valType = $1->valType;
	 		$$->astPtr = new multExpr_Node($1->astPtr, NULL, -1);

	 		// output data 
			if(YFLAG){
				outY << "additive_expression : multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> multiplicative_expression;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| additive_expression PLUS multiplicative_expression
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
			$$->val = $1->val; 
 			$$->astPtr = new additiveExpr_Node($1->astPtr, $3->astPtr, PLUS);
 			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "additive_expression : additive_expression PLUS multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> {additive_expression PLUS cast_expression};" << std::endl;
			}
			
 			// performArithmeticOp($$, $1, $3, PLUS);

			// register data for graphviz		
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "PLUS", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| additive_expression MINUS multiplicative_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
			$$->valType = $1->valType;
			$$->val = $1->val; 
			$$->astPtr = new additiveExpr_Node($1->astPtr, $3->astPtr, MINUS);
			//$$->astPtr->gen3AC();

			// output data 
 			if(YFLAG){
				outY << "additive_expression : additive_expression MINUS multiplicative_expression;" << std::endl;
	 			outG << "additive_expression -> {additive_expression MINUS cast_expression};" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
	 		outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MINUS", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

multiplicative_expression
	: cast_expression
 		{
 			// create ast node
			$$ = new node();
			$$->val = $1->val; 
			$$->valType = $1->valType; 
	 		$$->astPtr = new multExpr_Node($1->astPtr, NULL, -1);
			//$$->astPtr->gen3AC();

 			// output data 
			if(YFLAG){
				outY << "multiplicative_expression : cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> cast_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| multiplicative_expression MULT cast_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val; 
			$$->astPtr = new multExpr_Node($1->astPtr, $3->astPtr, MULT);
			//$$->astPtr->gen3AC();

			// output data
			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression MULT cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression MULT cast_expression};" << std::endl;
			}

			/*
 			if ($1->valType != STE_T && $3->valType == STE_T) {
 				performArithmeticOp_OneSTE($$, $1, $3, MULT, false);
 			}
 			else if ($1->valType == STE_T && $3->valType != STE_T) {
 				std::cout << "left is an STE and right is not" << std::endl; 
 				performArithmeticOp_OneSTE($$, $1, $3, MULT, true);
 			}
			*/

 			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MULT", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| multiplicative_expression DIV cast_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val; 
			$$->astPtr = new multExpr_Node($1->astPtr, $3->astPtr, DIV);
			//$$->astPtr->gen3AC();

			// prevent division by 0
			switch ($3->valType) {
				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
					if ($3->val._num == 0) {
						std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL;
						std::cout << "Unable to divide by 0." << std::endl; 
 						yyerror("");
					}
				break;

				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
					if ($3->val._dec == 0.0) {
						std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL;
						std::cout << "Unable to divide by 0.0." << std::endl; 
 						yyerror("");
					}
				break;  
			}

			// output data
 			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression DIV cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression DIV cast_expression};" << std::endl;
			}

			/*
			if ($1->valType != STE_T && $3->valType == STE_T) {
 				performArithmeticOp_OneSTE($$, $1, $3, DIV, false);
 			}
 			else if ($1->valType == STE_T && $3->valType != STE_T) {
 				std::cout << "left is an STE and right is not" << std::endl; 
 				performArithmeticOp_OneSTE($$, $1, $3, DIV, true);
 			}
 			*/

 			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DIV", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	| multiplicative_expression MOD cast_expression
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val; 
			$$->astPtr = new multExpr_Node($1->astPtr, $3->astPtr, MOD);

			// output data
 			if(YFLAG){
				outY << "multiplicative_expression : multiplicative_expression MOD cast_expression;" << std::endl;
	 			outG << "multiplicative_expression -> {multiplicative_expression MOD cast_expression};" << std::endl;
			}
 			
			/*
 			performArithmeticOp($$, $1, $3, MOD);
 			*/
	 		
 			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "MOD", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
		}
	;

cast_expression
	: unary_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "cast_expression : unary_expression;" << std::endl;
				outG << "cast_expression -> unary_expression;" << std::endl;
			}
		}
	| LPAREN type_name RPAREN cast_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "cast_expression : LPAREN type_name RPAREN cast_expression;" << std::endl;
				outG << "cast_expression -> {LPAREN type_name RPAREN cast_expression};" << std::endl;
			}
		}
	;

unary_expression
	: postfix_expression
 		{
			// create ast node and assign attributes
			$$ = new node();
			$$->valType = $1->valType;
			$$->val = $1->val;
	 		$$->astPtr = new unaryExpr_Node($1->astPtr, NULL, false, false);
			//$$->astPtr->gen3AC();

	 		// output data 
			if(YFLAG){
				outY << "unary_expression : postfix_expression;" << std::endl;
	 			outG << "unary_expression -> postfix_expression;" << std::endl;
			}

			// register data for graphviz
	 		registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
		}
	| INC_OP unary_expression /* ++a, ++a[x][y], etc.. */
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $2->valType;
 			$$->val = $2->val;
			$$->astPtr = new unaryExpr_Node(NULL, $2->astPtr, true, false);
			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "unary_expression : INC_OP unary_expression;" << std::endl;
	 			outG << "unary_expression -> {INC_OP cast_expression};" << std::endl;
			}

			// register data for graphviz	 		
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "INC_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";

		}
	| DEC_OP unary_expression /* --a, --a[x][y], etc.. */ 
 		{
 			// create ast node and assign attributes
	 		$$ = new node();
 			$$->valType = $2->valType;
 			$$->val = $2->val;
 			$$->astPtr = new unaryExpr_Node(NULL, $2->astPtr, false, true);
			//$$->astPtr->gen3AC();

 			if(YFLAG){
				outY << "unary_expression : DEC_OP unary_expression;" << std::endl;
	 		outG << "unary_expression -> {DEC_OP cast_expression};" << std::endl;
			}		

 			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "DEC_OP", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";
		}
	| unary_operator cast_expression /* negative values */
 		{
 			// create ast node and assign attributes 
			$$ = new node();
			$$->valType = $1->valType;
 			$$->val = $1->val;
			$$->astPtr = new unaryExpr_Node($1->astPtr, $2->astPtr);
			//$$->astPtr->gen3AC();

			// output data 
			if(YFLAG){
				outY << "unary_expression : unary_operator cast_expression;" << std::endl;
	 			outG << "unary_expression -> {unary_operator cast_expression}" << std::endl;
			}		

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $2->astPtr);
 			outA << ";\n";

		}
	| SIZEOF unary_expression
 		{
 			// output data 
			if(YFLAG){
				outY << "unary_expression : SIZEOF unary_expression;" << std::endl;
				outG << "unary_expression -> {SIZEOF unary_expression};" << std::endl;
			}
		}
	| SIZEOF LPAREN type_name RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "unary_expression : SIZEOF LPAREN type_name RPAREN;" << std::endl;
				outG << "unary_expression -> {SIZEOF LPAREN type_name RPAREN};" << std::endl;
			}
		}
	;

unary_operator
	: AMP
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(AMP);
 			unaryOperatorChosen = AMP;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : AMP;" << std::endl;
 				outG << "unary_operator -> AMP;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, $$->astPtr);
		}
	| MULT
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(MULT);
 			unaryOperatorChosen = MULT;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : MULT;" << std::endl;
 				outG << "unary_operator -> MULT;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, $$->astPtr);
		}
	| PLUS
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(PLUS);
 			unaryOperatorChosen = PLUS;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : PLUS;" << std::endl;
 				outG << "unary_operator -> PLUS;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, $$->astPtr);
		}
	| MINUS
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(MINUS);
 			unaryOperatorChosen = MINUS;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : MINUS;" << std::endl;
 				outG << "unary_operator -> MINUS;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, $$->astPtr);
		}
	| TILDE
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(TILDE);
 			unaryOperatorChosen = TILDE;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : TILDE;" << std::endl;
 				outG << "unary_operator -> TILDE;" << std::endl;
			}

			// register data for graphviz 
 			registerNode(outA, $$->astPtr);
		}
	| BANG
 		{
 			// create ast node and assign attributes 
 			$$ = new node();
			$$->astPtr = new unaryOp_Node(BANG);
 			unaryOperatorChosen = BANG;

 			// output data 
			if(YFLAG){
				outY << "unary_operator : BANG;" << std::endl;
 				outG << "unary_operator -> BANG;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	;

postfix_expression
	: primary_expression
 		{
 			// create ast node and assign attributes
			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
			$$->astPtr = new postfixExpr_Node($1->astPtr, NULL, false, false);
			//$$->astPtr->gen3AC();

			// output data 
 			if(YFLAG){
				outY << "postfix_expression : primary_expression;" << std::endl;
 				outG << "postfix_expression -> primary_expression;" << std::endl;
			}

			// check to see if the current identifier is a function 
 			if($1->valType == STE_T && $1->val._ste->isFunction()){
 				currentFunc = $1->val._ste;
 			} 
 			
 			// register data for graphviz
 			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n"; 
 		}
	| postfix_expression set_lookup LBRACK expression RBRACK /* COME BACK TO THIS */
 		{
 			// create ast and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
			$$->astPtr = new postfixExpr_Node($1->astPtr, $4->astPtr, false, false);
			//$$->astPtr->gen3AC();

 			// output data 
 			if(YFLAG){
				outY << "postfix_expression : postfix_expression LBRACK expression RBRACK;" << std::endl;
				outG << "postfix_expression -> {postfix_expression LBRACK expression RBRACK};" << std::endl;
			}

			// register data for graphviz
 			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n"; 

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LBRACK", unique);
 			unique++;

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $4->astPtr);
 			outA << ";\n"; 

 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RBRACK", unique);
 			unique++;
		}
	| postfix_expression LPAREN RPAREN
 		{
 			// output data 
			if(YFLAG){
				outY << "postfix_expression : postfix_expression LPAREN RPAREN;" << std::endl;
				outG << "postfix_expression -> {postfix_expression LPAREN RPAREN};" << std::endl;
			}
		}
	| postfix_expression LPAREN argument_expression_list RPAREN
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
 			$$->astPtr = new postfixExpr_Node($1->astPtr, $3->astPtr, false, false);

 			// output data 
  			if(YFLAG){
				outY << "postfix_expression : postfix_expression LPAREN argument_expression_list RPAREN;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression LPAREN argument_expression_list RPAREN;};" << std::endl;
			}

			// check to see if the function parameters are valid 
 			$1->val._ste = currentFunc; 
 			std::string errorMsg = "";
 			if (!$1->val._ste->checkParams(funcCallingParams, errorMsg)) {
 				std::cout << COLOR_NORMAL << COLOR_CYAN_NORMAL << "ERROR: " << COLOR_NORMAL << errorMsg << std::endl;
 				yyerror("");
 			}
 			funcCallingParams.clear();

			// register data for graphviz
 			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "LPAREN", unique);
 			unique++;
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $3->astPtr);
 			outA << ";\n";
			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "RPAREN", unique);
 			unique++;
		}
	| postfix_expression DOT identifier
 		{
 			// output data
			if(YFLAG){
				outY << "postfix_expression : postfix_expression DOT identifier;" << std::endl;
				outG << "postfix_expression -> {postfix_expression DOT identifier};" << std::endl;
			}
		}
	| postfix_expression PTR_OP identifier
 		{
 			// output data
			if(YFLAG){
				outY << "postfix_expression : postfix_expression PTR_OP identifier;" << std::endl;
				outG << "postfix_expression -> {postfix_expression PTR_OP identifier};" << std::endl;
			}
		}
	| postfix_expression INC_OP /* a++, a[x][y]++. etc.. */
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
 			$$->astPtr = new postfixExpr_Node($1->astPtr, NULL, true, false);
 			//$$->astPtr->gen3AC();

 			// output data 
			if(YFLAG){
				outY << "postfix_expression : postfix_expression INC_OP;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression INC_OP};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputTerminal(outA, "INC_OP", unique);
 			unique++;

 			// do we need this? Seems like run-time stuff
 			/*
 			node* n = $1->val._ste->getIdentifierValue();
 			switch(n->valType) {
 				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
 					n->val._num++;
 					break; 

 				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
 					n->val._dec++;
 					break;

 				case CHAR_T:
 					n->val._char++;
 					break;

 				default:
 					yyerror("Unable to increment.");
 					break;
 			}
 			$1->val._ste->setIdentifierValue(*n);
			*/	
		}
	| postfix_expression DEC_OP /* a--, a[x][y]--, etc.. */
 		{
 			// create ast node and assign attributes
 			$$ = new node();
 			$$->valType = $1->valType;
 			$$->val = $1->val;
 			$$->astPtr = new postfixExpr_Node($1->astPtr, NULL, false, true);
 			//$$->astPtr->gen3AC(); 

 			// output data 
 			if(YFLAG){
				outY << "postfix_expression : postfix_expression DEC_OP;" << std::endl;
 				outG << "postfix_expression -> {postfix_expression DEC_OP};" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
 			outputNode(outA, $$->astPtr);
 			outA << " -> ";
 			outputNode(outA, $1->astPtr);
 			outA << ";\n";

 			// perform decrement - do we need this? Seems like run-time stuff
 			/*
 			node* n = $1->val._ste->getIdentifierValue();
 			switch(n->valType) {
 				case LONG_LONG_T:
				case LONG_T:
				case INT_T:
				case SHORT_T:
 					n->val._num--;
 					break; 

 				case FLOAT_T:
				case DOUBLE_T:
				case LONG_DOUBLE_T:
 					n->val._dec--;
 					break;

 				case CHAR_T:
 					n->val._char--;
 					break;

 				default:
 					yyerror("Unable to decrement.");
 					break;
 			}
 			$1->val._ste->setIdentifierValue(*n);
			*/
		}
	;

primary_expression /* no code in this production - just passing stuff up */
	: identifier
 		{
 			// output data 
			if(YFLAG){
				outY << "primary_expression : identifier;" << std::endl;
				outG << "primary_expression -> identifier;" << std::endl;
			}

			// pass pointer up tree 
 			$$ = $1;
		}
	| constant
 		{
 			// output data 
 			if(YFLAG){
				outY << "primary_expression : constant;" << std::endl;
				outG << "primary_expression -> constant;" << std::endl;
			}

			// pass pointer up tree
 			$$ = $1;
		}
	| string
 		{
 			// output data 
			if(YFLAG){
				outY << "primary_expression : string;" << std::endl;
				outG << "primary_expression -> string;" << std::endl;
			}
		}
	| LPAREN expression RPAREN
 		{
 			// assign appropriate node
 			$$ = $2;

 			// output data 
			if(YFLAG){
				outY << "primary_expression : LPAREN expression RPAREN;" << std::endl;
				outG << "primary_expression -> {LPAREN expression RPAREN};" << std::endl;
			}
		}
	;

argument_expression_list /* used for calling a function with actual parameters */
	: assignment_expression
 		{ 
			// push back the symbol table entry of the actual parameter
 			funcCallingParams.push_back($1->val._ste);

 			// output data 
 			if(YFLAG){
				outY << "argument_expression_list : assignment_expression;" << std::endl;
				outG << "argument_expression_list -> assignment_expression;" << std::endl;
			}

 			
 			// create ast node ?
		}
	| argument_expression_list COMMA assignment_expression
 		{
 			if(YFLAG){
				outY << "argument_expression_list : argument_expression_list COMMA assignment_expression;" << std::endl;
				outG << "argument_expression_list -> {argument_expression_list COMMA assignment_expression};" << std::endl;
			}
 			// push back the symbol table entry of the actual parameter
 			funcCallingParams.push_back($3->val._ste);

			// create ast node ?
		}
	;

constant
	: INTEGER_CONSTANT
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->val = $1->val; 
 			$$->valType = INT_T; 
 			$$->astPtr = new leaf_Node($$->val, $$->valType, "INTEGER_CONSTANT");

 			// output data
 			if(YFLAG){
				outY << "constant : INTEGER_CONSTANT;" << std::endl;
				outG << "constant -> INTEGER_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| CHARACTER_CONSTANT
 		{
			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->astPtr = new leaf_Node($1->val, $1->valType, "CHARACTER_CONSTANT");
 			$$->val = $1->val; 
 			$$->valType = CHAR_T; 

 			// output data
 			if(YFLAG){
				outY << "constant : CHARACTER_CONSTANT;" << std::endl;
				outG << "constant -> CHARACTER_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| FLOATING_CONSTANT
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->astPtr = new leaf_Node($1->val, $1->valType, "FLOATING_CONSTANT");
 			$$->val = $1->val; 
 			$$->valType = FLOAT_T;

 			// output data
 			if(YFLAG){
				outY << "constant : FLOATING_CONSTANT;" << std::endl;
				outG << "constant -> FLOATING_CONSTANT;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	| ENUMERATION_CONSTANT
 		{
 			/* not sure what to do about this */
			if(YFLAG){
				outY << "constant : ENUMERATION_CONSTANT;" << std::endl;
				outG << "constant -> ENUMERATION_CONSTANT;" << std::endl;
			}

			// displaying error message 
			yyerror("catfishC cannot handle enumeration constants.");
		}
	;

string
	: STRING_LITERAL
 		{
 			// create ast node and assign attributes
 			$$ = new node(); 
 			$$->astPtr = new leaf_Node($1->val, $1->valType, "STRING_LITERAL");
 			strcpy($$->val._str, $1->val._str);
 			$$->valType = STR_T; 

 			// output data 
			if(YFLAG){
				outY << "string : STRING_LITERAL;" << std::endl;
				outG << "string -> STRING_LITERAL;" << std::endl;
			}

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	;

identifier
	: IDENTIFIER
		{
			// output data
			if(YFLAG){
				outY << "identifier : IDENTIFIER;" << std::endl;
				outG << "identifier -> IDENTIFIER;" << std::endl;
			}

			// create ast node and assign attributes
			$$ = new node(); 
			$$->astPtr = new leaf_Node($1->val, $1->valType, $1->val._ste->getIdentifierName());
			$$->val = $1->val;
			$$->valType = $1->valType;

			// register data for graphviz
			registerNode(outA, $$->astPtr);
		}
	;
%% /* end of ANSI C grammar and actions */

/* user code */

/*
Function: yyerror(const char* s)

Description: Used for error messages in both the Flex and Bison files. 
*/
void yyerror(const char* s) {

	std::cout << s << std::endl;
	exit(-1);
}

/*
Function: integerTicketCounter()

Description: Returns a unique string for each integer encountered while 
parsing.
*/
std::string intTC() {
	return "IT_" + std::to_string(intTicket++);
}

std::string labelTC() {
	return "Label_" + std::to_string(labelCount++);
}

void registerNode(std::ofstream &out, astNode* ptr){

	out << ptr->getName() << '_' << ptr->getID() << ' ';
	out << "[label = \"" << ptr->getName() << "\"" << "]";
	out << ';' << std::endl;
}

void outputNode(std::ofstream &out, astNode* ptr){

	out << ptr->getName() << '_' << ptr->getID();
}

void outputTerminal(std::ofstream &out, std::string name, int id){
	out << name << id << ";\n";
	out << name << id << "[label=" << name << "];\n";
}