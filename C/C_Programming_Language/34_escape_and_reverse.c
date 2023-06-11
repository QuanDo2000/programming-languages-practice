#include <stdio.h>

#define MAXCHAR 10000

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);

int main() {
  char s[MAXCHAR], t[MAXCHAR];
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF) {
    t[i] = c;
    ++i;
  }
  t[i] = '\0';

  escape(s, t);
  printf("%s\n", s);

  reverse_escape(t, s);
  printf("%s\n", t);

  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    switch (t[i]) {
      case '\n':
        s[j] = '\\';
        ++j;
        s[j] = 'n';
        break;
      case '\t':
        s[j] = '\\';
        ++j;
        s[j] = 't';
        break;
      default:
        s[j] = t[i];
        break;
    }
    ++i;
    ++j;
  }
  s[j] = '\0';
}

void reverse_escape(char s[], char t[]) {
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    if (t[i] == '\\') {
      switch (t[i + 1]) {
        case 'n':
          s[j] = '\n';
          ++i;
          break;
        case 't':
          s[j] = '\t';
          ++i;
          break;
        default:
          s[j] = t[i];
          break;
      }
    } else {
      s[j] = t[i];
    }
    ++i;
    ++j;
  }
  s[j] = '\0';
}