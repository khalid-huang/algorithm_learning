//用于解决单源最短路径问题，比如顶点1到任何顶点的距离,核心主要是使用贪心策略进行边权拓展，换代更新
//算法步骤
//1.1）设置两个顶点的集合T和S
//  S中存放已找到最短路径的顶点，初始时，S上只有一个顶点，即源点
//  T中存在当前还未找到最短路径的点
//1.2）在T集合中选取当前长度最短的一条路径（v0,..,vk)，从而将vk加入到顶点集合S上，并根据(v0,..,vk)这一最短路径修改源点v0到T中各顶点的最短路径长度，重复这一步骤，直到所有的顶点都加入到集合S中，算法结束

/*
输入
6 9
0 2 5
0 3 30
1 0 2
1 4 8
2 5 7
2 1 15
4 3 4
5 3 10
5 4 18
输出
20  0->2->1
5  0->2
22 0->2->5->3
28 0->2->1->4
12 0->2->5
 */
#include <iostream>
using namespace std;

#define MAXM 100
#define MAXN 50
#define INF 10000

int N, M;
int edges[MAXN][MAXN];
int S[MAXN]; //S集合，S[i] = 1表示顶点i已经找到到源点的最短距离
int path[MAXN]; //路径记录集合；path[3] = 4表示在源点到3顶点这条最短路径上，3的前一个顶点是4,可以通过反向搜索找到整条路径
int dist[MAXN]; //记录每个顶点到源点的距离

void printDist() {
  for(int i = 0; i < N; i++) {
    cout << dist[i] << " ";
  }
  cout << endl;
}

void Dijkstra(int start) {
  //初始化
  for(int i = 0; i < N; i++) {
    S[i] = 0;
    dist[i] = edges[start][i];
    if(dist[i] < INF && i != start) {
      path[i] = start; //如果从源点到i有路径的话，就先设置前置点
    } else {
      path[i] = -1;
    }
  }
  S[start] = 1; //源点标记在S集合中
  dist[start] = 0;
  printDist();
  for(int i = 1; i < N; i++) { //将剩下的n-1个点加入到S集合中
    //从集合T中找到集合S中最短路径
    int min = INF, u = -1;
    for(int j = 0; j < N; j++) {
      if(S[j] != 1 && min > dist[j]) {
        min = dist[j];
        u = j;
      }
    }
    // cout << "u " << u << endl;
    S[u] = 1; //将u加入到集合S中
    //根据顶点u更新path和dist
    for(int j = 0; j < N; j++) {
      if(S[j] != 1 && edges[u][j] < INF && dist[j] > dist[u] + edges[u][j]) {
        path[j] = u;
        dist[j] = dist[u] + edges[u][j];
      }
    }
    // printDist();
  }
}

void print() {
  int p, cur;
  int temp[N];
  for(int i = 1; i < N; i++) {
    cout << dist[i] << "   ";
    for(int j = 0; j < N; j++) {
      temp[j] = 0;
    }

    p = path[i];
    cur = 0;
    temp[cur++] = i; //放入终点
    while(p != -1) {
      temp[cur++] = p;
      p = path[p];
    }
    for(int j = cur-1; j > 0; j--) {
      cout << temp[j] << "->";
    }
    cout << temp[0];
    cout << endl;
  }
}

void printGraph() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  cin >> N >> M;

  // 初始化
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
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
    edges[s][e] = w;
  }
  // printGraph();

  int start = 0;
  Dijkstra(start);
  //打印信息
  print();
}
