#include <iostream>
#include <vector>

using namespace std;

void nullifyRow(std::vector<std::vector<int> >& matrix, int i, int rows, int cols) {
  for(int j = 0; j < cols; j++) {
    matrix[i][j] = 0;
  }
}

void nullifyCol(std::vector<std::vector<int> >& matrix, int j, int rows, int cols) {
  for(int i = 0; i < rows; i++) {
    matrix[i][j] = 0;
  }
}

//想法是将除第一列和第一行的0信息注入到第一列和第一行，然后使用这些信息进行更新，这样是反正重复；然后针对第一列和第一行的零信息，放到最后进行更新。https://leetcode.com/problems/set-matrix-zeroes/#/discuss
void setZeroes(std::vector<std::vector<int> >& matrix) {
  if(matrix.size() == 0) {return;}
  int rows = matrix.size(), cols = matrix[0].size();
  int colsHasZero = 0, rowsHasZero = 0;
  //存储第一列和第一行是否有零的信息
  for(int i = 0; i < rows; i++) {
    if(matrix[i][0] == 0) {
      colsHasZero = 1;
      break;
    }
  }

  for(int j = 0; j < cols; j++) {
    if(matrix[0][j] == 0) {
      rowsHasZero = 1;
      break;
    }
  }

  for(int i = 1; i < rows; i++) {
    for(int j = 1; j < cols; j++) {
      if(matrix[i][j] == 0) {
        matrix[i][0] = matrix[0][j] = 0;
      }
    }
  }
  for(int i = 1; i < rows; i++) {
    if(matrix[i][0] == 0) {
      nullifyRow(matrix, i, rows, cols);
    }
  }
  for(int j = 1; j < cols; j++) {
    if(matrix[0][j] == 0) {
      nullifyCol(matrix, j, rows, cols);
    }
  }
  //
  if(rowsHasZero == 1) {
    nullifyRow(matrix, 0, rows, cols);
  }
  if(colsHasZero == 1) {
    nullifyCol(matrix, 0, rows, cols);
  }
}



int main() {
  std::vector<std::vector<int> > matrix(3);
  setZeroes(matrix);
  // print(matrix);
}
