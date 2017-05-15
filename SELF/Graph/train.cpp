//《图论算法理论，实现及应用》p30

#include <iostream>
using namespace std;

int N, M, T;
int sx, sy, ex, ey;
char map[9][9];
bool escape = false;
int dir[4][2] = {{-1,0}, {1, 0}, {0, 1}, {0,-1}};

int abs(int v) {
  return v > 0 ? v : -v;
}

void dfs(int x, int y, int t) {
  //成功判断
  if(x == ex && y == ey && t == T) {
    escape = true;
    return;
  }
  //剪枝
  int temp = (T - t) - abs(x - ex) - abs(y - ey);
  if(temp < 0 || temp & 1 == 1) {
    return;
  }

  int nx, ny;
  for(int i = 0; i < 4; i++) {
    nx = x + dir[i][0];
    ny = y + dir[i][1];
    if(nx < 0 || ny < 0 || nx > N || ny > M) {
      continue;
    }
    if(map[nx][ny] != 'X') {
      map[nx][ny] = 'X';
      dfs(nx, ny, t+1);
      map[nx][ny] = '.';
    }
  }
}

void printGraph() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  cin >> N >> M >> T;
  int x, y;
  char s;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> map[i][j];
      if(map[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if(map[i][j] == 'D') {
        ex = i;
        ey = j;
      }
    }
  }

  printGraph();
  map[sx][sy] = 'X'; //统一符号
  dfs(sx, sy, 0);
  if(escape == true) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
