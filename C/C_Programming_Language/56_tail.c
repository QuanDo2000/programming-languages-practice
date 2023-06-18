#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define MAXLINES 100

int getline(char line[], int maxline);

int main(int argc, char *argv[]) {
  int ntail, len, nlines;
  char *lineptr[MAXLINES];
  int start = 0, curr = 0, loop = 0;
  char line[MAXLINE];

  if (argc == 1) {
    ntail = 10;
  } else if (argc == 2 && (*++argv)[0] == '-') {
    ntail = atoi(argv[0] + 1);
    if (ntail > MAXLINES) {
      printf("error: too many lines\n");
      return 1;
    }
  } else {
    printf("error: usage: tail [-n]\n");
    return 1;
  }

  nlines = 0;
  while ((len = getline(line, MAXLINE)) > 0) {
    lineptr[curr] = malloc(len + 1);
    if (lineptr[curr] == NULL) {
      printf("error: malloc failed\n");
      return 1;
    }
    line[len] = '\0';
    strcpy(lineptr[curr], line);
    curr = (curr + 1) % MAXLINES;
    nlines++;
    if (curr == start) {
      start = (start + 1) % MAXLINES;
      loop = 1;
    }
  }

  if (loop) {
    start = (curr + (MAXLINES - ntail)) % MAXLINES;
  } else if (curr < ntail) {
    start = 0;
  } else {
    start = curr - ntail;
  }

  while (ntail-- > 0 && nlines-- > 0) {
    // printf("%d: ", start);
    printf("%s", lineptr[start]);
    start = (start + 1) % MAXLINES;
  }

  return 0;
}

int getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}