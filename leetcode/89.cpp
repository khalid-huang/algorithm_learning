//这种就是找规律，一般就是迭代或直接映射

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

//可以发现是有规律的，n的数字是在n-1的基础上再加上往其全部的逆序数字前面都上1
std::vector<int> grayCode(int n) {
  std::vector<int> rsl;
  rsl.push_back(0);
  for(int i = 0; i < n; i++) {
    int size  = rsl.size();
    for(int j = size - 1; j > -1; j--) {
      rsl.push_back(rsl[j] | 1 << i);
    }
  }
  return rsl;
}

int main() {
  int n;
  cin >> n;
  print(grayCode(n));
}
