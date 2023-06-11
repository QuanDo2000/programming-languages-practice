#include <stdio.h>

#define MAXLINE 1000

int main() {
  int c, i, lim;
  char s[MAXCHAR];

  lim = MAXCHAR;
  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) == '\n') {
      break;
    } else if (c == EOF) {
      break;
    } else {
      s[i] = c;
    }
  }
  s[i] = '\0';
  printf("%s\n", s);
}