#include <stdio.h>
#include <string.h>

struct Map {
  char key[4];
  char left[4];
  char right[4];
};

int main(void) {
  int t = 283;
  int c = 766;
  char key[4] = "AAA";

  char instructions[t];
  scanf("%s", instructions);
  struct Map map[c];
  for (int i = 0; i < c; ++i) {
    scanf(" %3s = (%3s, %3s)", map[i].key, map[i].left, map[i].right);
  }

  long long step = 0;
  int reach = 0;
  while (!reach) {
    for (int j = 0; j < c; ++j) {
      if (strcmp(key, map[j].key) == 0) {
        if (instructions[step % t] == 'L') {
          strcpy(key, map[j].left);
          break;
        } else if (instructions[step % t] == 'R') {
          strcpy(key, map[j].right);
          break;
        }
      }
    }
    if (strcmp(key, "ZZZ") == 0) reach = 1;
    step++;
  }
  printf("%lld", step);

  return 0;
}