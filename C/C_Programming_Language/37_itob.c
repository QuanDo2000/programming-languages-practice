#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  int n = 255;
  char s[100];
  itob(n, s, 10);
  printf("%s\n", s);
  return 0;
}

void itob(int n, char s[], int b) {
  int i, sign, temp;
  sign = n;
  i = 0;
  do {
    temp = ((n % b) * ((sign < 0) ? -1 : 1));
    if (temp < 10) {
      s[i++] = temp + '0';
    } else {
      s[i++] = temp - 10 + 'A';
    }
  } while ((n /= b) != 0);
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