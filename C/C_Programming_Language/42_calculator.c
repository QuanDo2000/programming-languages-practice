#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define COMMAND '1' /* signal that a command was found */
#define MAXVAL 100  /* maximum depth of val stack */
#define BUFSIZE 100 /* buffer size (Ex4.8: No need to modify getch or ungetch) */
#define VAR_MAX 26

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */
double var[VAR_MAX];

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char[]);
double store_var(char);
double get_var(char);

/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  for (int i = 0; i < VAR_MAX; i++) {
    var[i] = 0.0;
  }

  // Ex4.10: getline

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case COMMAND:
        if (strcmp(s, "sin") == 0) {
          push(sin(pop()));
        } else if (strcmp(s, "cos") == 0) {
          push(cos(pop()));
        } else if (strcmp(s, "exp") == 0) {
          push(exp(pop()));
        } else if (strcmp(s, "pow") == 0) {
          op2 = pop();
          push(pow(pop(), op2));
        } else if (strcmp(s, "sqrt") == 0) {
          push(sqrt(pop()));
        } else if (strcmp(s, "clear") == 0) {
          sp = 0;
        } else if (strcmp(s, "pop") == 0) {
          printf("\t%.8g\n", pop());
        } else if (strcmp(s, "duplicate") == 0) {
          push(val[sp - 1]);
        } else if (strcmp(s, "swap") == 0) {
          op2 = pop();
          push(pop());
          push(op2);
        } else if (strcmp(s, "ans") == 0) {
          push(val[sp - 1]);
        } else if (strcmp(s, "store") == 0) {
          store_var(pop());
        } else if (strcmp(s, "get") == 0) {
          get_var(pop());
        } else if (s[0] >= 'A' && s[0] <= 'Z') {
          push(s[0]);
        } else {
          printf("error: unknown command %s\n", s);
        }
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '\n':
        printf("\t%.8g\n", val[sp - 1]);
        break;
      case '%':
        op2 = pop();
        if (op2 != 0.0)
          push((int)pop() % (int)op2);
        else
          printf("error: zero divisor\n");
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* getop: get next character or numeric operand */
int getop(char s[]) {
  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    if (!isalpha(c))
      return c; /* not a number */
    else {
      i = 0;
      while (isalpha(s[++i] = c = getch()))
        ;
      s[i] = '\0';
      if (c != EOF)
        ungetch(c);
      return COMMAND;
    }
  i = 0;
  if (c == '-') {
    if (isdigit(c = getch()) || c == '.') {
      s[++i] = c;
    } else {
      if (c != EOF)
        ungetch(c);
      return '-';
    }
  }
  if (isdigit(c)) /* collect integer part */
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

/*
 * Ex4.9: From the implementation, EOF can never be pushed-back.
 */

int getch(void) /* get a (possibly pushed-back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
  int len = strlen(s);
  while (len > 0) {
    ungetch(s[--len]);
  }
}

double store_var(char c) {
  if (c >= 'A' && c <= 'Z') {
    var[c - 'A'] = pop();
  } else {
    printf("error: invalid variable name %c\n", c);
  }
  return var[c - 'A'];
}

double get_var(char c) {
  if (c >= 'A' && c <= 'Z') {
    push(var[c - 'A']);
  } else {
    printf("error: invalid variable name %c\n", c);
  }
  return var[c - 'A'];
}