#include <stdio.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
  int n = 20;
  char s[100];
  itoa(n, s, 10);
  printf("%s\n", s);
  return 0;
}

void itoa(int n, char s[], int w) {
  int i, sign;
  sign = n;
  i = 0;
  do {
    s[i++] = ((n % 10) * ((sign < 0) ? -1 : 1)) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  while (i < w) {
    s[i++] = ' ';
  }
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int i, j, temp;
  for (i = 0, j = 0; s[j] != '\0'; j++) {
    ;
  }
  j--;
  if (s[j] == '\n') {
    j--;
  }
  for (; i < j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}