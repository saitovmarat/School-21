struct stack {
    int num;
    struct stack* prev;
};
struct stack* init(int num);
struct stack* push(struct stack* highest, int num);
struct stack* pop(struct stack* highest);
void destroy(struct stack* highest);
