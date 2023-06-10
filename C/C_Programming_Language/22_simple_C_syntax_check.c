#include <stdio.h>

#define MAXLEN 1000

int main() {
  char error[MAXLEN];
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '(':
        error[i++] = ')';
        break;
      case '[':
        error[i++] = ']';
        break;
      case '{':
        error[i++] = '}';
        break;
      case '/':
        if ((c = getchar()) == '/') {
          while ((c = getchar()) != '\n' && c != EOF)
            ;
        } else if (c == '*') {
          while ((c = getchar()) != EOF) {
            if (c == '*') {
              if ((c = getchar()) == '/') {
                break;
              }
            }
          }
        }
        break;
      case '"':
        while ((c = getchar()) != '"' && c != '\n' && c != EOF) {
          ;
        }
        break;
      case '\'':
        while ((c = getchar()) != '\'' && c != '\n' && c != EOF) {
          ;
        }
        break;
      case ')':
      case ']':
      case '}':
        // printf("Bracket: %c\n", c);
        if (i > 0 && error[i - 1] == c) {
          i--;
        } else {
          printf("Mismatch: %c %c\n", c, error[i - 1]);
          return 1;
        }
        break;
      default:
        break;
    }
  }

  if (i > 0) {
    printf("Extra bracket: %c\n", error[i - 1]);
    return 1;
  }
}