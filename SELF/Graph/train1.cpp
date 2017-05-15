//《图论算法理论，实现及应用》
#include <iostream>
#include <queue>
using namespace std;

#define MAX 200
#define INF 1000000

struct Point {
  int x, y; //位置
  int step; //到达这个位置花的步数
  int time; //到达这个位置花的时间
  Point () {}
  Point (int xt, int yt, int stept, int timet) {
    x = xt;
    y = yt;
    step = stept;
    time = timet;
  }
};

int N, M;
int mintime[MAX][MAX];
char map[MAX][MAX];
int sx, sy, ex, ey;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
queue<Point> q;

int bfs(Point start) {
  //初始化工作
  int i, j, nx, ny;
  for(i = 0; i < N; i++) {
    for(j = 0; j < M; j++) {
      mintime[i][j] = INF;
    }
  }

  mintime[start.x][start.y] = start.time;
  q.push(start);
  Point p;
  while(!q.empty()) {
    // cout << q.size() << endl;
    p = q.front();
    q.pop();

    for(i = 0; i < 4; i++) {
      nx = p.x + dir[i][0];
      ny = p.y + dir[i][1];
      if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
        continue;
      }
      if(map[nx][ny] != '#') {
        Point tmp(nx, ny, p.step+1, p.time+1);
        if(map[nx][ny] == 'x') {
          tmp.time = tmp.time + 1;
        }
        if(mintime[nx][ny] > tmp.time) {
          mintime[nx][ny] = tmp.time;
          q.push(tmp);
        }
      }
    }
  }
  return mintime[ex][ey];
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
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> map[i][j];
      if(map[i][j] == 'r') {
        // cout << sx << sy << endl;
        sx = i;
        sy = j;
      } else if(map[i][j] == 'a') {
        ex = i;
        ey = j;
      }
    }
  }

  // printGraph();
  Point start(sx, sy, 0, 0);
  cout << "sx-sy " << sx << "-" << sy << " ;ex-ey " << ex << "-" << ey << endl;
  int rsl = bfs(start);
  if(rsl == INF) {
    cout << "无穷地狱啊" << endl;
  } else {
    cout << "营救成功，get" << endl;
    cout << rsl << endl;
  }
}
