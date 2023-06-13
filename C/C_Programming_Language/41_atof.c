#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int getline(char line[], int max);
double atof(char s[]);

int main() {
  double sum, atof(char[]);
  char line[MAXLINE];
  int getline(char line[], int max);
  sum = 0;
  while (getline(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

int getline(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sign;
  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  int exp_sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  int exp = 0;
  for (; isdigit(s[i]); i++)
    exp = 10 * exp + (s[i] - '0');
  for (int j = 0; j < exp; j++)
    power *= ((exp_sign == -1) ? 10 : 0.1);
  return sign * val / power;
}