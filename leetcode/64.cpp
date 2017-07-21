#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void print(std::vector<std::vector<int> >& grid) {
  int size = grid.size();
  for(int i = 0; i < size; i++) {
    int size_i = grid[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int getMin(int row, int col, std::vector<std::vector<int> >& grid) {
  int temp = 0;
  if(row - 1 >= 0) {
    temp = grid[row-1][col];
  }
  if(col - 1 >= 0 && (temp == 0 || temp > grid[row][col-1])) {
    temp = grid[row][col-1];
  }
  return temp;
}

int minPathSum(vector<vector<int> >& grid) {
  int m = grid.size();
  int n = grid[0].size();
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n;j++) {
      grid[i][j] = grid[i][j] + getMin(i, j, grid);
    }
  }
  print(grid);
  return grid[m-1][n-1];
}

int main() {
  std::vector<std::vector<int> > grid;
  std::vector<int> v1(3,0);
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 4;
  std::vector<int> v2(3,0);
  v2[0] = 3;
  v2[1] = 1;
  v2[2] = 5;
  std::vector<int> v3(3,0);
  v3[0] = 7;
  v3[1] = 2;
  v3[2] = 5;
  grid.push_back(v1);
  grid.push_back(v2);
  grid.push_back(v3);
  cout << minPathSum(grid) << endl;
}
