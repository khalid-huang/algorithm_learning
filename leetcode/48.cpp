#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void rotate(std::vector<std::vector<int> >& matrix) {
  int size = matrix.size();
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  for(int i = 0; i < size; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  std::vector<std::vector<int> > matrix();

}
