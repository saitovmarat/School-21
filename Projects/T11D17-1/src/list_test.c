#include "list.h"

#include <stdio.h>
#include <stdlib.h>
void add_door_test(struct node* root, struct door* door);
void remove_door_test(struct node* root, struct door* door);

int main() {
    // Quest_2
    struct door* door1 = (struct door*)malloc(sizeof(struct door));
    struct door* door2 = (struct door*)malloc(sizeof(struct door));
    struct door* door3 = (struct door*)malloc(sizeof(struct door));
    door1->status = 1;
    door1->id = 1;
    door2->status = 0;
    door2->id = 2;
    door3->status = 0;
    door3->id = 2;

    struct node* root = init(door1);
    add_door_test(root, door2);
    printf("\n");
    remove_door_test(root, door3);
    destroy(root);
    free(door1);
    free(door2);
    free(door3);
    return 0;
}
void add_door_test(struct node* root, struct door* door) {
    struct node* checkDoor = add_door(root, door);
    if (checkDoor->door.id == door->id) {
        remove_door(checkDoor, root);
        printf("SUCCESS");
    } else {
        remove_door(checkDoor, root);
        printf("FAIL");
    }
}
void remove_door_test(struct node* root, struct door* door) {
    struct node* checkDoor = add_door(root, door);
    remove_door(checkDoor, root);
    if (find_door(checkDoor->door.id, root) == NULL) {
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}
