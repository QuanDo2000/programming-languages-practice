#include <conio.h>
#include <stdio.h>

#define EOF_VAL 26

int main() {
  int c;

  printf("EOF_VAL value: %d\n", EOF_VAL);
  while ((c = getch()) != EOF_VAL) {
    switch (c) {
      case 13:
        putch('\n');
        break;
      case 8:
        putch('\b');
        putch(' ');
        putch('\b');
        break;
      case 3:
        putch('^');
        putch('C');
        return 0;
        break;
      default:
        putch(c);
        break;
    }
    // printf("(%d) ", c);
  }
}