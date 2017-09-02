#include <iostream>
#include <vector>

using namespace std;


void dfs(int row, int col, std::vector<std::vector<char> >& grid) {
  if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') {
    return;
  }
  grid[row][col] = '0';
  dfs(row-1,col, grid);
  dfs(row+1,col,grid);
  dfs(row, col-1, grid);
  dfs(row, col+1, grid);
}

int numIslands(std::vector<std::vector<char> >& grid) {
  int answer = 0;
  int rows = grid.size();
  if(rows == 0) {
    return answer;
  }

  int cols = grid[0].size();
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(grid[i][j] == '1') {
        dfs(i,j,grid);
        answer++;
      }
    }
  }
  return answer;
}

int main() {

}
