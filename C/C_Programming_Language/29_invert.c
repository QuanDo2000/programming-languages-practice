#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  unsigned x = 0b11111111;
  int p = 4;
  int n = 2;
  printf("%d\n", invert(x, p, n));
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}