#include <stdio.h>

main() {
  int c;

  printf("EOF value: %d\n", EOF);
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}