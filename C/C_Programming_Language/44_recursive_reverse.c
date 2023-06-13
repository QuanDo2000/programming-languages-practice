#include <stdio.h>

void reverse(char s[]);

int main() {
  char s[] = "Hello, world!";
  reverse(s);
  printf("%s\n", s);
  return 0;
}

void reverse(char s[]) {
  static int i = 0;
  static int j = 0;
  int temp;
  if (s[j] != '\0') {
    j++;
    reverse(s);
  }
  j--;
  if (i < j) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
  }
}