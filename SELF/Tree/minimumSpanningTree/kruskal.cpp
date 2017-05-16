//Kruskal算法的参考：http://128kj.iteye.com/blog/1705936 和 http://blog.csdn.net/dellaserss/article/details/7724401


//涉及到并查集；
#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
  int start;
  int end;
  int weight;
};

int vertexNum, edgeNum;
Edge edges[11];
int father[11];
int son[11];

int cmp(const Edge& a, const Edge& b) {
  if (a.weight < b.weight) {
    return 1;
  } else {
    return 0;
  }
}


//并查集查找根结点
int unionsearch(int x) {
  return (x == father[x]) ? x : unionsearch(father[x]);
}

//对两个点进行连接，同时进行路径压缩，压缩的策略是谁的儿子数多；
bool join(int u, int v) {
  int fu = unionsearch(u);
  int fv = unionsearch(v);
  if(fu == fv) {
    return false;
  }
  //进行连接; 连接的规划是谁的儿子数多，谁老大(扁平化了)
  if(son[fu] > son[fv]) {
    father[fv] = fu; //将fu作为fv的父节点
    son[fu] += son[fv]; //更新fu的儿子数
  } else {
    father[fu] = fv;
    son[fv] += son[fu];
  }
  return true;
}

void Kruskal() {
  //初始化工作
  for(int i = 0; i < vertexNum; i++) {
    father[i] = i; //自己作为自己的父节点；表示根结点
    son[i] = 1;//一开始的儿子数为1;
  }


  int sum = 0;
  int curEdges = 0;
  sort(edges, edges+edgeNum, cmp); //对边进行排序

  for(int i = 0; i < edgeNum; i++) {
    if(join(edges[i].start, edges[i].end)) {
      curEdges = curEdges + 1;
      sum += edges[i].weight;
      cout << edges[i].start << " -> " << edges[i].end << ": " << edges[i].weight << endl;
    }
    if(curEdges == vertexNum - 1) {
      break;
    }
  }
  cout << sum << endl;
}

int main() {
  cin >> vertexNum >> edgeNum;

  int s, e,w;
  for(int i = 0; i < edgeNum; i++) {
    cin >> s >> e >> w;
    Edge eg = {s, e, w};
    edges[i] = eg;
  }

  Kruskal();
}
