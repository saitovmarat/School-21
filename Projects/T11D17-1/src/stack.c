#include "stack.h"

#include <stdlib.h>

struct stack* init(int num) {
    struct stack* newStack = (struct stack*)malloc(sizeof(struct stack));
    newStack->num = num;
    newStack->prev = NULL;
    return newStack;
}
struct stack* push(struct stack* highest, int num) {
    struct stack* current = (struct stack*)malloc(sizeof(struct stack));
    current->num = num;
    current->prev = highest;
    return current;
}
struct stack* pop(struct stack* highest) {
    struct stack* current = highest->prev;
    highest->prev = NULL;
    free(highest);
    return current;
}
void destroy(struct stack* highest) {
    struct stack* current = highest;
    while (current != NULL) {
        current = pop(highest);
    }
    free(current);
}
