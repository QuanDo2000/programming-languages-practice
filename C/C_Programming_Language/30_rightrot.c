#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {
  unsigned x = 0x12345678;
  int n = 2;
  printf("x = %x\n", x);
  printf("n = %d\n", n);
  printf("rightrot(x, n) = %x\n", rightrot(x, n));
  return 0;
}

unsigned rightrot(unsigned x, int n) {
  int i;
  unsigned mask = 0;
  for (i = 0; i < n * 4; i++) {
    mask = mask << 1;
    mask = mask | 1;
  }
  unsigned right = x & mask;
  unsigned left = x >> n * 4;
  return right << (sizeof(unsigned) * 8 - n * 4) | left;
}