#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int sum = 0;
  char delimiters[] = ",:; ";
  int t = 100;
  for (int i = 0; i < t; ++i) {
    char buffer[201];
    scanf(" %200[0-9A-Za-z ;:,]", buffer);
    char *pch;
    pch = strtok(buffer, delimiters);
    pch = strtok(NULL, delimiters);
    int id = atoi(pch);
    pch = strtok(NULL, delimiters);
    int val = 0;
    int j = 0;
    int flag = 1;
    while (pch != NULL) {
      if (j % 2 == 0) {
        val = atoi(pch);
      } else {
        if ((!strcmp(pch, "blue") && val > 14) ||
            (!strcmp(pch, "green") && val > 13) ||
            (!strcmp(pch, "red") && val > 12)) {
          flag = 0;
        }
      }
      pch = strtok(NULL, delimiters);
      j = j + 1;
    }
    if (flag) {
      sum += id;
    }
  }
  printf("%d\n", sum);
  return 0;
}