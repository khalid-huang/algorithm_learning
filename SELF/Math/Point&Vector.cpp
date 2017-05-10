//利用旋转角来判断:https://segmentfault.com/a/1190000004457595
// 由点 A，B，C，D 计算出向量 AC，AD，BC，BD
// 计算 sin(<AC, AD>) * sin(<BC, BD>) 和 sin(<CA, CB>) * sin(<DA, DB>)，若皆为非正数，则相交；否则，不相交。
//对于OA=（x1, y1）, OB=(y1, y2); sin(<OA, OB>)的符号，只需要判断x1*y2 - x2 *y1的符号即可，两都是一样报的；因为 叉乘公式有|a×b| = |a|*|b|*sin<a, b>；但这里需要用到sin的方向和正负，其正负与a×b的方向是一样的；

//如果向量是二维的(e. g. a = (ax, by) , b = (bx, by) )，那么
//a x b = ax * by - ay * bx = |a| * |b| * sin<a, b>
//可以用来判断两条线段之间的夹角是顺时针还是逆时针的
#include <iostream>
using namespace std;

int MAX_VALUE = 10000;

struct Point {
  int x;
  int y;
};

struct Vector {
  int x;
  int y;

  Vector(Point A, Point B) {
    x = B.x - A.x;
    y = B.y - A.y;
  }

  Vector() {

  }
};

//显示函数
void printGrapham(int top, int stackRsl[], Point points[]) {
  for(int i = 0; i <= top; i++) {
    cout << "(" <<points[stackRsl[i]].x << ", " << points[stackRsl[i]].y <<  ")  ";
  }
  cout << endl;
}

void printPoints(int vertexNum, Point points[]) {
  for(int i = 0; i < vertexNum; i++) {
    cout << "(" <<points[i].x << ", " << points[i].y <<  ")  ";
  }
  cout << endl;
}

void printStack(int top, int stackRsl[], Point points[]) {
  for(int i = 0; i <= top; i++) {
    cout << "(" <<points[stackRsl[i]].x << ", " << points[stackRsl[i]].y <<  ")  ";
  }
  cout << endl;
}

//行列式的计算：http://www.cnblogs.com/AndyJee/p/3491487.html

//计算两个二维向量的叉乘
int vector_product(Vector a, Vector b) {
  return a.x * b.y - b.x * a.y;
}

//计算p1p2, p3p4的叉乘
int vector_product_using_point(Point p1, Point p2, Point p3, Point p4) {
  Vector v1(p1, p2), v2(p3, p4);
  return vector_product(v1, v2);
}

