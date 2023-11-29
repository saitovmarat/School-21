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
int findBinFile(char* filepath, int day, int month, int year) {
    FILE* file = fopen(filepath, "rb+");
    if (!file) {
        printf("n/a");
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    if (fileSize != 0) {
        struct Records arr;
        int flag = 0;
        long count = (long)fileSize / sizeof(struct Records);
        for (int i = 0; i < count; ++i) {
            fseek(file, i * sizeof(struct Records), SEEK_SET);
            fread(&arr, sizeof(struct Records), 1, file);
            if (arr.days == day && arr.month == month && arr.year == year) {
                printf("%d", arr.code);
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("n/a");
    } else {
        printf("n/a");
    }
    fclose(file);
    return 1;
}
//"../datasets/door_state_2"
int main() {
    char filepath[50];
    scanf(" %99[^\n]", filepath);
    addInStart(filepath, "../");

    int day, month, year;
    if (scanf("%d.%d.%d", &day, &month, &year) == 3) {
        findBinFile(filepath, day, month, year);
    } else
        printf("n/a");
    return 0;
}
