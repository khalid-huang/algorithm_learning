#define MAX 80
int father[MAX]; //father[x]表示x的父节点
int rankArr[MAX]; //rank[x]表示x的秩；用来确定合并策略的

//初始化
int makeSet(int x) {
  //赋值可以根据实际情况变动
  father[x] = x;
  rankArr[x] = 0;
}

//查找x所在的集合
int findSet(int x) {
  if(x != father[x]) {
    father[x] = findSet(father[x]); //这个回溯时，还进行了路径压缩
  }
  return father[x];
}

//按秩进行合并x,y所在的集合; 连接的策略都要按实际情况来
void unionSet(int x, int y) {
  x = findSet(x);
  y = findSet(y);
  if(rankArr[x] > rankArr[y]) {
    father[y] = x;
  } else if(rankArr[x] == rankArr[y]) {
    father[x] = y;
    rankArr[y]++;
  } else {
    father[x] = y;
  }
}
