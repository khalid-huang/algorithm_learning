#include <iostream>
#include <vector>

using namespace std;

int directions[4][2] = {{1, 0}, {-1, 0}, {0 ,1}, {0,-1}};

//可以利用回溯的方式来替代visited数组，利用|| 实现返回值取代引用修改结果
bool bfs(std::vector<std::vector<char> >& board, string word, int count, int row, int col) {
  if(count == word.size()) {
    return true;
  }
  if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size()) {
    return false;
  }

  if(board[row][col] != word[count]) {
    return false;
  }

  char c = board[row][col];
  board[row][col] = '#'; //防止重复使用
  bool exist = bfs(board, word, count + 1, row + 1, col)
      || bfs(board, word, count + 1, row - 1, col)
      || bfs(board, word, count + 1, row, col + 1)
      || bfs(board, word, count + 1, row, col - 1);
  board[row][col] = c; //  回溯
  return exist;

}

bool exist(std::vector<std::vector<char> >& board, string word) {
  int rows = board.size();
  if(rows == 0) {
    return false;
  }
  int cols = board[0].size();
  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      if(bfs(board, word, 0, i, j)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  std::vector<std::vector<char> > board;
  std::vector<char> v1(4);
  v1[0] = 'A';
  v1[1] = 'B';
  v1[2] = 'C';
  v1[3] = 'E';
  std::vector<char> v2(4);
  v2[0] = 'S';
  v2[1] = 'F';
  v2[2] = 'C';
  v2[3] = 'S';
  std::vector<char> v3(4);
  v3[0] = 'A';
  v3[1] = 'D';
  v3[2] = 'E';
  v3[3] = 'E';

  board.push_back(v1);
  board.push_back(v2);
  board.push_back(v3);

  string word;
  cin >> word;
  cout << exist(board, word) << endl;
}
