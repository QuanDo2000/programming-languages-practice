#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABINC 8
#define MAXSTOPS 100

int getline(char line[], int maxline);
void entab(char line[], int len, int tabstops[]);
int comp(const void *a, const void *b);
int get_tabstop(int pos, int tabstops[]);

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
    entab(line, len, tabstops);
    printf("%s", line);
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

void entab(char s[], int len, int tabstops[]) {
  int i, j, k, n, space_count;
  char temp[MAXLINE];

  for (i = 0, j = 0; i < len; ++i, ++j) {
    if (s[i] == ' ') {
      int t = i;
      space_count = 1;
      while (s[i + 1] == ' ') {
        ++space_count;
        ++i;
      }
      n = get_tabstop(t, tabstops);
      while (space_count >= n && n > 0) {
        temp[j] = '\t';
        space_count -= n;
        t += n;
        n = get_tabstop(t, tabstops);
        ++j;
      }
      for (k = 0; k < space_count; ++k, ++j) {
        temp[j] = ' ';
      }
      --j;
    } else {
      temp[j] = s[i];
    }
  }
  temp[j] = '\0';
  for (i = 0; i < j; ++i) {
    s[i] = temp[i];
  }
  s[i] = '\0';
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

int get_tabstop(int pos, int tabstops[]) {
  int i;

  for (i = 0; i < MAXSTOPS; ++i) {
    if (tabstops[i] > pos) {
      return tabstops[i] - pos;
    }
  }
  if (pos < tab_start) {
    return TABINC - (pos % TABINC);
  } else {
    return tab_inc - ((pos - tab_start) % tab_inc);
  }
}