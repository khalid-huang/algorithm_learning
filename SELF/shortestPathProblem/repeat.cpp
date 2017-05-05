int vertexNum;
int weights[vertexNum];
int MAX_VALUE;

void dijkstra(int dis[], int start) {
  //初始化dis[]数组和S数组标记
  int S[vertexNum];
  for(int i = 1; i <= vertexNum; i++) {
    dis[i] = weights[start][i];
    S[i] = -1;
  }

  S[start] = 1;
  for(int i = 1; i < vertexNum; i++) { //次数
    //找出最近点
    int mix = MAX_VALUE;
    int u;
    for(int j = 1; j <= vertexNum; j++) {
      if(S[j] == -1 && min > dis[j]) {
        min = dis[j];
        u = j;
      }
    }

    S[u] = 1;
    //更新权重
    for(int v = 1; v <= vertexNum; v++) {
      if(weights[u][v] < MAX_VALUE) {
        if(dis[v] > dis[u] + weights[u][v]) {
          dis[v] = dis[u] + weights[u][v];
        }
      }
    }
  }
}
