//http://blog.csdn.net/liufeng_king/article/details/8500084
//最长公共子序列问题，可以直接参考博客的内容，很详细

#include <iostream>

using namespace std;

int max(int v1, int v2) {
  return v1 >= v2 ? v1 : v2;
}

void get_LCS(int **c, int pos1, int pos2, string s1, string s2, string& rsl) {
  if(pos1 == 0 || pos2 == 0) {
    return;
  }
  // if(c[pos1][pos2] == c[pos1-1][pos2-1]+1) { //使用这种方式的话，会出现一个问题，就是针对bccdef和bcdef的情况，结果为ccdef,应该使用s1[pos1]==s2[pos2]这种更强的约束来进行
  if(s1[pos1] == s2[pos2]) {
    get_LCS(c, pos1-1, pos2-1, s1, s2, rsl);
    rsl = rsl + s1[pos1];
  } else if(c[pos1-1][pos2] >= c[pos1][pos2-1]) {
    get_LCS(c, pos1-1, pos2, s1, s2, rsl);
  } else {
    get_LCS(c, pos1, pos2-1, s1, s2, rsl);
  }
}

string LCS(string s1, string s2) {
  int size1 = s1.size(), size2 = s2.size();

  //下面的方式要学习,直接传递静态二维数组的话，需要第二维的信息
  //多给出两个空位是为了方便递推
  s1 = " " + s1;
  s2 = " " + s2;
  int **c = new int *[size1+1];
  for(int i = 0; i <= size1; i++) {
    c[i] = new int[size2+1];
  }
  //动态规划开始
  c[0][0] = 0;
  for(int i = 1; i <= size1; i++) {
    c[i][0] = 0;
  }
  for(int i = 1; i <= size2; i++) {
    c[0][i] = 0;
  }

  for(int i = 1; i <= size1; i++) {
    for(int j = 1; j <= size2; j++) {
      if(s1[i] == s2[j]) {
        c[i][j] = c[i-1][j-1] + 1;
      } else {
        c[i][j] = max(c[i][j-1], c[i-1][j]);
      }
    }
  }

  for(int i = 0; i <= size1; i++) {
    for(int j = 0; j <= size2; j++) {
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
  string rsl;
  get_LCS(c, size1, size2, s1, s2, rsl);
  cout << c[size1][size2] << endl;
  // for(int i = size1, j = size2; i >= 1 && j >= 1;) {
  //   if(s1[i] == s2[j]) {
  //     cout << s1[i];
  //     i--;
  //     j--;
  //   } else {
  //     if(c[i][j-1] > c[i-1][j]) {
  //       j--;
  //     } else {
  //       i--;
  //     }
  //   }
  // }
  // cout << endl;
  return rsl;
}

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  string rsl = LCS(s1, s2);
  cout << rsl << endl;
}
