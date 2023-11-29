#include "logger.h"

FILE* log_init(char* filename) { return fopen(filename, "a"); }
int logcat(FILE* log_file, char* message, enum log_level level) {
    if (!log_file) return 0;
    time_t now;
    time(&now);
    struct tm* local = localtime(&now);
    int hours = local->tm_hour;
    int minutes = local->tm_min;
    int seconds = local->tm_sec;
    if (level == debug)
        fprintf(log_file, "DEBUG");
    else if (level == trace)
        fprintf(log_file, "TRACE");
    else if (level == info)
        fprintf(log_file, "INFO");
    else if (level == warning)
        fprintf(log_file, "WARNING");
    else if (level == error)
        fprintf(log_file, "ERROR");
    fprintf(log_file, "-%d:%d:%d-%s\n", hours, minutes, seconds, message);
    return 1;
}
int log_close(FILE* log_file) {
    if (!log_file) return 0;
    fclose(log_file);
    return 1;
}
