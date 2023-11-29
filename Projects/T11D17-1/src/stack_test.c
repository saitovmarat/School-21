#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push_test(struct stack* highest, int num);
void pop_test(struct stack* highest);

int main() {
    struct stack* highest1 = init(1);
    push_test(highest1, 2);
    destroy(highest1);
    printf("\n");
    struct stack* highest2 = init(2);
    pop_test(highest2);
    return 0;
}
void push_test(struct stack* highest, int num) {
    struct stack* current = push(highest, num);
    if (current->prev == highest) {
        pop(current);
        printf("SUCCESS");
    } else {
        pop(current);
        printf("FAIL");
    }
}
void pop_test(struct stack* highest) {
    if (highest->prev == pop(highest))
        printf("SUCCESS");
    else
        printf("FAIL");
}
