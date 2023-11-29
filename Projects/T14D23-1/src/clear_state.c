#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Records {
    int year;
    int month;
    int days;
    int hours;
    int minutes;
    int seconds;
    int status;
    int code;
};
void addInStart(char* original, const char* newString) {
    char temp[100];
    strcpy(temp, newString);
    strcat(temp, original);
    strcpy(original, temp);
}
int printBinFile(char* filepath) {
    FILE* file = fopen(filepath, "rb+");
    int isEmpty = 1;
    if (!file) {
        printf("n/a");
        return 0;
    }
    struct Records arr;
    while ((fread(&arr, sizeof(struct Records), 1, file)) != 0) {
        isEmpty = 0;
        printf("%d %d %d %d %d %d %d %d\n", arr.year, arr.month, arr.days, arr.hours, arr.minutes,
               arr.seconds, arr.status, arr.code);
    }
    fclose(file);
    return isEmpty;
}
void swap(int i, int j, FILE* file) {
    struct Records arr1, arr2;

    fseek(file, i * sizeof(struct Records), SEEK_SET);
    fread(&arr1, sizeof(struct Records), 1, file);

    fseek(file, j * sizeof(struct Records), SEEK_SET);
    fread(&arr2, sizeof(struct Records), 1, file);

    fseek(file, i * sizeof(struct Records), SEEK_SET);
    fwrite(&arr2, sizeof(struct Records), 1, file);

    fseek(file, j * sizeof(struct Records), SEEK_SET);
    fwrite(&arr1, sizeof(struct Records), 1, file);
}
int differrence(struct Records* arr1, struct Records* arr2) {
    int dif = 0;
    if (arr1->year != arr2->year)
        dif = arr1->year - arr2->year;
    else if (arr1->month != arr2->month)
        dif = arr1->month - arr2->month;
    else if (arr1->days != arr2->days)
        dif = arr1->days - arr2->days;
    else if (arr1->hours != arr2->hours)
        dif = arr1->hours - arr2->hours;
    else if (arr1->minutes != arr2->minutes)
        dif = arr1->minutes - arr2->minutes;
    else if (arr1->seconds != arr2->seconds)
        dif = arr1->seconds - arr2->seconds;
    else if (arr1->status != arr2->status)
        dif = arr1->status - arr2->status;
    else if (arr1->code != arr2->code)
        dif = arr1->code - arr2->code;
    return dif;
}
int sortBinFile(char* filepath) {
    struct Records arr1;
    struct Records arr2;
    FILE* file = fopen(filepath, "rb+");
    if (!file) {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    if (fileSize == 0) {
        fclose(file);
        return 0;
    }

    long count = (long)fileSize / sizeof(struct Records);
    for (int i = 0; i < count; ++i) {
        for (int j = i; j < count; ++j) {
            fseek(file, j * sizeof(struct Records), SEEK_SET);
            fread(&arr1, sizeof(struct Records), 1, file);
            fseek(file, (j + 1) * sizeof(struct Records), SEEK_SET);
            fread(&arr2, sizeof(struct Records), 1, file);
            if (differrence(&arr1, &arr2) > 0) {
                swap(j, j + 1, file);
            }
        }
    }
    rewind(file);
    fclose(file);
    return 1;
}
void clearBinFile(FILE* file, FILE* fileNew, struct Records* arr1, struct Records* arr2) {
    if (!file) return;
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    if (fileSize == 0) {
        printf("n/a");
        return;
    }
    struct Records temp;
    long count = (long)fileSize / sizeof(struct Records);
    int j = 0;
    for (int i = 0; i < count; i++) {
        fseek(file, i * sizeof(struct Records), SEEK_SET);
        fread(&temp, sizeof(struct Records), 1, file);
        if (differrence(&temp, arr1) <= 0 || differrence(&temp, arr2) >= 0) {
            fseek(fileNew, j * sizeof(struct Records), SEEK_SET);
            fwrite(&temp, sizeof(struct Records), 1, fileNew);
            j++;
        }
    }
    return;
}

//"../datasets/door_state_3"
int main() {
    char filepath[100];
    scanf(" %99[^\n]", filepath);
    addInStart(filepath, "../");
    sortBinFile(filepath);

    struct Records arr1;
    struct Records arr2;
    if (scanf("%d.%d.%d %d.%d.%d", &arr1.days, &arr1.month, &arr1.year, &arr2.days, &arr2.month,
              &arr2.year) == 6) {
        FILE* file = fopen(filepath, "rb+");
        FILE* fileNew = fopen("../datasets/door_state_4", "wb+");
        clearBinFile(file, fileNew, &arr1, &arr2);
        rename("../datasets/door_state_4", filepath);
        printBinFile(filepath);
        fclose(fileNew);
        fclose(file);
    } else
        printf("n/a");
    return 0;
}
