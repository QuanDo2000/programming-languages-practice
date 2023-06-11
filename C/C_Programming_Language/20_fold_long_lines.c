#include <stdio.h>

#define MAXLINE 1000
#define MAXLEN 80

int getline(char line[], int maxline);
void print_folded_line(char line[], int len);

int main() {
  int len;
  char line[MAXCHAR];

  while ((len = getline(line, MAXCHAR)) > 0) {
    if (len > MAXLEN) {
      print_folded_line(line, len);
    } else {
      printf("%s", line);
    }
  }
  return 0;
}

int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  if (c != EOF && c != '\n') {
    s[i - 1] = '\n';
    s[i - 2] = '.';
    s[i - 3] = '.';
    s[i - 4] = '.';
    while ((c = getchar()) != EOF && c != '\n') {
      ++i;
    }
  }
  return i;
}

void print_folded_line(char s[], int len) {
  int i, j, last_blank;
  char temp[MAXLEN + 2];

  i = j = 0;
  last_blank = 0;
  while (i < len && i < MAXCHAR) {
    // printf("i = %d, j = %d, s[i] = %c, last_blank = %d\n", i, j, s[i], last_blank);
    if (s[i] == ' ') {
      last_blank = i;
    }

    if (j >= MAXLEN) {
      if (last_blank > 0) {
        temp[j - (i - last_blank)] = '\n';
        temp[j - (i - last_blank) + 1] = '\0';
        i = last_blank;
        last_blank = 0;
      } else {
        temp[j - 2] = '-';
        temp[j - 1] = '\n';
        temp[j] = '\0';
        i = i - 3;
      }
      printf("%s", temp);
      temp[0] = '\0';
      j = 0;
    } else {
      temp[j] = s[i];
      ++j;
    }
    ++i;
  }

  if (j > 0) {
    printf("%s", temp);
    temp[j] = '\0';
  }
}