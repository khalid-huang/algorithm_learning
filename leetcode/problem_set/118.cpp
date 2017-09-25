#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

std::vector<std::vector<int> > generate(int num) {
  std::vector<std::vector<int> > rsl;
  if(num == 0) {
    return rsl;
  } else {
    rsl.push_back(std::vector<int>(1,1));
  }
  std::vector<int> pre;
  for(int i = 1 ;i < num; i++) {
    pre = rsl[i-1];
    std::vector<int> cur;
    for(int j = 0; j <= i; j++) {
      if(j - 1 < 0 || j >= pre.size()) {
        cur.push_back(1);
      } else {
        cur.push_back(pre[j-1] + pre[j]);
      }
    }
    rsl.push_back(cur);
  }
  return rsl;
}

int main() {
  int num;
  cin >> num;
  print(generate(num));
}
