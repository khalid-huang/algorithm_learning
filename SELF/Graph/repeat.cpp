#include <iostream>
#define MAX_VERTEX 10
using namespace std;

int nx, ny, edgesNum;
int g[MAX_VERTEX][MAX_VERTEX];
int mx[MAX_VERTEX], my[MAX_VERTEX];
int visit[MAX_VERTEX];

int dfs(int u) {
  for(int v = 0; v < ny; v++) {
    if(g[u][v] && !visit[v]) {
      visit[v] = 1;
      if(my[v] == -1 || dfs(my[v])) {
        my[v] = u;
        mx[u] = v;
        return 1;
      }
    }
  }
  return 0;
}

int MaxMatch_DFS() {
  //初始化
  for(int i = 0; i < MAX_VERTEX; i++) {
    mx[i] = -1;
    my[i] = -1;
  }
  int rsl = 0;

  for(int u = 0; u < nx; u++) {
    if(mx[u] == -1) {
      for(int j = 0; j < MAX_VERTEX; j++) {
        visit[j] = 0;
      }
      rsl += dfs(u);
    }
  }

  return rsl;
}

int queue[MAX_VERTEX];
int pred[MAX_VERTEX];
int MaxMatch_BFS() {
  int cur, tail, y, rsl = 0;
  for(int i = 0; i < MAX_VERTEX; i++) {
    mx[i] = -1;
    my[i] = -1;
  }

  for(int u = 0; u < nx; u++) {
    if(mx[u] != -1) {
      continue;
    }
    for(int j = 0; j < MAX_VERTEX; j++) {
      pred[j] = -2;
    }

    cur = tail = 0;
    for(int v = 0; v < ny; v++) {
      if(g[u][v]) {
        pred[v] = -1;
        queue[tail++] = v;
      }
    }
    while(cur < tail) {
      y = queue[cur];
      if(my[y] == -1) {
        break;
      }
      cur++;
      for(int j = 0; j < ny; j++) {
        if(g[my[y]][j] && pred[j] == -2) {
          pred[j] = y;
          queue[++tail] = j;
        }
      }
    }
    if(cur == tail) {
      continue;
    }
    //这一步画一个pred的迭代过程就可以明白了
    while(pred[y] > -1) {
      mx[my[pred[y]]] = y;
      my[y] = my[pred[y]];
      y = pred[y];
    }
    my[y] = u;
    mx[u] = y;
    rsl++;
  }
  return rsl;
}

int main() {
  cin >> nx >> ny >> edgesNum;
  int x, y;
  for(int i = 0; i < edgesNum; i++) {
    cin >> x >> y;
    g[x][y] = 1;
  }

  // cout << MaxMatch_DFS() << endl;
  cout << MaxMatch_BFS() << endl;
}
