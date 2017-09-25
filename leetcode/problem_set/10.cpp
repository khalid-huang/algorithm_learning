//可以多打几次这个代码

//学习如何设计这种递归思想
//https://leetcode.com/problems/regular-expression-matching/#/solutions
//链接里面的代码蛮好的
#include <iostream>
using namespace std;

bool isMatch1(string s, string p) {
  if(p.empty()) {
    return s.empty();
  }

  if(p.size() >= 2 && '*' == p[1]) {
    //带有星号的情况，就是第一种取0个数的情况，或是第二种，一个字符一个字符地吃，要求要不是相等要不就是'.'
    return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
  } else {
    return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
  }
}

bool isMatch(string s, string p) {
  //f[i][j] = 1表示s[0,...,i-1]与p[0,...,j-1]相匹配；而f[0][0]就表示s与p都是空的也匹配，记住是空的，不是说s和p只有一个字符，当只有一个字符的，应该是f[1][1];
  int size_s = s.size(), size_p = p.size();
  int f[size_s][size_p];
  //初始化
  f[0][0] = true;
  for(int j = 1; j < size_p; j++) {
    f[0][j] = '*' == p[j] && f[0][j-2];
  }

  for(int i = 1; i <= size_s; i++) {
    for(int j = 1; j <= size_p; j++) {
      if(p[j-1] != '*') {
        f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || '.' == p[j-1]);
      } else {
        //=f[i][j-2]表示*取0次后面的表示取了一次,往前进了一次
        f[i][j] = f[i][j-2] || （(s[i-1] == p[j-2] || '.' == p[j-2]) && f[i-1][j]）;
      }
    }
  }
  return f[size_s][size_p];
}

int main() {
  string s, p;
  cin >> s >> p;
  cout << isMatch(s, p) << endl;
}
