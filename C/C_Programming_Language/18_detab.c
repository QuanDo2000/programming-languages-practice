#include <stdio.h>

#define MAXLINE 1000
#define TABINC 8

int getline(char line[], int maxline);
void detab(char line[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    detab(line, len);
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

void detab(char s[], int len) {
  int i, j, k, n;
  char temp[MAXLINE];

  for (i = 0, j = 0; i < len; ++i, ++j) {
    if (s[i] == '\t') {
      n = TABINC - (j % TABINC);
      for (k = 0; k < n; ++k) {
        temp[j + k] = ' ';
      }
      j = j + k - 1;
    } else {
      temp[j] = s[i];
    }
  }
  temp[j] = '\0';

  for (i = 0; (s[i] = temp[i]) != '\0'; ++i) {
    ;
  }
}
