#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

int getline(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > MINLINE) {
      printf("%s", line);
    }
  }
  return 0;
}

int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  if (c != EOF && c != '\n') {
    s[i - 1] = '.';
    s[i - 2] = '.';
    s[i - 3] = '.';
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
  }
  return i;
}