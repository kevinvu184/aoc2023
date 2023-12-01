#include <stdio.h>

int main(void) {
  int sum = 0;
  int line = 1000;
  while (line--) {
    char in[61];
    scanf("%60s", in);
    int fdigit = 0;
    int ldigit = 0;
    for (char *p = in; *p; ++p) {
      if (!fdigit && *p >= 48 && *p <= 57) {
        fdigit = *p - '0';
      }
      if (*p >= 48 && *p <= 57) {
        ldigit = *p - '0';
      }
    }
    sum += fdigit * 10 + ldigit;
  }
  printf("%d", sum);
  return 0;
}