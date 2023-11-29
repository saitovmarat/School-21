#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sortDoors(struct door *doors);
void closeDoors(struct door *doors);
void output(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sortDoors(doors);
    closeDoors(doors);
    output(doors);
    return 0;
}

void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
void sortDoors(struct door *doors) {
    struct door temp;
    for (int i = 0; i < DOORS_COUNT; i++) {
        for (int j = i; j < DOORS_COUNT; j++) {
            if (doors[i].id > doors[j].id) {
                temp = doors[i];
                doors[i] = doors[j];
                doors[j] = temp;
            }
        }
    }
}
void closeDoors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        if (i == DOORS_COUNT - 1)
            printf("%d, %d", doors[i].id, doors[i].status);
        else
            printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}
