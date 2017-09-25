#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int> > v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    int size_i = v[i].size();
    for(int j = 0; j < size_i; j++) {
        cout << v[i][j] << ", ";
    }
    cout << endl;
  }
}


std::vector<std::vector<int> > generateMatrix(int n) {
  //初始化二维vector
  std::vector<std::vector<int> > rsl;
  for(int i = 0; i < n; i++) {
    std::vector<int> vct(n, 0);
    rsl.push_back(vct);
  }

  int left = 0, right = n-1, up = 0, down = n -1;
  int val = 1, row = 0, col = 0;
  while(true) {
    //向右
    for(col = left; col <= right; col++) {
      rsl[up][col] = val;
      ++val;
    }
    if(++up > down) break;

    //向下
    for(row = up; row <= down; row++) {
      rsl[row][right] = val;
      ++val;
    }
    if(--right < left) break;

    //向左
    for(col = right; col >= left; col--) {
      rsl[down][col] = val;
      ++val;
    }
    if(--down < up) break;

    //向上
    for(row = down; row >= up; row--) {
      rsl[row][left] = val;
      ++val;
    }
    if(++left > right) break;
  }
  return rsl;
}



int main() {
  int n = 3;
  print(generateMatrix(3));
}
