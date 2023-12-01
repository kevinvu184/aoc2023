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
      if (*p >= 48 && *p <= 57) {
        ldigit = *p - '0';
      } else if (*p == 'e') {
        if (*(p - 1) == 'n' && *(p - 2) == 'o') ldigit = 1;
        if (*(p - 1) == 'v' && *(p - 2) == 'i' && *(p - 3) == 'f') ldigit = 5;
        if (*(p - 1) == 'n' && *(p - 2) == 'i' && *(p - 3) == 'n') ldigit = 9;
        if (*(p - 1) == 'e' && *(p - 2) == 'r' && *(p - 3) == 'h' &&
            *(p - 4) == 't')
          ldigit = 3;
      } else if (*p == 'n') {
        if (*(p - 1) == 'e' && *(p - 2) == 'v' && *(p - 3) == 'e' &&
            *(p - 4) == 's')
          ldigit = 7;
      } else if (*p == 'o') {
        if (*(p - 1) == 'w' && *(p - 2) == 't') ldigit = 2;
      } else if (*p == 'r') {
        if (*(p - 1) == 'u' && *(p - 2) == 'o' && *(p - 3) == 'f') ldigit = 4;
      } else if (*p == 't') {
        if (*(p - 1) == 'h' && *(p - 2) == 'g' && *(p - 3) == 'i' &&
            *(p - 4) == 'e')
          ldigit = 8;
      } else if (*p == 'x') {
        if (*(p - 1) == 'i' && *(p - 2) == 's') ldigit = 6;
      }
      if (!fdigit) {
        fdigit = ldigit;
      }
    }
    sum += fdigit * 10 + ldigit;
  }
  printf("%d", sum);
  return 0;
}