#include <limits.h>
#include <stdio.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
  int n = INT_MIN;
  char s[100];
  itoa(n, s);
  printf("%s\n", s);
  return 0;
}

/*
 * itoa: convert n to characters in s
 * This version fixes the bug of INT_MIN where n = -n would overflow
 */
void itoa(int n, char s[]) {
  int i, sign;
  sign = n;
  i = 0;
  do {
    s[i++] = ((n % 10) * ((sign < 0) ? -1 : 1)) + '0';
  } while ((n /= 10) != 0);
  if (sign < 0) {
    s[i++] = '-';
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