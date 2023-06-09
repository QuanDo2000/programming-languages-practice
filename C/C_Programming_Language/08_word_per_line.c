#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n') {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == IN) {
        printf("\n");
      }
      state = OUT;
    } else if (state == OUT) {
      printf("%c", c);
      state = IN;
      ++nw;
    } else {
      printf("%c", c);
    }
  }
  printf("Lines: %d\nWords: %d\nChars: %d\n", nl, nw, nc);
}