//也是解决单源最短路径问题，但是可以进行处理负权的问题，还可以找出有无成环；
//算法的思路是动态规划进行d(u) = min(d(u), d(v)+w(v,u)); 进行边的拓展

#include <iostream>
using namespace std;

struct Edge {
  int start;
  int end;
  int weight;
};

Edge edges[11];
int vertexNum, edgeNum;
int MAX_VALUE = 100000;
bool isLoopFlag = false;

void print(int distances[]) {
  for(int i = 1; i <= vertexNum; i++) {
    cout << distances[i] << " ";
  }
  cout << endl;
}

void bellmanFord(int distances[], int start) {
  //初始化
  for(int i = 1; i <= vertexNum; i++) {
    distances[i] = MAX_VALUE;
  }
  distances[start] = 0;
  //拓展的次数最多就是vertexNum - 1; 最多每个点都走一次嘛;
  int times = vertexNum - 1;

  // print(distances);

  for(int i = 1; i <= times; i++) {
    for(int j = 1; j <= edgeNum; j++) {
      if(distances[edges[j].end] > edges[j].weight + distances[edges[j].start]) {
        distances[edges[j].end] = edges[j].weight + distances[edges[j].start];
      }
    }

    // print(distances);

  }

  //判断是否成环
  for(int i = 1; i <= edgeNum; i++) {
    if(distances[edges[i].end] > edges[i].weight + distances[edges[i].start]) {
      isLoopFlag = true;
    }
  }
}


int main() {

  cin >> vertexNum >> edgeNum;

  int start, end, weight;
  for(int i = 1; i <= edgeNum; i++) {
    cin >> start >> end >> weight;
    edges[i].start = start;
    edges[i].end = end;
    edges[i].weight = weight;
  }

  int distances[vertexNum];
  int startPoint;
  // cin >> startPoint; //开始顶点
  startPoint = 1;
  bellmanFord(distances, startPoint);
  if(isLoopFlag) {
    cout << "图中成环" << endl;
  } else {
    print(distances);
  }

}
