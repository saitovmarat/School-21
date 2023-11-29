#include "s21_string.h"

#include <stdio.h>

// Quest_1
int s21_strlen(const char* string) {
    int index = 0;
    while (string[index] != '\0') {
        index++;
    }
    return index;
}
// Quest_2
int s21_strcmp(const char* string1, const char* string2) {
    int i = 0;
    while (string1[i] == string2[i]) {
        if (string1[i] == '\0') {
            return 0;
        }
        i++;
    }
    return string1[i] - string2[i];
}
// Quest_3
char* s21_strcpy(char* str1, char* str2) {
    char* ptr = str2;
    while (*str1 != '\0') {
        *str2 = *str1;
        str2++;
        str1++;
    }
    *str2 = '\0';
    return ptr;
}

// Quest_4
char* s21_strcat(char* str1, char* str2) {
    char* ptr = str2;
    while (*str1 != '\0') {
        str1++;
    }
    s21_strcpy(str2, str1);
    return ptr;
}
// Quest_5
char* s21_strchr(char* str1, char symb) {
    while (*str1 != '\0') {
        if (*str1 == symb) {
            return str1;
        }
        str1++;
    }
    return NULL;
}
// Quest_6
int compare(const char* X, const char* Y) {
    while (*X && *Y) {
        if (*X != *Y) {
            return 0;
        }

        X++;
        Y++;
    }

    return (*Y == '\0');
}
const char* s21_strstr(const char* str1, const char* str2) {
    while (*str1 != '\0') {
        if ((*str1 == *str2) && compare(str1, str2)) {
            return str1;
        }
        str1++;
    }

    return NULL;
}
