#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXCHAR];
char longest[MAXCHAR];

int getline(void);
void copy(void);

int main() {
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) {
    printf("Longest line (%d characters):\n%s", max, longest);
  }
  return 0;
}

int getline(void) {
  int c, i;
  extern char line[];

  for (i = 0; i < MAXCHAR - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }

  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  if (c != EOF && c != '\n') {
    line[i - 1] = '\n';
    line[i - 2] = '.';
    line[i - 3] = '.';
    line[i - 4] = '.';
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
  }
  return i;
}

void copy(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0') {
    ++i;
  }
}