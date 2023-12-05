#include <limits.h>
#include <stdio.h>

void mapping(int to, int t, long seeds[t]) {
  long map[to][3];
  scanf(" %*[a-z -]:");
  for (int i = 0; i < to; ++i) {
    scanf(" %ld %ld %ld", &map[i][0], &map[i][1], &map[i][2]);
  }
  for (int i = 0; i < t; ++i) {
    int mapped = 0;
    for (int j = 0; j < to; ++j) {
      if (!mapped &&
          (map[j][1] <= seeds[i] && seeds[i] < map[j][1] + map[j][2])) {
        seeds[i] = seeds[i] - map[j][1] + map[j][0];
        mapped = 1;
        break;
      }
    }
  }
}

int main(void) {
  scanf(" %*[a-z -]:");

  int t = 20;
  long seeds[t];
  for (int i = 0; i < t; ++i) {
    scanf(" %ld", &seeds[i]);
  }

  int stos = 37;
  mapping(stos, t, seeds);
  int stof = 10;
  mapping(stof, t, seeds);
  int ftow = 36;
  mapping(ftow, t, seeds);
  int wtol = 46;
  mapping(wtol, t, seeds);
  int ltot = 28;
  mapping(ltot, t, seeds);
  int ttoh = 40;
  mapping(ttoh, t, seeds);
  int htol = 42;
  mapping(htol, t, seeds);

  long lowest = LONG_MAX;
  for (int i = 0; i < t; ++i) {
    if (seeds[i] < lowest) {
      lowest = seeds[i];
    }
  }

  printf("%ld", lowest);

  return 0;
}