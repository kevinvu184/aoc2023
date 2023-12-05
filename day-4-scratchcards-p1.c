#include <stdio.h>

int main(void) {
  int t = 193;
  int w = 10;
  int n = 25;
  int sum = 0;
  for (int i = 0; i < t; ++i) {
    char formatter[20];
    sprintf(formatter, " Card%4d:", i + 1);

    scanf(formatter);
    int wins[w];
    for (int j = 0; j < w; ++j) {
      scanf("%3d", &wins[j]);
    }
    scanf(" |");
    int nums[n];
    for (int j = 0; j < n; ++j) {
      scanf("%3d", &nums[j]);
    }

    int fwin = 0;
    int won = 1;
    for (int a = 0; a < w; ++a) {
      for (int b = 0; b < n; ++b) {
        if (wins[a] == nums[b]) {
          sum += won;
          !fwin ? (fwin = 1) : (won = won * 2);
        }
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}