#include <iostream>
#include <vector>

using namespace std;

void backTrack(std::vector<std::vector<int> >& rsl, std::vector<int>& tempVector, int n, int row) {
  if(row == n) {
    rsl.push_back(tempVector);
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
      backTrack(rsl, tempVector, n, row+1);
      //这里本来是要回溯一下的，但是tempVector[row]是直接修改的，所以就不用回溯了
      //实际就是tempVector[row] = 0;
    }
  }
}

// string genStr(int queen_pos, int num) {
//   string
// }

std::vector<std::vector<string> > int2str(std::vector<std::vector<int> > rsl) {
  std::vector<std::vector<string> > rsl_str;
  int size_o = rsl.size();
  if(size_o == 0) {
    return rsl_str;
  }
  int size_i = rsl[0].size();
  std::vector<string> tempVector;
  for(int i = 0; i < size_o; i++) {
    for(int j = 0; j < size_i; j++) {
      string tempStr(size_i, '.');
      tempStr[rsl[i][j]] = 'Q';
      tempVector.push_back(tempStr);
    }
    rsl_str.push_back(tempVector);
    tempVector.clear();
  }
  return rsl_str;
}

std::vector<std::vector<string> > solveNQueens(int n) {
  std::vector<std::vector<int> > rsl;
  std::vector<int> tempVector(n, 0);
  backTrack(rsl, tempVector, n, 0);
  return int2str(rsl);
}

void print(std::vector<std::vector<string> > rsl) {
  int size_o = rsl.size();
  for(int i = 0; i < size_o; i++) {
    int size_i = rsl[i].size();
    cout << "[ ";
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << "," << endl;
    }
    cout << "]" << endl;
  }
}

int main() {
    int n;
    cin >> n;
    print(solveNQueens(n));
}
