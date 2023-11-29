#include "s21_string.h"

#include <stdio.h>
#include <stdlib.h>
void s21_strlen_test(const char* string, int len);
void s21_strcmp_test(const char* string1, const char* string2, int areSame);
void s21_strcpy_test(char* str1, char* str2);
void s21_strcat_test(char* str1, char* str2, char* str3);
void s21_strchr_test(char* str1, char symb, int isInStr);
void s21_strstr_test(char* str1, char* str2, int isInStr);
int main() {
// Quest_1
#if strlen
    s21_strlen_test("Hello", 5);
    printf("\n");
    s21_strlen_test("", 0);
    printf("\n");
    s21_strlen_test("+", 1);
    printf("\n");
#endif

// Quest_2
#if strcmp
    char* str1 = "HEllo";
    char* str2 = "hel";
    int areSame1 = -1;
    int areSame2 = 1;
    int areSame3 = 0;
    s21_strcmp_test(str1, str2, areSame1);
    printf("\n");
    s21_strcmp_test(str2, str1, areSame2);
    printf("\n");
    s21_strcmp_test(str2, str2, areSame3);
    printf("\n");
#endif

// Quest_3
#if strcpy
    char str1[50] = "HEALLER";
    char str2[50] = "HHHHHHHlpkj;j";
    char str3[50] = " ";
    char str4[50] = " ";
    s21_strcpy_test(str1, str2);
    printf("\n");
    s21_strcpy_test(str1, str3);
    printf("\n");
    s21_strcpy_test(str4, str1);
    printf("\n");
#endif

// Quest_4
#if strcat
    char str1[50] = "HEALL";
    char str2[50] = "gr";
    char str3[50] = " ";
    char str4[50] = " ";
    s21_strcat_test(str1, str2, "HEALLgr");
    printf("\n");
    s21_strcat_test(str3, str4, "  ");
    printf("\n");
    s21_strcat_test(str2, str1, "grHEALLgr");
    printf("\n");
#endif

// Quest_5
#if strchr
    char str[50] = "HELLO";
    char symb1 = 'L';
    char symb2 = 'P';
    char symb3 = ' ';
    int isInStr = 1;
    s21_strchr_test(str, symb1, isInStr);
    printf("\n");
    s21_strchr_test(str, symb2, !isInStr);
    printf("\n");
    s21_strchr_test(str, symb3, !isInStr);
    printf("\n");

#endif

// Quest_6
#if strstr
    char str[50] = "HELLO";
    char strCompare1[50] = "EL";
    char strCompare2[50] = "LE";
    char strCompare3[50] = " ";
    int isInStr = 1;
    s21_strstr_test(str, strCompare1, isInStr);
    printf("\n");
    s21_strstr_test(str, strCompare2, !isInStr);
    printf("\n");
    s21_strstr_test(str, strCompare3, !isInStr);
    printf("\n");
#endif
    return 0;
}

// Quest_1
void s21_strlen_test(const char* string, int len) {
    if ((s21_strlen(string)) == len) {
        printf("%s",string);
        printf(" %d ", s21_strlen(string));
        printf("SUCCESS");
    } else {
        printf("%s",string);
        printf(" %d ", s21_strlen(string));
        printf("FAIL");
    }
}
// Quest_2
void s21_strcmp_test(const char* string1, const char* string2, int areSame) {
    printf("%s",string1);
    printf(" ");
    printf("%s",string2);
    printf(" %d ", s21_strcmp(string1, string2));
    if (s21_strcmp(string1, string2) < 0 && areSame < 0)
        printf("SUCCESS");
    else if (s21_strcmp(string1, string2) > 0 && areSame > 0)
        printf("SUCCESS");
    else if (s21_strcmp(string1, string2) == 0 && areSame == 0)
        printf("SUCCESS");
    else
        printf("FAIL");
}
// Quest_3
void s21_strcpy_test(char* str1, char* str2) {
    printf("%s",str1);
    printf(" ");
    printf("%s",str2);
    char* temp = str2;
    s21_strcpy(str1, str2);
    printf("  ");
    printf("%s",str1);
    printf(" ");
    printf("%s",str2);
    if (s21_strcmp(temp, str2) == 0)
        printf(" SUCCESS");
    else
        printf(" FAIL");
}
// Quest_4
void s21_strcat_test(char* str1, char* str2, char* str3) {
    printf("%s",str1);
    printf(" ");
    printf("%s",str2);
    s21_strcat(str1, str2);
    printf("  ");
    printf("%s",str1);
    if (s21_strcmp(str1, str3) == 0)
        printf(" SUCCESS");
    else
        printf(" FAIL");
}
// Quest_5
void s21_strchr_test(char* str1, char symb, int isInStr) {
    printf("%s",str1);
    printf(" %c ", symb);
    if (s21_strchr(str1, symb) != NULL && isInStr)
        printf(" SUCCESS");
    else if (s21_strchr(str1, symb) == NULL && !isInStr)
        printf(" SUCCESS");
    else
        printf(" FAIL");
}
// Quest_6
void s21_strstr_test(char* str1, char* str2, int isInStr) {
    printf("%s", str1);
    printf(" ");
    printf("%s", str2);
    if (s21_strstr(str1, str2) != NULL && isInStr)
        printf(" SUCCESS");
    else if (s21_strstr(str1, str2) == NULL && !isInStr)
        printf(" SUCCESS");
    else
        printf(" FAIL");
}
