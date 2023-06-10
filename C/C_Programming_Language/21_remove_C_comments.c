#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '/') {
      if ((c = getchar()) == '*') {
        while ((c = getchar()) != EOF) {
          if (c == '*') {
            if ((c = getchar()) == '/') {
              break;
            }
          }
        }
      } else if (c == '/') {
        while ((c = getchar()) != EOF) {
          if (c == '\n') {
            break;
          }
        }
      } else {
        putchar('/');
        putchar(c);
      }
    } else {
      putchar(c);
    }
  }

  return 0;
}
