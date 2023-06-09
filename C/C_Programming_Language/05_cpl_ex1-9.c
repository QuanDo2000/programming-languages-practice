#include <conio.h>
#include <stdio.h>

#define EOF_VAL 26

int main() {
  int curr, last;

  last = 0;
  while ((curr = getch()) != EOF_VAL) {
    switch (curr) {
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
      case ' ':
        if (last != ' ') {
          putchar(curr);
        }
        break;
      default:
        putch(curr);
        break;
    }
    last = curr;
  }
}