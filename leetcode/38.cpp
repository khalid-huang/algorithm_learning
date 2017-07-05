#include <iostream>
#include <sstream>
using namespace std;

string int2str(int count) {
  stringstream ss;
  ss << count;
  return  ss.str();
}

string countAndSay(int n) {
  string res = "1", cur;
  int size, count;
  while(--n) {
    size = res.size();
    cur = "";
    for(int i = 0; i < size; i++) {
      count = 1;
      //学习下种循环的方式，利用 res[i] == res[i+1]而不用去预设一个数字
      while(i + 1 < size && res[i] == res[i+1]) {
        ++count;
        ++i;
      }
      cur += int2str(count) + res[i];
    }
    res = cur;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  cout << countAndSay(n) << endl;
}
