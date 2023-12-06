#include <math.h>
#include <stdio.h>

int main(void) {
  int t = 4;
  long double races[t][2];

  scanf("%*s:");
  for (int i = 0; i < t; ++i) {
    scanf(" %Lf", &races[i][0]);
  }

  scanf("%*s:");
  for (int i = 0; i < t; ++i) {
    scanf(" %Lf", &races[i][1]);
  }

  long long multiply = 1;

  // x^2 - races[i][0]x + races[i][1] = 0
  for (int i = 0; i < t; ++i) {
    long double sq = sqrt(pow(races[i][0], 2.0) - 4.0 * races[i][1]);
    long double x1 = (races[i][0] - sq) / 2.0;

    long long v1 = ceil(x1);
    long long v2 = (long long)races[i][0] - v1;
    while (v1 * v2 <= races[i][1]) {
      v1++;
      v2--;
    }
    multiply *= v2 - v1 + 1;
  }

  printf("%lld\n", multiply);

  return 0;
}