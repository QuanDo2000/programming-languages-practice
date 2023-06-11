#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
  char s1[] = "-A-z0-9";
  char s2[100];
  expand(s1, s2);
  printf("%s\n", s2);
  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j, k;
  for (i = 0, j = 0; s1[i] != '\0'; i++) {
    if (s1[i] == '-') {
      if (i == 0 || s1[i + 1] == '\0' || s1[i - 1] >= s1[i + 1]) {
        s2[j++] = s1[i];
        continue;
      }
      for (k = s1[i - 1] + 1; k < s1[i + 1]; k++) {
        s2[j++] = k;
      }
    } else {
      s2[j++] = s1[i];
    }
  }
  s2[j] = '\0';
}