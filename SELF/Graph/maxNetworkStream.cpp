//网络最大流问题
//以下是使用一般增广路方法（Ford-Fulkerson算法）
//寻找增广路和改进网络流的方法为标号法
//参考《图论算法理论,实现及应用》

//以下代码适用于初始流为零流和非零流的情况

/*
输入格式
  顶点数 边数
  v1 v2 容量 流量
  ....

例子
6 10
0 1 8 2
0 2 4 3
1 3 2 2
1 4 2 2
2 1 4 2
2 3 1 1
2 4 4 0
3 4 6 0
3 5 9 3
4 5 7 2
 */

#include <iostream>
#define MAX_VERTEX 10
#define INF 100000 //无穷大

using namespace std;

struct Edge {
  int c; //容量
  int f; //流量
};

int vertexNum, edgesNum;
Edge edges[MAX_VERTEX][MAX_VERTEX];
int flag[MAX_VERTEX]; //顶点状态， -1表示未标号，0表示已标号未检查，1表示已标号已检查;
int prev[MAX_VERTEX]; //标号的第一个分量：指明标号来自哪个顶点，以便找出可改进量
int alpha[MAX_VERTEX]; //标号的第二个分量：可改进量
int queue[MAX_VERTEX]; //队列 ，用于BFS算法
int qs, qe; //队列头位置和队尾位置


int abs(int v) {
  return v > 0 ? v : -v;
}

int min(int v1, int v2) {
  return v1 < v2 ? v1 : v2;
}

void print(int flag[], int vertexNum) {
  cout << "print flag" << endl;
  for(int i = 0; i < vertexNum; i++) {
    cout << flag[i] << " ";
  }
  cout << endl;
}

//本身是一个广度优先算法
int ford() {
  int v, i, j; //v表示队列头元素
  //一直循环，直到找不到增广路
  while(1) {
    //进行一轮标号
    //初始化
    for(i = 0; i < vertexNum; i++) {
      flag[i] = -1;
      prev[i] = -1;
      alpha[i] = -1;
    }
    qs = qe = 0; //队列初始化
    flag[0] = 0;
    prev[0] = 0;
    alpha[0] = INF;
    queue[qe++] = 0; //源点进入;
    //当队列为空或是汇点已经标号时，当前论迭代结束
    while(qs < qe && flag[vertexNum-1] == -1) {
      v = queue[qs];
      qs++;
      //检查v所有的未标号的邻接点，对其标号
      for(i = 0; i < vertexNum; i++) {
        if(flag[i] == -1) {
          //正向弧且未満
          if(edges[v][i].c < INF && edges[v][i].f < edges[v][i].c) {
            flag[i] = 0; //已标号，未检查
            prev[i] = v;
            alpha[i] = min(alpha[v], edges[v][i].c - edges[v][i].f);
            queue[qe++] = i;
          }
          //反射弧且有流量
          else if(edges[i][v].c < INF && edges[i][v].f > 0) {
            flag[i] = 0;
            prev[i] = -v; //-v表示反向弧
            alpha[i] = min(alpha[v], edges[i][v].f);
            queue[qe++] = i;
          }
        }
      }
      flag[v] = 1; //顶点v已检查
    }

    //如果当前论标号没有到达终点的路径或是到达了但改进量为0，就表示找不到可改进的增广路，算法退出
    if(flag[vertexNum-1] == -1 || alpha[vertexNum-1] == 0) {
      break;
    }

    //根据标号情况，使用可改进量和反向路径回溯进行修改流量
    int k1 = vertexNum - 1, k2 = abs(prev[k1]);
    int a = alpha[vertexNum-1]; //可改进量
    while(1) {
      if(edges[k2][k1].f < INF) {//正向弧
        edges[k2][k1].f = edges[k2][k1].f + a;
      } else {
        edges[k1][k2].f = edges[k1][k2].f - a;
      }
      //如果已经到源点，更新完成;
      if(k2 == 0) {
        break;
      }
      k1 = k2;
      k2 = abs(prev[k2]);
    }
    print(flag, vertexNum);
  }

  int maxFlow = 0;
  for(int i = 0; i < vertexNum; i++) {
    for(int j = 0; j < vertexNum; j++) {
      if(i == 0 && edges[i][j].f < INF) {
        maxFlow += edges[i][j].f;
      }
      if(edges[i][j].f < INF) {
        cout << i << "->" << j << ": " << edges[i][j].f << endl;
      }
    }
  }
  // cout << "MaxFlow: "<< maxFlow << endl;
  return maxFlow;
}

int main() {
  //初始化弧
  cin >> vertexNum >> edgesNum;
  for(int i = 0; i < vertexNum; i++) {
    for(int j = 0; j < vertexNum; j++) {
      edges[i][j].c = INF;
      edges[i][j].f = INF;
    }
  }
  int u, v, c, f; //起点，终点，容量，流量
  for(int i = 0; i < edgesNum; i++) {
    cin >> u >> v >> c >> f;
    edges[u][v].c = c;
    edges[u][v].f = f;
  }
  cout << ford() << endl; //标号法求最大网络流
}
