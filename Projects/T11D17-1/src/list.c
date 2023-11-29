#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(struct door* door) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->door.id = door->id;
    newNode->door.status = door->status;
    newNode->next = NULL;
    return newNode;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->door.id = door->id;
    newNode->door.status = door->status;
    newNode->next = elem->next;
    elem->next = newNode;
    return newNode;
}
struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current->next != NULL && current->door.id == door_id) {
        current = current->next;
    }
    if (current->door.id == door_id)
        return current;
    else
        return NULL;
}
struct node* remove_door(struct node* elem, struct node* root) {
    struct node* temp = root;
    if (root == elem) {
        temp = root->next;
        free(root);
        return temp;
    }
    while (temp) {
        if (temp->next == elem) {
            temp->next = elem->next;
            free(elem);
            break;
        }
        temp = temp->next;
    }
    return root;
}
void destroy(struct node* root) {
    struct node* current = root;
    while (current->next != NULL) {
        remove_door(current->next, root);
    }
    free(root);
}
