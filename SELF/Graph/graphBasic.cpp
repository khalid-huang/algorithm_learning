#define MAXN 100

struct ArcNode { //边结点
  int adjvex; //邻接点
  ArcNode *nextarc; //指向下一个边结点的指针
};

struct Vnode { //顶点
  int data; //顶点信息
  ArcNode *head1; //出边表的表头指针
  ArcNode *head2; //入边表的表头指针
};

//图的邻接表存储结构
struct LGraph {
  VNode vertex[MAXN]; //顶点数组
  int vexnum, arcnum; //顶点数和弧数
}

/*
输入的格式为
vertexNum edgeNum
1 2
2 2
4 4
...
 */
//有向图
LGraph lg;
void createLG() {
  cin >> lg.vexnum >> lg.arcnum;
  int v1, v2;
  ArcNode *pi;
  for(int i = 0; i < lg.arcnum; i++) {
    cin >> v1 >> v2;
    v1--; //数组从0开始
    v2--;
    //v1到v2
    pi = new ArcNode;
    pi->adjvex = v2;
    pi->nextarc = lg.vertex[v1].head1; //新增加的都直接接入到头结点之后就可以了
    lg.vertex[v1].head1 = pi;
    //v2到v1
    pi = new ArcNode;
    pi->adjvex = v1;
    pi->nextarc = lg.vertex[v2].head2;
    lg.vertex[v2].head2 = pi;
  }
}


//图的遍历方式(对于不同的题目，入栈，入队列的条件并不一定是一样的，可以根据实际情况进行判断，有时相同的点因为状态不同也可以再次入栈或再次入队列的)
//1)深度优先算法（DFS）
//1.1）邻接表存储图信息的情况下，伪码如下
DFS(顶点 i) {
  visited[i] = 1;
  p = 顶点i的边链表表头指针;
  while(p 不为空) {
    //设指针p所指向的边结点所表示的边中，另一个顶点为顶点j
    if(顶点j未访问过) {
      //递归搜索前的准备工作写这里
      DFS(顶点j);
      //以下是DFS的回退位置，在很多应用中需要在这里写代码; //恢复现场的代码
    }
    p = p->nextarc; //移向下一个边结点
  }
}


//1.2)邻接矩阵存储图(看train1代码)
DFS(顶点 i) {
  visited[i] = 1;
  for(j = 0; j < n; j++) {
    if(Edge[i][j] == 1 && !visited[j]) {
      //递归搜索前的准备工作
      DFS(j);
      //以下是DFS的回退位置，在很多应用中需要在这里写代码 //恢复现场的代码
      //以下是DFS的回退位置，在很多应用中需要在这里写代码
    }
  }
}

//2)广度优先搜索
//2.1)邻接表存储图
BFS(顶点i) {
  visited[i] = 1;
  將顶点i入队列;
  while(队列不为空){
    取出队列头，设为k
    p = 顶点k的边链表表头指针
    while(p不为空) {
      设指针p指向的边结点所表示的边的另一个顶点为顶点j
      if(顶点j未访问过) {
        visited[j] = 1;
        將顶点j入队列
      }
      p = p->nextarc;
    }
  }
}
//2.2)邻接矩阵存储图
BFS(顶点i) {
  visited[i] = 1;
  将顶点i入队列;
  while(队列不为空) {
    取出队列头设为k
    for(j = 0; j < n; j++) {
      if(Edge[k][j] == 1 && !visited[j]) {
        visited[j] = 1;
        j入队列
      }
    }
  }
}


//3）搜索的一些策略
//3.1）方向 int dir[4][2] = {{-1,0},{0,1}}, {1,0}, {0.-1}}
//3.2）深度优先算法里面的奇偶剪枝策略，首先明白一个策略的原理：在搜索的过程中，不管有多少障碍，不管绕多少路，只要能达到目的，走过的距离中好日子短距离的奇偶性是一致的。因为走过的距离=最短距离+偶数（不管怎么绕路，回到原来的路上，都要偶数步），所以就有最短距离：abs(x-ex)+abs(y-ey)和实际还需要的步数t之间满足t-(abs(x-ex)+abs(y-ey)) > 0而且差是一个偶数
//


//4）c++经验：
//4.1)c++是没有数组越界的概念的，因为它的计算方式，map[-1][-2]也是合理的
