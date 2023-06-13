#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
int any(char s1[], char s2[]);

int main() {
  char s1[MAXLINE], s2[MAXLINE];

  printf("Enter string 1: ");
  getline(s1, MAXLINE);
  printf("Enter string 2: ");
  getline(s2, MAXLINE);

  printf("Result: %d\n", any(s1, s2));
  return 0;
}

int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; ++j)
      ;
    if (s2[j] != '\0')
      return i;
  }
  return -1;
}