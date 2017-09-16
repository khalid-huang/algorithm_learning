//用于解决多源最短路径问题
//算法核心是动态规划，
//D(i,j,k)表示只能使用第1号到第k号点作为中间媒介时，点i到点j之间的最短路径长度
//D(i,j,k) = min(D(i,j,k-1), D(i,k,k-1)+D(j,k,k-1))


//输入格式
//首行输入顶点数n和边数m
//接下来的m是边权信息，[v1, v2, value]表示从v1到v2要花费value
/*
  4,5
  1,2,1
  1,3,2
  1,4,3
  2,3,4
  2,4,1
 */

#include <iostream>

using namespace std;

int d[11][11];
int MAX_VALUE = 10000;
int vertexNum, edgeNum;

void init() {
  for(int i = 1 ;i <= vertexNum; i++) {
    for(int j = 1; j <= vertexNum; j++) {
      d[i][j] = (i == j ? 0 : MAX_VALUE);
    }
  }
}

void FloydWarshall() {
  for(int k = 1; k <= vertexNum; k++) {
    for(int i = 1; i <= vertexNum; i++) {
      for(int j = 1; j <= vertexNum; j++) {
        if(d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
}

void print() {
  for(int i = 1; i <= vertexNum; i++) {
    for(int j = 1; j <= vertexNum; j++) {
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  cin >> vertexNum >> edgeNum;
  init();

  int s, e, w;
  for(int i = 0; i < edgeNum; i++) {
    cin >> s >> e >> w;
    d[s][e] = w;
  }

  FloydWarshall();
  print();
}
