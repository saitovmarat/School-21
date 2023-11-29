#include "print_module.h"

#include <stdio.h>

int print_char(char ch) { return putchar(ch); }

void print_log(int (*print)(char), char* message) {
    time_t current_time;
    struct tm* time_info;
    char time_string[9];
    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);
    char* d = Log_prefix;
    while (*d != '\0') {
        print(*d);
        d++;
    }
    print(' ');
    for (int i = 0; i < 8; i++) {
        print(time_string[i]);
    }
    print(' ');
    while (*message != '\0') {
        print(*message);
        message++;
    }
}
