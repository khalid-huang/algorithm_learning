#include <iostream>
#include <vector>

using namespace std;

void backTrack(int& num, std::vector<int>& tempVector, int n, int row) {
  if(row == n) {
    num++;
    return;
  }
  //为row行放置皇后,可能的情况有n列，所有列都有可能
  int i, j;
  for(i = 0; i < n; i++) {
    //保证当前放置的不会跟前面有冲突
    for(j = 0; j < row; j++) {
      if(tempVector[j] == i || (j - row == tempVector[j] - i || j - row == i - tempVector[j])) {
        break;
      }
    }
    //没有冲突，成功
    if(j == row) {
      tempVector[row] = i;
      backTrack(num, tempVector, n, row+1);
      //这里本来是要回溯一下的，但是tempVector[row]是直接修改的，所以就不用回溯了
      //实际就是tempVector[row] = 0;
    }
  }
}

int solveNQueens(int n) {
  int num = 0;
  std::vector<int> tempVector(n, 0);
  backTrack(num, tempVector, n, 0);
  return num;
}

int main() {
    int n;
    cin >> n;
    cout << solveNQueens(n) << endl;
}
