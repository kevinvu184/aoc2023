#include <stdio.h>

int main(void) {
  int t = 193;
  int w = 10;
  int n = 25;
  int sum = 0;
  int allwins[t];
  for (int i = 0; i < t; ++i) {
    allwins[i] = 0;
  }

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

    for (int a = 0; a < w; ++a) {
      for (int b = 0; b < n; ++b) {
        if (wins[a] == nums[b]) {
          allwins[i] += 1;
        }
      }
    }
  }

  int instances[t];
  for (int i = 0; i < t; ++i) {
    instances[i] = 1;
  }

  for (int i = 0; i < t; ++i) {
    for (int j = 0; j < allwins[i]; ++j) {
      instances[i + j + 1] += instances[i];
    }
  }

  for (int i = 0; i < t; ++i) {
    sum += instances[i];
  }

  printf("%d\n", sum);
  return 0;
}