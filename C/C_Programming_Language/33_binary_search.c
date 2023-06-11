#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int v[] = {1, 2, 3, 4, 5, 6, 7, 8};
  printf("%d\n", binsearch(3, v, 8));
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  if (x == v[mid])
    return mid;
  else if (x == v[low])
    return low;
  else if (x == v[high])
    return high;
  return -1;
}