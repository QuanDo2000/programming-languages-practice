#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int reverse, fold, dir;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
  int nlines;      /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  reverse = 0;     /* 1 if reverse sort */
  fold = 0;        /* 1 if fold sort */
  dir = 0;         /* 1 if directory sort */

  if (argc > 1) {
    while (--argc > 0) {
      if (strcmp(*++argv, "-n") == 0)
        numeric = 1;
      else if (strcmp(*argv, "-r") == 0)
        reverse = 1;
      else if (strcmp(*argv, "-f") == 0)
        fold = 1;
      else if (strcmp(*argv, "-d") == 0)
        dir = 1;
      else {
        printf("error: invalid option %s\n", *argv);
        return 1;
      }
    }
  }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    sort((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp)); /* sort input lines */
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000 /* max length of any input line */
int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* sort: sort v[left]...v[right] into increasing order */
void sort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  char s1[MAXLEN], s2[MAXLEN];
  void swap(void *v[], int i, int j);

  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (dir) {
      int t1 = 0, t2 = 0;
      while (((char *)v[i])[t1] != '\0') {
        if (isalnum(((char *)v[i])[t1]))
          s1[t2++] = ((char *)v[i])[t1];
        t1++;
      }
      s1[t2] = '\0';
      t1 = t2 = 0;
      while (((char *)v[left])[t1] != '\0') {
        if (isalnum(((char *)v[left])[t1]))
          s2[t2++] = ((char *)v[left])[t1];
        t1++;
      }
      s2[t2] = '\0';
    } else {
      strcpy(s1, v[i]);
      strcpy(s2, v[left]);
    }
    if (fold) {
      for (int j = 0; s1[j] != '\0'; j++)
        s1[j] = tolower(s1[j]);
      for (int j = 0; s2[j] != '\0'; j++)
        s2[j] = tolower(s2[j]);
    }
    if (reverse && (*comp)(s1, s2) > 0)
      swap(v, ++last, i);
    else if (!reverse && (*comp)(s1, s2) < 0)
      swap(v, ++last, i);
  }
  swap(v, left, last);
  sort(v, left, last - 1, comp);
  sort(v, last + 1, right, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);

  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int getline(char *s, int lim) {
  int c;
  char *t = s;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;
  if (c == '\n')
    *s++ = c;
  *s = '\0';

  return s - t;
}

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) {                        /* return pointer to n characters */
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp - n; /* old p */
  } else               /* not enough room */
    return 0;
}