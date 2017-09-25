#include <iostream>
#include <vector>

using namespace std;

//首先一个是方向问题，一个是边缘问题
std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
  if(matrix.empty()) {
    return {};
  }
  int m = matrix.size();
  int n = matrix[0].size();
  std::vector<int> rsl(m*n,0);

  int col = 0, row = 0, k = 0; //当前的位置
  int up = 0, down = m - 1, left = 0, right = n -1; //边界控制
  while(true) {
    //向右
    for(col = left; col <= right; col++) {
      rsl[k++] = matrix[up][col];
    }
    if(++up > down) break;

    //向下
    for(row = up; row <= down; row++) {
      rsl[k++] = matrix[row][right];
    }
    if(--right < left) break;

    //向左
    for(col = right; col >= left; col--) {
      rsl[k++] = matrix[down][col];
    }
    if(--down < up) break;

    //向上
    for(row = down; row >= up; row--) {
      rsl[k++] = matrix[row][left];
    }
    if(++left > right) break;
  }
  return rsl;
}

int main() {

}
