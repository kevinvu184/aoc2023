#include <stdio.h>

int handcmp(char *, char *);
int card(char);
int type(char *);

struct Play {
  char hand[6];
  int bid;
};

int main(void) {
  int t = 1000;
  struct Play plays[t];
  for (int i = 0; i < t; ++i) {
    scanf("%5s %d", plays[i].hand, &plays[i].bid);
  }

  for (int i = 0; i < t; ++i) {
    for (int j = i; j < t; ++j) {
      if (handcmp(plays[i].hand, plays[j].hand) > 0) {
        struct Play tmp = plays[i];
        plays[i] = plays[j];
        plays[j] = tmp;
        continue;
      }
    }
  }

  long long res = 0;
  for (int i = 0; i < t; ++i) {
    res += plays[i].bid * (i + 1);
  }
  printf("%lld\n", res);
  return 0;
}

int handcmp(char *h1, char *h2) {
  // type ordering rule
  int t = type(h1) - type(h2);
  if (t != 0) {
    return t;
  }

  // second ordering rule
  while (*h1 == *h2++)
    if (*h1++ == '\0') return 0;
  return card(*h1) - card(*(h2 - 1));
}

int type(char *h) {
  char map[5][2];
  for (int i = 0; i < 5; ++i) {
    map[i][0] = 0;
    map[i][1] = 0;
  }

  for (char *p = h; *p; ++p) {
    for (int i = 0; i < 5; ++i) {
      if (map[i][0] == 0) {
        map[i][0] = *p;
        map[i][1]++;
        break;
      } else if (map[i][0] == *p) {
        map[i][1]++;
        break;
      }
    }
  }

  if (map[0][1] == 5) return 7;
  if (map[0][1] == 4 || map[1][1] == 4) return 6;
  if ((map[0][1] == 3 && map[1][1] == 2) || (map[0][1] == 2 && map[1][1] == 3))
    return 5;
  if (map[0][1] == 3 || map[1][1] == 3 || map[2][1] == 3) return 4;

  int pair = 0;
  for (int i = 0; i < 5; ++i) {
    if (map[i][1] == 2) pair++;
  }
  if (pair == 2) return 3;
  if (pair == 1) return 2;

  return 1;
}

int card(char c) {
  switch (c) {
    case '2':
      return 1;
    case '3':
      return 2;
    case '4':
      return 3;
    case '5':
      return 4;
    case '6':
      return 5;
    case '7':
      return 6;
    case '8':
      return 7;
    case '9':
      return 8;
    case 'T':
      return 9;
    case 'J':
      return 10;
    case 'Q':
      return 11;
    case 'K':
      return 12;
    case 'A':
      return 13;
  }
  return 0;
}