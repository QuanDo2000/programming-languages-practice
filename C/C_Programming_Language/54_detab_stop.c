#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABINC 8
#define MAXSTOPS 100

int getline(char line[], int maxline);
void detab(char line[], int len, int tabstops[]);
int comp(const void *a, const void *b);

int tab_inc = 8;
int tab_start = 0;

int main(int argc, char *argv[]) {
  int len;
  char line[MAXLINE];
  int tabstops[MAXSTOPS];

  for (int i = 0; i < MAXSTOPS; i++) {
    tabstops[i] = 0;
  }

  int j = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      tab_start = atoi(argv[i] + 1);
    } else if (argv[i][0] == '+') {
      tab_inc = atoi(argv[i] + 1);
    } else {
      tabstops[j] = atoi(argv[i]);
      j++;
    }
  }

  qsort(tabstops, MAXSTOPS, sizeof(int), comp);

  while ((len = getline(line, MAXLINE)) > 0) {
    detab(line, len, tabstops);
    printf("%s", line);
  }
  return 0;
}

int comp(const void *a, const void *b) {
  if (*(int *)a == 0) {
    return 1;
  } else if (*(int *)b == 0) {
    return -1;
  } else {
    return (*(int *)a - *(int *)b);
  }
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

void detab(char s[], int len, int tabstops[]) {
  int i, j, k, n;
  char temp[MAXLINE];

  for (i = 0, j = 0; i < len; ++i, ++j) {
    if (s[i] == '\t') {
      if (tabstops[0] != 0) {
        for (k = 0; k < MAXSTOPS && tabstops[k] < j && tabstops[k] != 0; ++k) {
          ;
        }
        if (tabstops[k] == j) {
          n = tabstops[k + 1] - j;
        } else if (tabstops[k] != 0) {
          n = tabstops[k] - j;
        } else if (j < tab_start) {
          n = TABINC - (j % TABINC);
        } else {
          n = tab_inc - ((j - tab_start) % tab_inc);
        }
      } else if (j < tab_start) {
        n = TABINC - (j % TABINC);
      } else {
        n = tab_inc - ((j - tab_start) % tab_inc);
      }

      for (k = 0; k < n; ++k) {
        temp[j + k] = ' ';
      }
      j = j + k - 1;
    } else {
      temp[j] = s[i];
    }
  }
  temp[j] = '\0';

  for (i = 0; (s[i] = temp[i]) != '\0'; ++i) {
    ;
  }
}
