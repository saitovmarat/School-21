#include "countPolish.h"

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

int ctgEx(double x) { return fmod(x, M_PI); }
int tgEx(double x) { return fmod(x, M_PI / 2); }

double evaluateFunction(const char *function, double x) {
    double res = 0.0;
    if (strcmp(function, "c") == 0) {
        if (!ctgEx(x))
            res = 0.5;
        else
            res = cos(x) / sin(x);
    } else if (strcmp(function, "t") == 0) {
        if (!tgEx(x))
            res = 0.5;
        else
            res = cos(x) / sin(x);
    } else if (strcmp(function, "l") == 0) {
        if (x <= 0) {
            res = 1000;
        } else
            res = log(x);
    } else if (strcmp(function, "s") == 0) {
        if (x < 0) {
            res = 1000;
        } else
            res = sqrt(x);
    } else if (strcmp(function, "C") == 0)
        res = cos(x + 0.1);
    else if (strcmp(function, "S") == 0)
        res = sin(x + 0.1);
    return res;
}

double evaluateOperation(double operand1, double operand2, char operation) {
    double result = 0;
    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 == 0) {
                result = 1000;
            } else
                result = operand1 / operand2;
            break;
        default:
            break;
    }
    return result;
}
int isAlphabetic(char c) { return ((c != 'x' && (c >= 'a' && c <= 'z')) || (c >= 'A' && c <= 'Z')); }

int isDigit(char c) { return (c >= '0' && c <= '9'); }

double evaluatePostfix(char *postfix, double x) {
    double stack[1000];
    int top = -1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isDigit(postfix[i]) || postfix[i] == 'x' || postfix[i] == '.' || postfix[i] == ',') {
            double num = 0.0;
            double isFractionPart = 0;
            while (isDigit(postfix[i]) || postfix[i] == 'x' || postfix[i] == '.' || postfix[i] == ',') {
                if (postfix[i] == 'x')
                    num = num * 10 + x;
                else if (postfix[i] == '.' || postfix[i] == ',')
                    isFractionPart = 0.1;
                else if (isFractionPart) {
                    num = num + (postfix[i] - '0') * isFractionPart;
                    isFractionPart *= 0.1;
                } else
                    num = num * 10 + (postfix[i] - '0');
                i++;
            }
            stack[++top] = num;
        } else if (postfix[i] == ' ') {
            continue;
        } else if (isOperator(postfix[i])) {
            double operand2 = stack[top--];
            double operand1 = stack[top--];
            stack[++top] = evaluateOperation(operand1, operand2, postfix[i]);
        } else if (isAlphabetic(postfix[i])) {
            char function[10];
            int j = 0;
            while (isAlphabetic(postfix[i])) {
                function[j++] = postfix[i++];
            }
            function[j] = '\0';
            i--;
            double argument = stack[top--];
            double result = evaluateFunction(function, argument);
            stack[++top] = result;
        }
    }
    return stack[top];
}
