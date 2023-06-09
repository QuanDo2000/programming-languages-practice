#include <conio.h>
#include <stdio.h>

#define EOF_VAL 26

int main() {
  int c, nl, nb, nt;

  nl = 0;
  nb = 0;
  nt = 0;
  while ((c = getch()) != EOF_VAL) {
    switch (c) {
      case 13:
        putch('\n');
        ++nl;
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
        putch(c);
        ++nb;
        break;
      case '\t':
        putch(c);
        ++nt;
        break;
      default:
        putch(c);
        break;
    }
    // printf("(%d) ", c);
  }
  printf("Number of newlines: %d\n", nl);
  printf("Number of blanks: %d\n", nb);
  printf("Number of tabs: %d\n", nt);
}