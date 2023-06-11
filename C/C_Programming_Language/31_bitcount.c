#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned x = 0b10101010101010101010101010101010;
  printf("%d\n", bitcount(x));
  return 0;
}

int bitcount(unsigned x) {
  int b;
  // x &= (x - 1) deletes the rightmost 1-bit in x
  // This is because x - 1 flips the rightmost 1-bit and all bits to the right
  for (b = 0; x != 0; x &= (x - 1)) {
    printf("x: %x, b: %d\n", x, b);
    b++;
  }
  return b;
}