#include <iostream>
#include <vector>

using namespace std;


void print(std::vector<int> v) {
  int size = v.size();
  for(int i = 0;i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

std::vector<int> getRow(int rowIndex) {

  std::vector<int> rsl(rowIndex+1, 0);
  rsl[0] = 1;
  for(int i = 1; i <= rowIndex; i++) {
    for(int j = i; j > 0; j--) { //反着过来，因为正向的话，数字会覆盖影响
      rsl[j] = rsl[j] + rsl[j-1];
    }
  }
  return rsl;
}

int main() {
  int rowIndex;
  cin >> rowIndex;
  print(getRow(rowIndex));
}
