#include <stdio.h>

#define LO 0
#define UP 300
#define STEP 20

int main() {
  float fahr, cels;

  printf("Fahrenheit\tCelsius\n");

  fahr = LO;
  while (fahr <= UP) {
    cels = (5.0 / 9.0) * (fahr - 32.0);
    printf("%10.0f\t%7.1f\n", fahr, cels);
    fahr = fahr + STEP;
  }

  printf("\n\nCelsius\tFahrenheit\n");

  cels = LO;
  while (cels <= UP) {
    fahr = ((9.0 / 5.0) * cels) + 32.0;
    printf("%7.0f\t%10.1f\n", cels, fahr);
    cels = cels + STEP;
  }

  printf("\n\nFahrenheit\tCelsius\n");

  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%10.0f\t%7.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}