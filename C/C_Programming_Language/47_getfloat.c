#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getfloat(float *);

int main() {
  int n;
  float array[10];

  for (n = 0; n < 10 && getfloat(&array[n]) != EOF; n++)
    ;
  for (n = 0; n < 10; n++)
    printf("%f ", array[n]);
  printf("\n");
  return 0;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* get a (possibly pushed back) character */
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

/* push character back on input */
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn) {
  int c, sign;
  float power;

  while (isspace(c = getch())) /* skip white space */
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    int d = c; /* remember sign character */
    if (!isdigit(c = getch())) {
      if (c != EOF)
        ungetch(c); /* push back non-digit */
      ungetch(d);   /* push back sign character */
      return d;     /* return sign character */
    }
  }
  for (*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c - '0');
  if (c == '.')
    c = getch();
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }
  *pn *= sign / power;
  if (c != EOF)
    ungetch(c);
  return c;
}