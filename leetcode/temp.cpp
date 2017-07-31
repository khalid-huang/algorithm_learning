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
  int a = 3;
  int b = 5;
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  cout << a << " " << b << endl;
}
