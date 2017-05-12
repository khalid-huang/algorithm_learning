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
