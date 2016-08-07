#include <cstdio>
#include <unistd.h>
#define SIZE 8
#define DRC  4
#define DEV  2
int a[SIZE][SIZE];
int l = 0; int x = 4; int y = 4; int d = 0;
int m[DRC][DEV];

void print() {
  while(l) { printf("\b\r"); --l; }
  for(int i = 0; i < SIZE; ++i) {
    for(int j = 0; j < SIZE; ++j) {
      printf("%d", a[i][j]);
    }
    printf("\n"); ++l;
  }
}

int main() {
  // test();
  m[0][0] = -1; m[0][1] =  0;
  m[1][0] =  0; m[1][1] =  1;
  m[2][0] =  1; m[2][1] =  0;
  m[3][0] =  0; m[3][1] = -1;
  for(int i = 0; i < SIZE; ++i) { for(int j = 0; j < SIZE; ++j) { a[i][j] = 0; } }
  while(1) {
    print();
    sleep(1);
    a[x][y] = !a[x][y];
    if(a[x][y]) {
      d = (d + 1) % DRC;
    } else {
      d = (d + DRC - 1) % DRC;
    }
    x = (x + SIZE + m[d][0]) % SIZE;
    y = (y + SIZE + m[d][1]) % SIZE;
  }
  return 0;
}
