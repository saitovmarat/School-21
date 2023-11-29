#include "s21_cat.h"

int main(int argc, char **argv) {
  int filesCount;
  flags flag = {0};
  filesCount = parseFlags(argc, argv, &flag);

  if (flag.errorflag == 1) {
    fprintf(stderr, "Такого флага нет");
  } else {
    while (filesCount < argc) {
      char *file;
      file = argv[filesCount];
      flagsRealisation(file, flag);
      filesCount++;
    }
  }
  return 0;
}
