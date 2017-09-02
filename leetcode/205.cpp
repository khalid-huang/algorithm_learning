#include <iostream>

using namespace std;

bool isIsomophic(string s, string t) {
  //char只有256; 只要对应的值相同就可以了
  int m1[256] = {0}, m2[256] = {0}, size = s.size();
  for(int i = 0; i < size; i++) {
    if(m1[s[i]] != m2[t[i]]) {
      return false;
    }
    m1[s[i]] = i + 1; //避免与初始值一样
    m2[t[i]] = i + 1;
  }
  return true;
}

int main() {
  string s = "agg", t = "kmm";
  cout << isIsomophic(s, t) << endl;
}
