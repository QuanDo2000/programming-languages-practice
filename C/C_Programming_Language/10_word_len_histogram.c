#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, i, j, state, word_len;
  int word_len_count[10];

  state = OUT;
  word_len = 0;

  for (i = 0; i < 10; ++i) {
    word_len_count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (word_len > 0) {
        ++word_len_count[word_len - 1];
        word_len = 0;
      }
    } else if (state == OUT) {
      state = IN;
      ++word_len;
    } else {
      ++word_len;
    }
  }

  printf("Word length histogram:\n");
  for (i = 0; i < 10; ++i) {
    printf("%d: ", i + 1);
    for (j = 0; j < word_len_count[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }
}