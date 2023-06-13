#include <stdio.h>

int strend(char *s, char *t);

int main() {
  char s[] = "Hello, world!";
  char t[] = "world!";

  printf("%d\n", strend(s, t));

  return 0;
}

int strend(char *s, char *t) {
  char *bs = s;
  char *bt = t;

  for (; *s; s++)
    ;
  for (; *t; t++)
    ;
  for (; *s == *t; s--, t--)
    if (t == bt || s == bs)
      break;
  if (*s == *t && t == bt && *s != '\0')
    return 1;
  else
    return 0;
}