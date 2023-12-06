#include <math.h>
#include <stdio.h>

int main(void) {
  int t = 4;
  long double races[t][2];

  scanf("%*s:");
  for (int i = 0; i < t; ++i) {
    scanf(" %Lf", &races[i][0]);
    if (i > 0) {
      long long tmp = races[i][0];
      int digit = 0;
      while (tmp > 0) {
        tmp /= 10;
        digit++;
      }
      races[i][0] = races[i - 1][0] * pow(10, digit) + races[i][0];
    }
  }

  scanf("%*s:");
  for (int i = 0; i < t; ++i) {
    scanf(" %Lf", &races[i][1]);
    if (i > 0) {
      long long tmp = races[i][1];
      int digit = 0;
      while (tmp > 0) {
        tmp /= 10;
        digit++;
      }
      races[i][1] = races[i - 1][1] * pow(10, digit) + races[i][1];
    }
  }

  // x^2 - races[i][0]x + races[i][1] = 0
  long double sq = sqrt(pow(races[t - 1][0], 2.0) - 4.0 * races[t - 1][1]);
  long double x1 = (races[t - 1][0] - sq) / 2.0;
  long long v1 = ceil(x1);
  long long v2 = (long long)races[t - 1][0] - v1;
  while (v1 * v2 <= races[t - 1][1]) {
    v1++;
    v2--;
  }

  printf("%lld\n", v2 - v1 + 1);

  return 0;
}