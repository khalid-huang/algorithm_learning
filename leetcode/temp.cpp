#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int> > v) {
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}


int main() {
  int a = -2147483647;
  int b = -a;
  cout << -a << endl;
}