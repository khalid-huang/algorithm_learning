//http://blog.csdn.net/runninghui/article/details/8895586
//是bellmanFord的一种队列优化，在松弛的时候不是使用盲目的松弛v次，而是只对邻接点进行松弛

//SPFA 在形式上和BFS非常类似，不同的是BFS中一个点出了队列就不可能重新进入队列，但是SPFA中 
//一个点可能在出队列之后再次被放入队列，也就是一个点改进过其它的点之后，过了一段时间可能本 
//身被改进，于是再次用来改进其它的点，这样反复迭代下去。 
 
//判断有无负环：如果某个点进入队列的次数超过V次则存在负环（SPFA无法处理带负环的图）

/*
输入:
4 6
0 1 1
0 2 3
0 3 2
1 2 1
1 3 1
2 3 1
 */

#include <iostream>
#include <queue>
#define INF 10000
#define MAX_VERTEX 10

using namespace std;

int vertexNum, edgesNum;
int g[MAX_VERTEX][MAX_VERTEX];

void SPFA(int dis[], int start) {
  queue<int> q;
  int visited[vertexNum];
  int num[vertexNum];
  for(int i = 0; i < vertexNum; i++) {
    visited[i] = 0; //未访问过
    num[i] = 0; //顶点i进入过队列的次数
    dis[i] = INF; //初始化为无穷大
  }

  //源点
  q.push(start);
  dis[start] = 0;
  visited[start] = 1;
  num[start] = 1;
  int p;
  while(!q.empty()) {
    p = q.front();
    q.pop();
    for(int i = 0; i < vertexNum; i++) {
      if(dis[p] + g[p][i] < dis[i]) {
        dis[i] = dis[p] + g[p][i];
        if(!visited[i]) {
          q.push(i);
          num[i]++;
          if(num[i] > vertexNum) {
            cout << "存在负环"<< endl;
            return;
          }
          visited[i] = 1;
        }
      }
    }
    visited[p] = 0;
  }
}

int main() {
  cin >> vertexNum >> edgesNum;
  for(int i = 0; i < vertexNum; i++) {
    for(int j = 0; j < vertexNum; j++) {
      if(i == j) {
        g[i][j] = 0;
      } else {
        g[i][j] = INF;
      }
    }
  }
  int s, e, v;
  for(int i = 0; i < edgesNum; i++) {
    cin >> s >> e >> v;
    g[s][e] = v;
  }
  int distances[vertexNum];
  SPFA(distances, 0);
  for(int i = 0; i < vertexNum; i++) {
    cout << distances[i] << " ";
  }
  cout << endl;
}
