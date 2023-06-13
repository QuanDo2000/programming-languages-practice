#include <stdio.h>

void strncpy(char *s, char *t, int n);
void strncat(char *s, char *t, int n);
int strncmp(char *s, char *t, int n);

int main() {
  char s[100] = "Hello ";
  char t[] = "World!";

  strncpy(s, t, 3);
  printf("%s %s\n", s, t);

  strncat(s, t, 3);
  printf("%s %s\n", s, t);

  printf("%d\n", strncmp(s, t, 3));

  return 0;
}

void strncpy(char *s, char *t, int n) {
  while (n-- > 0 && (*s++ = *t++) != '\0')
    ;
  *s = '\0';
}

void strncat(char *s, char *t, int n) {
  while (*s != '\0')
    s++;
  while (n-- > 0 && (*s++ = *t++) != '\0')
    ;
  *s = '\0';
}

int strncmp(char *s, char *t, int n) {
  for (; n-- > 0 && *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}