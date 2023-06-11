#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
int htoi(char s[]);

int main() {
  char s[MAXCHAR];
  getline(s, MAXCHAR);
  printf("%d\n", htoi(s));
  return 0;
}

int getline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  s[i] = '\0';
  return i;
}

int htoi(char s[]) {
  int i, n, c;
  i = 0;
  n = 0;
  if (s[i] == '0') {
    ++i;
    if (s[i] == 'x' || s[i] == 'X')
      ++i;
  }
  while (s[i] != '\0') {
    if (isdigit(s[i]))
      c = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      c = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      c = s[i] - 'A' + 10;
    else
      return -1;
    n = 16 * n + c;
    ++i;
  }
  return n;
}