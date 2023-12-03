#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int sum = 0;
  char delimiters[] = ",:; ";
  int t = 5;
  for (int i = 0; i < t; ++i) {
    int maxblue = INT_MIN;
    int maxgreen = INT_MIN;
    int maxred = INT_MIN;

    char buffer[201];
    scanf(" %200[0-9A-Za-z ;:,]", buffer);

    int val = 0;
    int j = 0;

    char *pch;
    pch = strtok(buffer, delimiters);
    pch = strtok(NULL, delimiters);
    pch = strtok(NULL, delimiters);
    while (pch != NULL) {
      if (j % 2 == 0) {
        val = atoi(pch);
      } else {
        if (!strcmp(pch, "blue") && val > maxblue) {
          maxblue = val;
        } else if (!strcmp(pch, "green") && val > maxgreen) {
          maxgreen = val;
        } else if (!strcmp(pch, "red") && val > maxred) {
          maxred = val;
        }
      }
      pch = strtok(NULL, delimiters);
      j = j + 1;
    }
    printf("%d %d %d\n", maxred, maxgreen, maxblue);
    sum += maxblue * maxgreen * maxred;
  }
  printf("%d\n", sum);
  return 0;
}