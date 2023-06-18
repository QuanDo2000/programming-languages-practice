#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 100

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("Usage: expr 2 3 4 + mult\n");
    printf("Due to globbing on Windows, use \"mult\" instead of *\n");
    return 1;
  }

  double val[MAXVAL];
  int sp = 0;

  for (int i = 0; i < MAXVAL; i++) {
    val[i] = 0.0;
  }

  for (int i = 1; i < argc; i++) {
    // printf("argv[%d]: %s\n", i, argv[i]);
    if (strcmp(argv[i], "+") == 0) {
      val[sp - 2] = val[sp - 2] + val[sp - 1];
      sp--;
    } else if (strcmp(argv[i], "-") == 0) {
      val[sp - 2] = val[sp - 2] - val[sp - 1];
      sp--;
    } else if (strcmp(argv[i], "mult") == 0) {
      // On Windows, * is a special character which expands to files, so we use "mult" instead.
      val[sp - 2] = val[sp - 2] * val[sp - 1];
      sp--;
    } else if (strcmp(argv[i], "/") == 0) {
      val[sp - 2] = val[sp - 2] / val[sp - 1];
      sp--;
    } else {
      val[sp++] = atof(argv[i]);
    }
    // for (int i = 0; i < sp; i++) {
    //   printf("%g ", val[i]);
    // }
    // printf("\n");
  }

  printf("%g\n", val[0]);

  return 0;
}