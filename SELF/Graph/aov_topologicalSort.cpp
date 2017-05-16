//拓扑排序，构造AOV网络全部顶点的拓扑有序序列的运算称为拓扑排序；
//AOV网络：可以用有向图来表示一个工程，在这种有向图中，用顶点表示活动，用有向边<u,v>表示活动u必须先于活动v进行，这种有向图叫做顶点表示活动的网络（Activity On Vertices）, 记作AOV网络
//判断有向无环图的方法是对AOV网络构造它的拓扑有序序列。
//拓扑排序实现算法
//1.1）从AOV网络中选择一个入度为0（即没有直接前驱）的顶点并输出
//1.2)从AOV网络中删除该顶点及该顶点发出的所有边
//1.3)重复步骤1.1）和1.2）直至找不到入度为0的顶点
//实现可以使用邻接表加栈的方式


#include <iostream>
#define MAXN 100
using namespace std;

struct ArcNode {
  int to;
  ArcNode* next;
};

int N, M; //N表示顶点数，M表示边数
int count[MAXN]; //用于记录顶点的入度值；当已经入过栈时，将其值置为-1，表示已经输出过
ArcNode* List[MAXN]; //链接表

int TopSort() {
  int stack[N];
  int rsl[N];
  int top = -1, i, topE, rslIndex = 0; //栈顶指针，当top == -1表示栈已空;
  //找入度为0的点
  for(i = 0; i < N; i++) {
    if(count[i] == 0) {
      stack[++top] = i;
      count[i] = -1; //表示已经入过栈
    }
  }
  //对栈进行操作，在栈不为空的情况下每次删除栈顶元素
  ArcNode* tmp;
  while(top != -1) {
    topE = stack[top--]; //出栈
    rsl[rslIndex++] = topE + 1; //记录拓扑排序的输出,要加回1；

    tmp = List[topE];
    while(tmp != NULL) {
      count[tmp->to]--;
      //入栈
      if(count[tmp->to] == 0) {
        stack[++top] = tmp->to;
        count[tmp->to] = -1; //表示已经入过栈
      }
      tmp = tmp->next;
    }
  }

  //输出的排序的个数与顶点数一样时，表示顶点全部输出，无环
  if(rslIndex != N) {
    cout << "网络有环" << endl;
  } else {
    for(i = 0; i < rslIndex; i++) {
      cout << rsl[i]<< " ";
    }
    cout << endl;
  }
}

int main() {
  int ct, from, to;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    count[i] = 0;
  }

  ArcNode* tmp;
  for(int i = 0; i < M; i++) {
    cin >> from >> to;
    from--, to--;
    // count[from]++;
    // tmp = new ArcNode;
    // tmp->to = from;
    // if(List[to] == NULL) {
    //   List[to] = tmp;
    // } else {
    //   tmp->next = List[to];
    //   List[to] = tmp;
    // }
    count[to]++;
    tmp = new ArcNode;
    tmp->to = to;
    if(List[from] == NULL) {
      List[from] = tmp;
    } else {
      tmp->next = List[from];
      List[from] = tmp;
    }
  }

  TopSort();

}
