//Prime算法呢，主要是使用贪心的策略； 更新的策略是使用lowest数组进行更新，这个数组表示VNew集合到邻接点最近的距离；
/*
假设数组如下：
5 8
1 2 1
1 3 1
1 4 2
2 3 2
3 4 3
3 5 2
2 5 5
4 5 1
一开始curPoint = 1;标记点1为已访问； lowest = [0,1,1,2,inf]
得到最小的非Vnew点为2点；curPoint = 2；标记点2为已访问 ；更新 lowest = [0 1 1 2 5]
得到最小的非Vnew点为3；curPoint = 3; 标记点3为已访问；更新Lowest = [0 1 1 2 4]
*/
#include <iostream>
using namespace std;

int weights[11][11];
int vertexNum; int edgeNum;
int MAX_VALUE = 100000;

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

void prime(int start) {
  int visit[vertexNum+1];
  int lowest[vertexNum+1];
  //初始化
  int curPoint = start;
  for(int i = 1; i <= vertexNum; i++) {
    visit[i] = -1;
    lowest[i] = weights[start][i];
  }
  visit[curPoint] = 1; //标记curPoint已经访问

  //找出剩下的vertexNum - 1个点；通过不断更新lowest来获取结果
  int min;
  for(int i = 1; i < vertexNum; i++) {
    //（打印更新情况）
    for(int k = 1; k <= vertexNum; k++) {
      cout << lowest[k] << " ";
    }
    cout << endl;

    //找出Lowest里面距离V最近的点
    min = MAX_VALUE;
    for(int j = 1; j <= vertexNum; j++) {
      if(visit[j] == -1 && min > lowest[j]) {
        min = lowest[j];
        curPoint = j;
      }
    }
    visit[curPoint] = 1; //标记当前点已访问
    //根据curPoint更新lowest数组
    for(int j = 1; j <= vertexNum; j++) {
      if(visit[j] == -1 && lowest[j] > weights[curPoint][j]) {
        lowest[j] = weights[curPoint][j];
      }
    }
  }

  //计算最小生成树的权重和
  int sum = 0;
  for(int i = 1; i <= vertexNum; i++) {
    sum += lowest[i];
  }
  cout << sum << endl;
}

int main() {
  cin >> vertexNum >> edgeNum;
  int s, e, w;

  init();
  for(int i = 0; i < edgeNum; i++) {
    cin >> s >> e >> w;
    weights[s][e] = w;
    weights[e][s] = w;
  }

  int start = 1;
  prime(start);
}
