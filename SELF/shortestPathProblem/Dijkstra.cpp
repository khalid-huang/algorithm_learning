//用于解决单源最短路径问题，比如顶点1到任何顶点的距离,核心主要是使用贪心策略进行边权拓展，换代更新
#include <iostream>

using namespace std;

int vertexNum, edgeNum; //n表示顶点数，m表示边数
int weights[11][11];
int MAX_VALUE = 999999;

void init() {
  for(int i = 1; i <= vertexNum; i++) {
    for(int j = 1; j <= vertexNum; j++) {
      if(i != j) {
        weights[i][j] = MAX_VALUE;
      } else {
        weights[i][j] = 0;
      }
    }
  }
}

void dijkstra(int dis[], int start) {
  //S集合表示已经放入在标记集合中，Q表示还没有，每次从Q集合中找到一个离start点最近的点。
  int S[11];
  for(int i = 1; i <= vertexNum; i++) {
    dis[i] = weights[start][i];
    S[i] = -1; //表示还没有进入到S集合中
  }

  // int cur = start;
  int min, u;
  S[start] = 1; //标记
  for(int i = 1; i < vertexNum; i++) { //次数
    //在Q集合中找到离start最近的点
    min = MAX_VALUE;
    for(int j = 1; j <= vertexNum; j++) {
      if(S[j] == -1 && min > dis[j]) {
        min = dis[j];
        u = j;
      }
    }

    S[u] = 1;
    cout << "u:" << u << endl;
    //更新权重
    for(int v = 1; v <= vertexNum; v++) {
      if(weights[u][v] < MAX_VALUE) { //防止溢出
        if(dis[v] > dis[u] + weights[u][v]) {
          dis[v] = dis[u] + weights[u][v];
        }
      }
    }
  }
}

int main() {
    cin >> vertexNum >> edgeNum;
    int m = edgeNum;

    init(); //权重无穷大

    int v1, v2, weight;
    while(m--) {
      cin >> v1 >> v2 >> weight;
      weights[v1][v2] = weight;
    }

    int dis[11];
    dijkstra(dis, 1);
    for(int i = 1; i <= vertexNum; i++) {
      cout << dis[i] << " ";
    }
    cout << endl;
}
