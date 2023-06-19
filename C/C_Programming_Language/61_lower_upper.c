#include <ctype.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    return 1;
  }

  if (argv[1][0] == 'u') {
    char c;
    while ((c = getchar()) != EOF) {
      putchar(toupper(c));
    }
    return 0;
  } else if (argv[1][0] == 'l') {
    char c;
    while ((c = getchar()) != EOF) {
      putchar(tolower(c));
    }
    return 0;
  } else {
    return 1;
  }
}