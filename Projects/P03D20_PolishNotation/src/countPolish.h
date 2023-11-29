#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isDigit(char c);
int isAlphabetic(char c);
int getPrecedence(char op);
int isOperator(char c);
int ctgEx(double x);
int tgEx(double x);
double evaluateFunction(const char *function, double x);
double evaluateOperation(double operand1, double operand2, char operation);
int isAlphabetic(char c);
int isDigit(char c);
double evaluatePostfix(char *postfix, double x);
