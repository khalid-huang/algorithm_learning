//关于顶点与索引的关系，以后都默认把0索引不使用
/*
输入
7 9
1 2 28
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
输出
1 6 10
6 5 25
5 4 22
4 3 12
3 2 16
2 7 14
最小生成树权重和：99
 */
#include <iostream>
#define MAXN 11
#define INF 10000

using namespace std;

int N, M; //顶点数和边数
int edges[MAXN][MAXN]; //邻接矩阵

void Prime(int start) {
  int lowest[N+1];
  int fromvex[N+1];
  int minsum = 0, v, min;
  for(int i = 1; i <= N; i++) {
    lowest[i] = edges[start][i];
    fromvex[i] = start;
  }

  fromvex[start] = -1;
  for(int i = 1; i < N; i++) { //将剩下的N-1个点都加入到T集合中，只需要N-1步就可以了
    //找出集合T中到T'集合最近的点
    v = -1, min = INF;
    for(int j = 1; j <= N; j++) {
      if(fromvex[j] != -1 && min > lowest[j]) {
        v = j;
        min = lowest[j];
      }
    }

    if(v != -1) {
      //根据最近点进行更新
      //打印找到的边; 累加最小生成树的和
      cout << fromvex[v] << "->" << v << ": " << lowest[v] << endl;
      minsum += lowest[v];

      fromvex[v] = -1;
      for(int j = 1; j <= N; j++) {
        if(fromvex[j] != -1 && lowest[j] > edges[v][j]) {
          lowest[j] = edges[v][j];
          fromvex[j] = v;
        }
      }
    } else {
      cout << "该图没有生成树" << endl;
      return;
    }
  }
  cout << "最小生成树的权重和: " << minsum << endl;
}

int main() {
  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(i == j) {
        edges[i][j] = 0;
      } else {
        edges[i][j] = INF;
      }
    }
  }

  int s, e, w;
  for(int i = 0; i < M; i++) {
    cin >> s >> e >> w;
    edges[s][e] = edges[e][s] = w;
  }
  int start = 1;
  // Prime(start);
  Prime1(start);
}
