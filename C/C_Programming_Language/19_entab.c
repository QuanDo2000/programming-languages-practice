#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int getline(char line[], int maxline);
void entab(char line[], int len);

int main() {
  int len;
  char line[MAXCHAR];

  while ((len = getline(line, MAXCHAR)) > 0) {
    entab(line, len);
    printf("%s", line);
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
    s[i - 1] = '\n';
    s[i - 2] = '.';
    s[i - 3] = '.';
    s[i - 4] = '.';
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
  }
  return i;
}

void entab(char s[], int len) {
  int i, j, k, n, space_count;
  char temp[MAXCHAR];

  for (i = 0, j = 0; i < len; ++i, ++j) {
    if (s[i] == ' ') {
      space_count = 1;
      while (s[i + 1] == ' ') {
        ++space_count;
        ++i;
      }
      n = TABINC - (j % TABINC);
      while (space_count >= n) {
        temp[j] = '\t';
        space_count -= n;
        n = TABINC;
        ++j;
      }
      for (k = 0; k < space_count; ++k, ++j) {
        temp[j] = ' ';
      }
      --j;
    } else {
      temp[j] = s[i];
    }
  }
  temp[j] = '\0';
  for (i = 0; i < j; ++i) {
    s[i] = temp[i];
  }
  s[i] = '\0';
}