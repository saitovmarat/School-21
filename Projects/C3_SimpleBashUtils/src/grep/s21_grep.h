#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 1024

typedef struct {
  int eflag;
  int iflag;
  int vflag;
  int cflag;
  int lflag;
  int nflag;
  int hflag;
  int sflag;
  int fflag;
  int oflag;
  int errorflag;
} flags;

typedef struct {
  char *path;
  int count_files;
  int count_pattern;
} grep_values;

int parseFlags(int argc, char **argv, flags *flag, grep_values *value,
               char pattern[SIZE][SIZE]);
void flagsRealisation(grep_values value, flags flag, char pattern[SIZE][SIZE]);
int find_pattern(int opt_ind, char **argv, char patterns[SIZE][SIZE]);
void flag_f(char *path, char pattern[SIZE][SIZE], grep_values *value);
void flag_cl(grep_values value, flags flag, int count_matched_lines);
void flag_o(char *start_point, regex_t preg);
void printing_strings(grep_values value, flags flag, int count_lines,
                      char *string);