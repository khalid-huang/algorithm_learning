//最优三角剖分，主要是使用了最优子结构的思想
//http://blog.csdn.net/pi9nc/article/details/9750091
//动态方程为t[i][j]表示从{Vi-1, Vi,...,Vj}的最优解，也就是权值最小；
//动态方程为t[i][j] = 0 if i == j;
//动态方程为t[i][j] = min{t[i][k] + t[k+1][j] + weight(Vi-1VkVj), i<=k<j}

#include <iostream>
#define MAXN 6 //最大的顶点数是为7

using namespace std;

int weight[][MAXN] = {{0,2,2,3,1,4},{2,0,1,5,2,3},{2,1,0,2,1,4},
    {3,5,2,0,6,2},{1,2,1,6,0,1},{4,3,4,2,1,0}};//凸多边形的权值矩阵，MAXN个点会有MAXN条边，包括到自己的一条边；数组里面的第一个数组表示V0到其他顶点的距离
int s[MAXN][MAXN]; //用来路径追踪的，打印出有哪些边；S[i][j] = k表示{Vi-1...Vj}这个剖分的点是在k
int t[MAXN][MAXN]; //用来记录最优子结构，t[i][j]表示{Vi-1...Vk}的最优三角剖分；而最后的结果就是t[1][MAXN-1];

int getWeight(int i, int k, int j) {
  return weight[i][k] + weight[k][j] + weight[i][j];
}

int minWeightTriangulation() {
  for(int i = 1; i <= MAXN; i++) {
    t[i][i] = 0;
  }
  for(int r = 2; r <= MAXN; r++) { //r表示链长，如V0V1V2的链长为2
    for(int i = 1; i < MAXN - r + 1; i++) { // i + r - 1 <= MAXN
      int j = i + r - 1; //因为i是代表了i-1的;r是长度的，所以i = 1, r = 2时，长度为2,只需要j = i + r - 1 = 2就可以了。
      //初始化：k = i时
      t[i][j] = t[i+1][j] + getWeight(i-1,i,j);
      s[i][j] = i; //划分点为i

      for(int k = i + 1; k < j; k++) {
        //将链ij划分为ik和k+1j再加上ikj的权重
        int u = t[i][k] + t[k+1][j] + getWeight(i-1, k, j);
        if(u < t[i][j]) {
          t[i][j] = u;
          s[i][j] = k;
        }
      }
    }
  }
  return t[1][MAXN - 1];
}

void Traceback(int vi, int vj) {
  if(vi == vj) return;
  Traceback(vi, s[vi][vj]);
  cout << "三角部分顶点：V" << vi - 1 << ", V" << s[vi][vj] << ", V" << vj << endl;
  Traceback(s[vi][vj] + 1, vj);
}

int main() {
  cout << "此多边形的最优三角剖分的值为:" << minWeightTriangulation() << endl;
  cout << "最优级三角剖分的结构为：" << endl;
  Traceback(1,MAXN-1); //表示从V0到V5的最优结构
}
