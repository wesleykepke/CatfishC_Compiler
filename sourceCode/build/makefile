# Name: Renee Iinuma, Kyle Lee, and Wesley Kepke
# File: KRW_Makefile
# Created: September 28, 2015
# Last Modified: October 15, 2015

# This is the makefile for the catfishC compiler.

# Macros
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG) -Wno-unused-function -Wno-return-type
LFLAGS = -Wall $(DEBUG) -Wno-unused-function -Wno-return-type
FLEX = flex
BISON = bison
LIBS = -L/usr/local/lib -lfl
OBJS = ../lexer/lex.yy.o ../parser/cParser.tab.o ../main/main.o \
		../classes/symbolTable.o ../classes/symbolTableEntry.o \
		../classes/scope.o ../classes/registerTable.o
NSRC = $(wildcard ../parser/nodes/*.cpp)
NOBJS = $(NSRC:.cpp=.o)

# Targets, dependencies, and rules
all: ../bin/catfishC

../bin/catfishC: $(OBJS) $(NOBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS) $(NOBJS) $(LIBS)

../main/main.o: ../main/main.cpp
	$(CC) $(CFLAGS) $< -o $@  

../classes/symbolTableEntry.o: ../classes/symbolTableEntry.cpp \
								../classes/symbolTableEntry.h
	$(CC) $(CFLAGS) $< -o $@

../classes/symbolTable.o: ../classes/symbolTable.cpp \
							../classes/symbolTable.h \
							../classes/symbolTableEntry.o
	$(CC) $(CFLAGS) $< -o $@

../classes/scope.o: ../classes/scope.cpp ../classes/scope.h \
					../classes/symbolTableEntry.o
	$(CC) $(CFLAGS) $< -o $@

../classes/registerTable.o: ../classes/registerTable.cpp ../classes/registerTable.h
	$(CC) $(CFLAGS) $< -o $@

../lexer/lex.yy.c: ../lexer/cLexer.l ../parser/cParser.tab.c
	$(FLEX) $<
	mv lex.yy.c ../lexer/

../parser/cParser.tab.c: ../parser/cParser.y
	$(BISON) -d $<
	mv cParser.tab.h ../parser/
	mv cParser.tab.c ../parser/

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(NOBJS) ../parser/cParser.tab.* ../lexer/lex.yy.* \
		../bin/catfishC