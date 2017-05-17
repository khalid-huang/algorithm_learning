//判断最小生成树是否唯一的算法
//1.1）对图中的每条边，扫描其他他，如果存在相同权值的边，则对该边进行标记
//1.2）然后用kruskal算法求MST
//1.3）求得MST后，如果该MST中未包含作了标记的边，即可判定MST唯一，如果含作了标记的边，则依次去掉这些边再求MST，如果求得的MST权值和原MST的权值一样，即可判定MST不唯一
/*
输入
7 10
1 2 28
1 4 22
1 6 10
2 3 16
2 7 14
3 4 12
4 5 22
4 7 18
5 6 25
5 7 24
输出
MST唯一
96

输入
7 12
1 2 6
1 6 6
1 7 6
2 3 2
2 7 3
3 4 3
3 7 2
4 5 1
4 7 4
5 6 8
5 7 3
6 7 7
输出
MST不唯一
20
 */


#include <iostream>
#include <algorithm>
using namespace std;

#define MAXM 100 //最大的边数
#define MAXN 50
int n, m;

struct Edge {
  int start;
  int end;
  int weight;
  int del; //边是否删除的标记; 0表示没有删除，1表示已经删除
  int used; //判定是否在第一次使用kruskal算法时被包含在最小生成树中；0表示没有使用，1表示已经使用
  int equal; //是否存在相同权值的边；0表示没有存在相同的边，1表示存在相同的边
};

Edge edges[MAXM];
int first = 0;
int one = 1;
int father[MAXN];
int son[MAXN];

int cmp(const Edge& e1, const Edge& e2) {
  if(e1.weight < e2.weight) {
    return 1;
  } else {
    return 0;
  }
}

int unionsearch(int p) {
  return p == father[p] ? p : unionsearch(father[p]);
}

bool join(int p1, int p2) {
  int f1 = unionsearch(p1);
  int f2 = unionsearch(p2);

  if(f1 == f2) {
    return false;
  }
  if(son[f1] > son[f2]) {
    father[f2] = f1;
    son[f1] += son[f2];
  } else {
    father[f1] = f2;
    son[f2] += son[f1];
  }
  return true;
}

//返回MST的权值
int kruskal() {
  //初始化
  for(int i = 0; i < m; i++) {
    father[i] = i;
    son[i] = 1;
  }

  int curEdgeNum = 0;
  int sum = 0;
  for(int i = 0; i < m; i++) {
    if(edges[i].del == 1) {
      continue; //忽略这条边
    }
    if(join(edges[i].start, edges[i].end)) {
      curEdgeNum++;
      sum += edges[i].weight;
      if(first == 1) {
        edges[i].used = 1;
      }
    }
    if(curEdgeNum == n - 1) {
      break;
    }
  }
  return sum;
}

int main() {
  //处理输入
  cin >> n >> m;
  int s, e, w;
  for(int i = 0; i < m; i++) {
    cin >> s >> e >> w;
    edges[i].start = s; edges[i].end = e; edges[i].weight = w;
    edges[i].del = 0; edges[i].used = 0; edges[i].equal = 0;
  }
  //标记相同权值的边
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < m; j++) {
      if(edges[i].weight == edges[j].weight && i != j) {
        edges[i].equal = 1;
      }
    }
  }
  //进行判定
  int weight1, weight2;
  sort(edges, edges+m, cmp);
  first = 1; //标记是第一次使用kruskal
  weight1 = kruskal();
  first = 0; //标记非每一次使用kruskal
  for(int i = 0; i < m; i++) {
    if(edges[i].used == 1 && edges[i].equal == 1) {
      edges[i].del = 1;
      weight2 = kruskal();
      edges[i].del = 0;
      //MST不唯一
      if(weight1 == weight2) {
        one = 0;
        break;
      }
    }
  }
  if(one) {
    cout << "MST唯一" << endl;
    cout << weight1 << endl;
  } else {
    cout << "MST不唯一" << endl;
    cout << weight1 << endl;
  }
}
