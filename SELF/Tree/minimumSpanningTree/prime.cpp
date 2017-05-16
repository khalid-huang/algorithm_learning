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

//Prime算法里面维护了两个集合，一个T集合，一个是T'集合，T集合表示当前生成树顶点的集合；而T’集合表示不属于当前生成树的顶点集合
void Prime(int start) {
  int lowest[N+1]; //存放顶点集合T'内各顶点到顶点集合T内各顶点权值最小的边的权舆
  int fromvex[N+1]; //记录顶点集合T‘内各顶点距离顶点集合T内哪个顶点最近；当fromvex[i] = -1时表示顶点i已经在集合T中；这个集合的重要主要是用于标记已访问和生成最小生成树的具体边信息
  int minsum = 0, v, min;
  //初始化
  for(int i = 1; i <= N; i++) {
    lowest[i] = edges[start][i];
    fromvex[i] = start; //一开始只有start点有T中，所以所有的fromvex都来自start
  }

  fromvex[start] = -1; //标记start已经在集合T中
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

      //这里根据找到的v还可以判断是否最小生成树是唯一的；策略是
      //1）已经找到了min = lowest[v],因此待拓展的点是v，待拓展的边是(fromvex[v],v);接下来我们只要判断在集合T中是否还存在其他点到v的距离等于lowest[v]
      for(int j = 1; j <= N; j++) {
        if(fromvex[j] == -1 && lowest[v] == edges[v][j] && fromvex[v] != j) {
          cout << endl << "生成的最小生成树不唯一" << endl;
          cout << j << "->" << v << "和" << fromvex[v] << "->" << v << "有一样的效果" << endl << endl;
        }
      }
      //根据最近点v更新信息；
      fromvex[v] = -1; //將v加入到T中
      for(int j = 1; j <= N; j++) {
        if(fromvex[j] != -1 && lowest[j] > edges[v][j]) {
          lowest[j] = edges[v][j]; //更新最近距离的值
          fromvex[j] = v; //更新来源点
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
  Prime(start);
}
