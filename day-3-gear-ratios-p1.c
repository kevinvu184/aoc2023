#include <stdio.h>

int index(int n[2], int chars, char engine[][chars]) {
  int a = n[1];
  for (; a > -1; --a)
    if (engine[n[0]][a] < 48 || engine[n[0]][a] > 57) break;
  return ++a;
}

int number(int coord[2], int chars, char engine[][chars]) {
  int value = 0;

  int pre[5];
  int i1 = 0;
  for (int a = coord[1]; a > -1; --a) {
    if (engine[coord[0]][a] < 48 || engine[coord[0]][a] > 57) break;
    pre[i1++] = engine[coord[0]][a] - '0';
  }
  for (int a = i1 - 1; a >= 0; --a) {
    value = value * 10 + pre[a];
  }

  int pos[5];
  int i2 = 0;
  for (int a = coord[1] + 1; a < chars; ++a) {
    if (engine[coord[0]][a] < 48 || engine[coord[0]][a] > 57) break;
    pos[i2++] = engine[coord[0]][a] - '0';
  }
  for (int a = 0; a < i2; ++a) {
    value = value * 10 + pos[a];
  }

  return value;
}

void processIndex(int coord[2], int chars, char engine[][chars],
                  int indexes[][2], int values[], int *i1) {
  if (coord[0] != -1 && coord[1] != -1 && engine[coord[0]][coord[1]] >= 48 &&
      engine[coord[0]][coord[1]] <= 57) {
    int lv = number(coord, chars, engine);
    int li[2];
    li[0] = coord[0];
    li[1] = index(coord, chars, engine);
    int flag = 1;
    for (int j = 0; j < *i1; ++j) {
      if (indexes[j][0] == li[0] && indexes[j][1] == li[1]) flag = 0;
    }
    if (flag) {
      indexes[*i1][0] = li[0];
      indexes[*i1][1] = li[1];
      values[*i1] = lv;
      (*i1)++;
    }
  }
}

int main(void) {
  int sum = 0;

  int lines = 140;
  int chars = 140;
  char engine[lines][chars];
  for (int i = 0; i < lines; ++i) {
    char line[chars];
    scanf("%s", line);
    for (int j = 0; j < chars; ++j) {
      engine[i][j] = line[j];
    }
  }

  int indexes[100000][2];
  int values[100000];
  int i1 = 0;
  for (int i = 0; i < lines; ++i) {
    for (int j = 0; j < chars; ++j) {
      if ((engine[i][j] < 48 || engine[i][j] > 57) && engine[i][j] != '.') {
        int n[2] = {-1, -1};
        if (i - 1 >= 0) {
          n[0] = i - 1;
          n[1] = j;
        }
        processIndex(n, chars, engine, indexes, values, &i1);

        int ne[2] = {-1, -1};
        if (i - 1 >= 0 && j + 1 <= chars) {
          ne[0] = i - 1;
          ne[1] = j + 1;
        }
        processIndex(ne, chars, engine, indexes, values, &i1);

        int e[2] = {-1, -1};
        if (j + 1 <= chars) {
          e[0] = i;
          e[1] = j + 1;
        }
        processIndex(e, chars, engine, indexes, values, &i1);

        int es[2] = {-1, -1};
        if (i + 1 <= lines && j + 1 <= chars) {
          es[0] = i + 1;
          es[1] = j + 1;
        }
        processIndex(es, chars, engine, indexes, values, &i1);

        int s[2] = {-1, -1};
        if (i + 1 <= lines) {
          s[0] = i + 1;
          s[1] = j;
        }
        processIndex(s, chars, engine, indexes, values, &i1);

        int sw[2] = {-1, -1};
        if (i + 1 <= lines && j - 1 >= 0) {
          sw[0] = i + 1;
          sw[1] = j - 1;
        }
        processIndex(sw, chars, engine, indexes, values, &i1);

        int w[2] = {-1, -1};
        if (j - 1 >= 0) {
          w[0] = i;
          w[1] = j - 1;
        }
        processIndex(w, chars, engine, indexes, values, &i1);

        int wn[2] = {-1, -1};
        if (i - 1 >= 0 && j - 1 >= 0) {
          wn[0] = i - 1;
          wn[1] = j - 1;
        }
        processIndex(wn, chars, engine, indexes, values, &i1);
      }
    }
  }
  for (int i = 0; i < i1; ++i) {
    sum += values[i];
  }
  printf("%d\n", sum);
  return 0;
}
