//最长回文子串的问题，下面的做法比较好，使用中心扩展的方式；初始化的时候，

#include <iostream>
#define MAXN 1000

using namespace std;

bool p[MAXN][MAXN] = {false}; //p[i][j] = 1表示从i到j是回文； 0表示不是回文

void print(int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      cout << p[i][j] << " ";
    }
    cout << endl;
  }
}

string longestPalindrome(string s) {
  size_t size = s.size();
  if(size == 0) {
    return "";
  }
  int maxlen = 1, down = 0, up = 0, i, j;
  //初始化；有两种可能性，一种是单独一个字母也是回文， 一种是bb也是初始化的回文
  for(i = 0; i < size; i++) {
    p[i][i] = true;
    j = i + 1;
    if(j < size && s[i] == s[j]) {
      p[i][j] = true;
      if(maxlen < 2) {
        maxlen = 2;
        down = i;
        up = j;
      }
    }
  }

  // print(size);

  int len, length = size;
  //以长度做为约束，表示一个down后，up就自然可以表示了
  for(len = 3; len <= length; len++) {
    for(i = 0; i <= length - len; i++) {
      j = len + i - 1;
      // cout << i << "-" << j << endl;
      // cout << p[i+1][j-1] << endl;
      if(p[i+1][j-1] && s[i] == s[j]) {
        p[i][j] = p[i+1][j-1];
        if(maxlen < len) {
          // cout << "ok: " << len << endl;
          maxlen = len;
          down = i;
          up = j;
        }
      }
    }
  }
  return s.substr(down,maxlen);
}

int main() {
  string s = "c";
  cout << longestPalindrome(s) << endl;
}
