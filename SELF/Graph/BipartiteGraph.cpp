// https://www.renfei.org/blog/bipartite-matching.html
// https://www.byvoid.com/zhs/blog/hungary
//主要参考 图论算法理论，实现及应用 （王桂平。。。）

/*
输入的格式为
  nx, ny, edgesNum; //x集合的顶点数和y集合的顶点数，边数
  x1 y1     //表示x1->y1有边
  ....
3 4 6
0 1
0 2
1 1
2 0
2 2
2 3
 */

//二分图的最大匹配算法是匈牙利算法，在对每个x集合的点进行寻找匹配点时，都使用搜索（广度或是深度）算法来查找增广路，找到增广路就可以进行拓展了

#include <iostream>
#define MAX_VERTEX 10 //x集合和y集合最大的顶点数
using namespace std;

int g[MAX_VERTEX][MAX_VERTEX]; //初始化为0，g[x][y] = 1表示x有一条到y的边
int nx, ny; //x集合的顶点数和y集合的顶点数
int edgesNum;

//dfs使用
int mx[MAX_VERTEX], my[MAX_VERTEX]; //初始化为-1; mx[i]表示最大匹配中与xi匹配的y顶点
int visit[MAX_VERTEX]; //用于在每轮查找增广路时记录集合y顶点的访问状态;

//bfs使用
int pred[MAX_VERTEX]; //用于记录交错轨的，同时也用来记录y集合中的顶点是否遍历过;
int queue[MAX_VERTEX]; //实现BFS搜索用到的队列; 用数组模拟即可


void init() {
  for(int i = 0; i < MAX_VERTEX; i++) {
    mx[i] = -1;
    my[i] = -1;
  }
}

//从集合x里面的u顶点出发寻找增广路
int dfs(int u) {

  for(int v = 0; v < ny; v++) {
    if(g[u][v] && !visit[v]) { //如果一个点标记的是已访问，对于本论增广来说，是不用再访问一次的，因为访问过程的可能性有做为增广点加入，或是查明没有办法从当前点对这个y点进行增广，无论哪种都不需要再进行一次访问的
      // cout << "u:v " << u << ":" << v  << endl;
      visit[v] = 1;
      //如果找到的y顶点是一个未匹配点或者是y已加经匹配，但从当前y顶点的匹配点可以找到一条增广路(也就是另一个匹配路径)，就把uv这条边加入最大匹配图中；并返回1表示找到增广路(加1)
      if(my[v] == -1 || dfs(my[v])) {
        my[v] = u;
        mx[u] = v;
        return 1;
      }
    }
  }
  return 0;//从u出发没有找到增广路；
}

//使用深度优先搜索增广的匈牙得算法
int MaxMatch_DFS() {
  int rsl = 0; //表示最大匹配数是多少
  for(int i = 0; i < nx; i++) {
    if(mx[i] == -1) { //从每个未盖点出发进行使用深度优先搜索寻找增广路
      //对于新一轮的增广路查找，初始化访问集合y顶点的状态数组，0表示未访问，1表示已访问
      for(int j = 0; j < MAX_VERTEX; j++) {
        visit[j] = 0;
      }
      rsl += dfs(i);
    }
  }
  return rsl;
}

//使用广度优先搜索增广的匈牙得算法
int MaxMatch_BFS() {
  int rsl = 0;
  int cur, tail, y;
  for(int u = 0; u < nx; u++) {
    //只对未匹配对进行增广
    if(mx[u] != -1) {
      continue;
    }
    for(int j = 0; j < ny; j++) {
      pred[j] = -2; //pred初始化，-2表示初始值，-1代表已经j已经匹配；大于-1表示交错轨上的点,比如-2 -1 1 -2;表示y集合中第一个点和最后一个点还是未匹配状态，第二个点和第三个点是当前增广路上的y点，在目前的最大匹配图中，第二个点已经匹配了，但是新的增广路将把第三个点连上第二个点的匹配点，而第二个点（-1）将与当前遍历的x顶点相连; 一条匹配边变成了两条
    }
    cur = tail = 0; //队列初始化
    //bfs开始
    for(int v = 0; v < ny; v++) {
      if(g[u][v]) {
        pred[v] = -1; //表示v点已经遍历到
        queue[tail++] = v; //加入队列中；这个就是bfs与dfs的区别所在
      }
    }
    while(cur < tail) {
      y = queue[cur];
      if(my[y] == -1) {
        break; //找到未匹配点，则找到了一条交错轨
      }
      cur++;
      //y已经匹配给了my[y],把my[y]的邻接点都加入队列中，尝试找增广路
      for(int j = 0; j < ny; j++) {
        if(g[my[y]][j] && pred[j] == -2) {//有邻接点，而且未遍历到
          pred[j] = y; //记录交错轨，用于下面更新交错轨的状态（回溯）
          queue[tail++] = j; //入队列
        }
      }
    }
    if(cur == tail) {
      continue; // 没有找到交错轨
    }
    //更改交错轨上的匹配状态
    while(pred[y] > -1) {
      //要将新找到的未匹配点匹配给前面一个已经匹配的x; 也就是y与my[pred[j]]
      mx[my[pred[y]]] = y;
      my[y] = my[pred[y]];
      y = pred[y];
    }
    my[y] = u;
    mx[u] = y;
    rsl++;
  }
  return rsl;
}

void printGraph() {
  for(int i = 0; i < MAX_VERTEX; i++) {
    for(int j = 0; j < MAX_VERTEX; j++) {
      cout << g[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {

  //处理输入
  cin >> nx >> ny >> edgesNum;
  int x, y;
  for(int i = 0; i < edgesNum; i++) {
    cin >> x >> y;
    g[x][y] = 1;
  }

  // printGraph();

  //进行最大匹配
  init();
  cout << MaxMatch_DFS() << endl;

  init();
  cout << MaxMatch_BFS() << endl;
}
