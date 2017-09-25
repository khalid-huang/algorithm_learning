// 动态规划
#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(std::vector<std::vector<char> >& matrix) {
  int rows = matrix.size();
  if(rows == 0) {
    return 0;
  }
  int cols = matrix[0].size();

  std::vector<std::vector<int> > dp(rows, std::vector<int>(cols, 0));
  int maxSize = 0;
  for(int i = 0; i < rows; i++) {
    dp[i][0] = matrix[i][0] - '0';
    maxSize = max(maxSize, dp[i][0]);
  }

  for(int j = 0; j < cols; j++) {
    dp[0][j] = matrix[0][j] - '0';
    maxSize = max(maxSize, dp[0][j]);
  }

  for(int i = 1; i < rows; i++) {
    for(int j = 1; j < cols; j++) {
      if(matrix[i][j] == '1') {
        dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
        maxSize = max(maxSize, dp[i][j]);
      }
    }
  }
  return maxSize * maxSize;
}

int main() {
  std::vector<std::vector<char> > matrix;
  std::vector<char> v1;
  v1.push_back('1');
  v1.push_back('0');
  v1.push_back('1');
  v1.push_back('0');
  v1.push_back('0');

  std::vector<char> v2;
  v2.push_back('1');
  v2.push_back('0');
  v2.push_back('1');
  v2.push_back('1');
  v2.push_back('1');

  std::vector<char> v3;
  v3.push_back('1');
  v3.push_back('1');
  v3.push_back('1');
  v3.push_back('1');
  v3.push_back('1');

  std::vector<char> v4;
  v4.push_back('1');
  v4.push_back('0');
  v4.push_back('0');
  v4.push_back('1');
  v4.push_back('0');

  matrix.push_back(v1);
  matrix.push_back(v2);
  matrix.push_back(v3);
  matrix.push_back(v4);
  cout << maximalSquare(matrix) << endl;

}
