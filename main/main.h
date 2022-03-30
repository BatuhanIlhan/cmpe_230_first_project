#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

enum types{scalar,vector,matrix};

FILE *pInputFile;
FILE *pOutputFile;

int lineNumber;

char * special_functions;

extern void printCloseBracket();
extern void print_usual();
extern void printsep();

extern char *trim(char *s);

extern int is_alphanumeric(char* s);
extern int is_alphanumeric_string(char* s);
extern int is_numeric_string(char *s);

extern void scalar_line(char* line);
extern void vector_line(char* line);
extern void matrix_line(char* line);

char* summation(char *first,char* second);
char* substraction(char *first,char* second);
char* multiplication(char *first,char* second);
char* expression_parser(char *line);

extern void exit_program(int lineNumber);

#endif