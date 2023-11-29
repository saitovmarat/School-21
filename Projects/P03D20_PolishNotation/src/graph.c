#include "countPolish.h"
#include "print.h"
#include "toPolish.h"

int main() {
    char infix[1000];

    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';

    char postfix[1000];
    infixToPostfix(infix, postfix);

    plot_function(evaluatePostfix, postfix);
    return 0;
}
