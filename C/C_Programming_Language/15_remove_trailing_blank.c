#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
int RemoveTrailingBlank(char line[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getline(line, MAXLINE)) > 0) {
    len = RemoveTrailingBlank(line, len);
    if (len > 0) {
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

int RemoveTrailingBlank(char s[], int len) {
  int i;

  for (i = len - 2; i >= 0 && (s[i] == ' ' || s[i] == '\t'); --i) {
    ;
  }
  if (i >= 0) {
    s[i + 1] = '\n';
    s[i + 2] = '\0';
  }
  return i;
}