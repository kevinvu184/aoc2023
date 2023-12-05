#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void mapping(int to, int t, long long seeds[t]) {
  long long map[to][3];
  scanf(" %*[a-z -]:");
  for (int i = 0; i < to; ++i) {
    scanf(" %lld %lld %lld", &map[i][0], &map[i][1], &map[i][2]);
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

  int t = 10;
  long long seedpacked[t][2];
  long long total = 0;
  for (int i = 0; i < t; ++i) {
    scanf(" %lld %lld", &seedpacked[i][0], &seedpacked[i][1]);
    total += seedpacked[i][1];
  }
  long long *seeds = (long long *)malloc(total * sizeof(long long));
  long long sid = 0;
  for (int j = 0; j < t; ++j) {
    for (long long s = 0; s < seedpacked[j][1]; ++s) {
      seeds[sid++] = seedpacked[j][0] + s;
    }
  }

  int stos = 37;
  mapping(stos, total, seeds);
  int stof = 10;
  mapping(stof, total, seeds);
  int ftow = 36;
  mapping(ftow, total, seeds);
  int wtol = 46;
  mapping(wtol, total, seeds);
  int ltot = 28;
  mapping(ltot, total, seeds);
  int ttoh = 40;
  mapping(ttoh, total, seeds);
  int htol = 42;
  mapping(htol, total, seeds);

  long long lowest = LONG_MAX;
  for (int i = 0; i < total; ++i) {
    if (seeds[i] < lowest) {
      lowest = seeds[i];
    }
  }

  printf("%lld", lowest);

  free(seeds);
  return 0;
}