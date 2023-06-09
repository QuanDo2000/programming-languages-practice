#include <conio.h>
#include <stdio.h>

#define EOF_VAL 26

int main() {
  int c;

  while ((c = getch()) != EOF_VAL) {
    switch (c) {
      case 13:
        putch('\n');
        break;
      case 8:
        putch('\\');
        putch('b');
        break;
      case 3:
        putch('^');
        putch('C');
        return 0;
        break;
      case 9:
        putch('\\');
        putch('t');
        break;
      case '\\':
        putch('\\');
        putch('\\');
        break;
      default:
        putch(c);
        break;
    }
  }
}