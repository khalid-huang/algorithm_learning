//记忆化搜索是一种剪枝的操作，可以用于深度优先搜索里面，可以参考 http://www.cnblogs.com/fu11211129/p/4276213.htm

//下面主要以滑雪来做一个示范
/*
输入
4 4
1 2 3 4
1 2 3 5
3 2 4 6
10 9 8 7
 */

//下面的代码带在visited的注释的作用是改变题意，表示当h[x][y] == h[x1][y1]时也可以运动，而原本的题意是不可以的；这里面主要会有一个反复访问的问题
#include <iostream>
#define MAXN 50

using namespace std;

int R, C;
int dp[MAXN][MAXN];
int h[MAXN][MAXN];
int visited[MAXN][MAXN];
int dir[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0, 1}}; // 表示四个方向汇过来

int dfs(int x, int y) {
  if(dp[x][y] != 0) {
    return dp[x][y];
  }
  // visited[x][y] = 1; //visted
  int max = 0, temp, nx, ny;
  for(int i = 0; i < 4; i++) {
    nx = x + dir[i][0];
    ny = y + dir[i][1];
    // if(nx >= 0 && nx < R && ny >= 0 && ny < C && h[x][y] <= h[nx][ny] && visited[nx][ny] == 0) { //visited
    if(nx >= 0 && nx < R && ny >= 0 && ny < C && h[x][y] < h[nx][ny]) {
      // cout << x << "-" << y << ": " << h[x][y] << endl;
      cout << nx << "-" << ny << ": " << h[nx][ny] << endl;
      temp = dfs(nx, ny);
      // cout << temp;
      max = temp > max ? temp : max;
    }
  }
  dp[x][y] = max + 1;
  // visited[x][y] = 0; //visited
  return dp[x][y];
}

int main() {
  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> h[i][j];
      dp[i][j] = 0;
      visited[i][j] = 0;
    }
  }

  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cout << h[i][j] << " ";
    }
    cout << endl;
  }

  int max = -1, temp;;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      temp = dfs(i, j);
      max = max > temp ? max : temp;
    }
  }
  cout << max << endl;
}
