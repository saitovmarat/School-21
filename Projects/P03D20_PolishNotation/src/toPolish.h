struct Operator {
    char op;
    int precedence;
};

void infixToPostfix(char *infix, char *postfix);
