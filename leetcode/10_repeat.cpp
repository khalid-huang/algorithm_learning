#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
  int size_s = s.size(), size_p = p.size();

  int f[size_s+1][size_p+1];
  int j = 1;
  f[0][0] = 1;
  while(p[j] == '*') {
    f[0][j+1] = 1;
    j += 2;
  }

  for(int i = 1; i <= size_s; i++) {
    for(int j = 1; j <= size_p; j++) {
      if(p[j-1] == '*') {
        f[i][j] = f[i][j-2] || ((s[i-1] == p[j-2] || p[j-2] == '.') && f[i-1][j]);
      } else {
        f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
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