//求两点的距离平方
double pointDistSquare(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

//判断AB与CD是否相交
//只需判断sin<AC， AD> * sin<BC, BD> 与sin<CA, CB> * sin<DA, DB>是否都小于0即可；
//也就是(AC×AD) * (BC×BD)的正负和(CA×CB)*(DA, DB)的正负
//叉乘的正负计算为OA(x1, y1), OB(x2,y2) ==> OA×OB = x1* y2 - y1 * x2;
//判断两个二维线段是否相交
bool isIntersected(Point A, Point B, Point C, Point D) {
  Vector AC(A, B);
  Vector AD(A, D);
  Vector BC(B, C);
  Vector BD(B, D);
  Vector CA(C, A);
  Vector CB(C, B);
  Vector DA(D, A);
  Vector DB(D, B);
  int flag1 = vector_product(AC, AD) * vector_product(BC, BD);
  int flag2 = vector_product(CA, CB) * vector_product(DA, DB);
  if(flag1 < 0 && flag2 < 0) {
    return true;
  } else {
    return false;
  }
}

//判断一个点P3是是直线p1p2的左边还是右边; 用三阶行列式，如果大于0的话在左边，小于0的话在右边
//http://blog.csdn.net/bone_ace/article/details/46239187
//直接使用点的方式1表示左边，-1表示右边, 0表示同一直线
int leftOrRightPoint(Point p1, Point p2, Point p3) {
  int flag = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y - p1.x * p3.y - p2.x* p1.y - p3.x * p2.y;
  if (flag > 0) {
    return 1;
  } else if(flag < 0) {
    return -1;
  } else {
    return 0;
  }
}
//使用向量的方式；只要判断p1p2与p2p3的旋转角就可以了，如果旋转角是逆时针(大于0)的话，就是左边；是顺时针的话，就是右边
int leftOrRightPointUsingVector(Vector p1p2, Vector p2p3) {
  int flag = vector_product(p1p2, p2p3);
  if(flag > 0) {
    return 1;
  } else if(flag < 0){
    return -1;
  } else {
    return 0;
  }
}

//凸包问题
//算法步骤：http://blog.csdn.net/Bone_ACE/article/details/46239187
//算法实现：http://mrknight.info/job/algorithm/2015/10/20/convex-hull/

//从小到大排列，排列的规则是：
//1）选择纵坐标最小的点，如果纵坐标一样，选择横坐标较小的点作为第一个点p0; 对接下来的点做比较
//2）选择与p0的同幅角小的点在前面，如果幅角一样，选择距离p0近的点；幅角的比较是用sin<p1p2, p1p3> > 0的话，就表示
//p2的幅角小于p3; 也就是p3在p1p2的逆时针方向；
void grahamSort(Point points[], int vertexNum) {
  //查找第一点
  Point minPoint = {MAX_VALUE, MAX_VALUE};
  int minInd;
  for(int i = 0; i < vertexNum; i++) {
    if(minPoint.y > points[i].y) {
      minPoint = points[i];
      minInd = i;
    } else if(minPoint.y == points[i].y && minPoint.x > points[i].x) {
      minPoint = points[i];
      minInd = i;
    }
  }

  Point temp;
  points[minInd] = points[0];
  points[0] = minPoint;

  //对剩下的点进行排序
  Vector temp1, temp2;
  for(int i = 1; i < vertexNum - 1; i++) {
    for(int j = 1; j < vertexNum - i; j++) {
      temp1.x = points[0].x - points[j].x;
      temp1.y = points[0].y - points[j].y;

      temp2.x = points[0].x - points[j+1].x;
      temp2.y = points[0].y - points[j+1].y;
      //交换的条件是temp1与temp2的旋转角是顺时针或是另一个是旋转角为0而且p0p1的距离大于p0p2
      if(vector_product(temp1, temp2) < 0 || (vector_product(temp1, temp2) == 0 &&
        pointDistSquare(points[0], points[j]) > pointDistSquare(points[0], points[j+1]))) {
          temp = points[j];
          points[j] = points[j+1];
          points[j+1] = temp;
      }
    }
  }
}

//在算法步骤里面，作者第四步写错了，不应该是P0与栈顶点而是栈顶点的下一个点和栈顶点
void Graham(int vertexNum, int stackRsl[], Point points[], int& top) {
  cout << "排序前" << endl;
  printPoints(vertexNum, points);
  grahamSort(points, vertexNum);
  cout << "排序后" << endl;
  printPoints(vertexNum, points);
  //将p0, p1进栈
  for(int i = 0; i < 2; i++) {
    stackRsl[i] = i;
  }
  //扫描查找剩下的凸包上的点；使用的策略是栈顶点与最接近栈顶点的点(stackRsl[top-1])的向量与栈顶点与测试点的旋转角如果是逆时针的话，就入栈，如果是同一直线或是顺时针就出栈。
  top = 1; //栈顶指针
  for(int i = 2; i < vertexNum; i++) {
    while(top && vector_product_using_point(points[top-1], points[top], points[top], points[i]) <= 0) {
      --top; //出栈
    }
    stackRsl[++top] = i; //进栈
    printStack(top, stackRsl, points);
  }
  cout << "top " << top << endl;
}

//利用叉乘来计算多边形的面积
//不用理化叉乘的正负，这样可以兼容凹多边形的情况
//http://www.cnblogs.com/TenosDoIt/p/4047211.html


//叉乘,sin判断旋转角:sin的符号与叉乘的符号是一致的
//若 direct(a, b) 为逆时针，则 0 <= <a, b> <= 180，从而 sin<a, b> >= 0。
//若 direct(a, b) 为顺时针，则 180 <= <a, b> <= 360，从而 sin<a, b> <= 0。

int main() {
  // Point A, B, C, D;
  // cin >> A.x >> A.y;
  // cin >> B.x >> B.y;
  // cin >> C.x >> C.y;
  // cin >> D.x >> D.y;
  Point A = {-2, 1};
  Point B = {4, 0};
  Point C = {0, 0};
  Point D = {2, 5};
  int flag1;
  if(isIntersected(A, C, B, D)) { //判断AB,CD是否相交
    cout << "AC与BD相交" << endl;
  } else {
    cout << "AC与BD不相交" << endl;
  }

  flag1 = leftOrRightPoint(A, B, D);
  // Vector v1(A, B), v2(B, D);
  // flag1 = leftOrRightPointUsingVector(v1, v2);
  if(flag1 > 0) {
    cout << "D点在AB的左边" << endl;
  } else if(flag1 < 0) {
    cout << "D点在AB的右边" << endl;
  } else {
    cout << "D点在AB上" << endl;
  }

  //凸包，graham Scan解决凸包问题
  Point E = {1, 1};
  Point F = {1, 2};
  Point G = {2, 2};
  Point points[7] = {A, B, C, D, E, F, G};
  int vertexNum = 7;
  int stackRsl[7];
  int top;
  Graham(vertexNum, stackRsl, points, top);
  printGrapham(top, stackRsl, points);
}
