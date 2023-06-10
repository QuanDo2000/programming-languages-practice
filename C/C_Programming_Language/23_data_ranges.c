#include <limits.h>
#include <stdio.h>

int main() {
  printf("The range of signed char is %d to %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("The range of unsigned char is 0 to %d\n", UCHAR_MAX);
  printf("The range of signed short is %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("The range of unsigned short is 0 to %d\n", USHRT_MAX);
  printf("The range of signed int is %d to %d\n", INT_MIN, INT_MAX);
  printf("The range of unsigned int is 0 to %u\n", UINT_MAX);
  printf("The range of signed long is %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("The range of unsigned long is 0 to %lu\n", ULONG_MAX);
  return 0;
}