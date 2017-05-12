#include <iostream>
#define MAX_VERTEX 10
#define INF 100000

using namespace std;

struct Edge {
  int c;
  int f;
};

int vertexNum, edgesNum;
Edge edges[MAX_VERTEX][MAX_VERTEX];
int flag[MAX_VERTEX];
int prev[MAX_VERTEX];
int alpha[MAX_VERTEX];
int queue[MAX_VERTEX];

int min(int v1, int v2) {
  return v1 > v2 ? v2 : v1;
}

int abs(int v) {
  return v > 0 ? v : -v;
}

int ford() {
  int qs, qe, v;
  while(1) {
    for(int i = 0; i < vertexNum; i++) {
      flag[i] = -1;
      prev[i] = -1;
      alpha[i] = -1;
    }

    qs = qe = 0;

    flag[0] = 0;
    prev[0] = 0;
    alpha[0] = INF;
    queue[qe++] = 0;
    while(qs < qe && flag[vertexNum - 1] == -1) {
      v = queue[qs];
      qs++;
      //找出 v的所有邻接点,并加入队列
      for(int i = 0; i < vertexNum; i++) {
        if(flag[i] == -1) {
          if(edges[v][i].c < INF && edges[v][i].f < edges[v][i].c) {
            flag[i] = 0;
            prev[i] = v;
            alpha[i] = min(alpha[v], edges[v][i].c - edges[v][i].f);
            queue[qe++] = i;
          } else if(edges[i][v].c < INF && edges[i][v].f > 0) {
            flag[i] = 0;
            prev[i] = -v;
            alpha[i] = min(alpha[v], edges[i][v].f);
            queue[qe++] = i;
          }
        }
      }
      flag[v] = 1;
    }
    if(flag[vertexNum - 1] == -1 || alpha[vertexNum - 1] == 0) {
      break;
    }
    int k1 = vertexNum - 1, k2 = abs(prev[k1]);
    int a = alpha[k1];
    while(1) {
      if(edges[k2][k1].f < INF) {
        edges[k2][k1].f = edges[k2][k1].f + a;
      } else {
        edges[k1][k2].f = edges[k1][k2].f - a;
      }
      if(k2 == 0) {
        break;
      }
      k1 = k2;
      k2 = abs(prev[k2]);
    }
  }
  int maxFlow = 0;
  for(int i = 0; i < vertexNum; i++) {
    for(int j = 0; j < vertexNum; j++) {
      if(i == 0 && edges[i][j].f < INF) {
        maxFlow += edges[i][j].f;
      }
      if(edges[i][j].f < INF) {
        cout << i << "->" << j << ":" << edges[i][j].f << endl;
      }
    }
  }
  return maxFlow;
}

int main() {
  cin >> vertexNum >> edgesNum;
  for(int i = 0; i < vertexNum; i++) {
    for(int j = 0; j < vertexNum; j++) {
      edges[i][j].c = INF;
      edges[i][j].f = INF;
    }
  }
  int u, v ,c, f;
  for(int i = 0; i < edgesNum; i++) {
    cin >> u >> v >> c >> f;
    edges[u][v].c = c;
    edges[u][v].f = f;
  }

  cout << ford() << endl;
}
