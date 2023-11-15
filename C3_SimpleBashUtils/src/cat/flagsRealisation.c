#include "s21_cat.h"

int parseFlags(int argc, char **argv, flags *flag) {
  struct option Options[] = {{"number-nonblank", no_argument, NULL, 'b'},
                             {"number", no_argument, NULL, 'n'},
                             {"squeeze-blank", no_argument, NULL, 's'},
                             {NULL, 0, NULL, 0}};

  int opt;

  while ((opt = getopt_long(argc, argv, "beEvnstT?", Options, NULL)) != -1) {
    switch (opt) {
      case 'b':
        flag->bflag = 1;
        break;
      case 'e':
        flag->eflag = flag->vflag = 1;
        break;
      case 'E':
        flag->eflag = 1;
        break;
      case 'n':
        flag->nflag = 1;
        break;
      case 's':
        flag->sflag = 1;
        break;
      case 't':
        flag->tflag = flag->vflag = 1;
        break;
      case 'T':
        flag->tflag = 1;
        break;
      case 'v':
        flag->vflag = 1;
        break;
      case '?':
        flag->errorflag = 1;
        break;
    }
  }
  return optind;
}

void flagsRealisation(char *file, flags flag) {
  if (access(file, F_OK) == 0) {
    FILE *filename = fopen(file, "rt");
    char cur, prev;
    int current_line = 1;
    int squeeze = 0;
    for (prev = '\n'; (cur = getc(filename)) != EOF; prev = cur) {
      if (flag.sflag == 1) {
        if (cur == '\n' && prev == '\n') {
          if (squeeze == 1) {
            continue;
          }
          squeeze++;
        } else
          squeeze = 0;
      }

      if (flag.bflag == 1) {
        if (prev == '\n' && cur != '\n') {
          printf("%*d\t", 6, current_line);
          current_line++;
        }
      }
      if (flag.nflag == 1 && flag.bflag == 0 && prev == '\n') {
        printf("%*d\t", 6, current_line);
        current_line++;
      }

      if (flag.eflag == 1 && cur == '\n') {
        putchar('$');
      }

      if (flag.tflag == 1 && cur == '\t') {
        printf("^");
        cur = 'I';
      }

      if (flag.vflag == 1) {
        if ((cur >= 0 && cur <= 31) && cur != '\t' && cur != '\n') {
          printf("^");
          cur = cur + 64;

        } else if (cur == 127) {
          printf("^");
          cur = cur - 64;
        }
      }
      putchar(cur);
    }
    fclose(filename);
  } else {
    fprintf(stderr, "No such file or directory: %s\n", file);
  }
}
