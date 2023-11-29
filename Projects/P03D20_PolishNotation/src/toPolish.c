#include "toPolish.h"

#include "countPolish.h"

void infixToPostfix(char *infix, char *postfix) {
    struct Operator operators[100];
    int operatorTop = -1;
    int postfixIndex = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isDigit(infix[i]) || infix[i] == 'x' || infix[i] == '.') {
            while (isDigit(infix[i]) || infix[i] == 'x' || infix[i] == '.' || infix[i] == ',') {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            operators[++operatorTop].op = '(';
            operators[operatorTop].precedence = 0;
        } else if (infix[i] == ')') {
            while (operatorTop >= 0 && operators[operatorTop].op != '(') {
                postfix[postfixIndex++] = operators[operatorTop--].op;
                postfix[postfixIndex++] = ' ';
            }
            operatorTop--;
        } else if (isOperator(infix[i])) {
            while (operatorTop >= 0 && operators[operatorTop].precedence >= getPrecedence(infix[i])) {
                postfix[postfixIndex++] = operators[operatorTop--].op;
                postfix[postfixIndex++] = ' ';
            }
            operators[++operatorTop].op = infix[i];
            operators[operatorTop].precedence = getPrecedence(infix[i]);
        } else if (isAlphabetic(infix[i])) {
            char function[10];
            int j = 0;
            while (isAlphabetic(infix[i])) {
                function[j++] = infix[i++];
            }
            function[j] = '\0';
            i--;

            while (operatorTop >= 0 && operators[operatorTop].precedence >= 3) {
                postfix[postfixIndex++] = operators[operatorTop--].op;
                postfix[postfixIndex++] = ' ';
            }
            if (function[1] == 'i') {
                operators[++operatorTop].op = 'S';
                operators[operatorTop].precedence = 3;
            } else if (function[1] == 'o') {
                operators[++operatorTop].op = 'C';
                operators[operatorTop].precedence = 3;
            } else {
                operators[++operatorTop].op = function[0];
                operators[operatorTop].precedence = 3;
            }
        }
    }
    while (operatorTop >= 0) {
        postfix[postfixIndex++] = operators[operatorTop--].op;
        postfix[postfixIndex++] = ' ';
    }
    postfix[postfixIndex] = '\0';
}
