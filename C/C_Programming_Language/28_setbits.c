#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned x = 0b11111111;
  unsigned y = 0b00000000;
  int p = 4;
  int n = 2;
  printf("%d\n", setbits(x, p, n, y));
  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}