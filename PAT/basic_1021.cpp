#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int digit_num[10];
void init() {
  for(int i = 0; i < 10; i++) {
    digit_num[i] = 0;
  }
}

void analyse(string val) {
  int size = val.size();
  for(int i = 0; i < size; i++) {
    digit_num[val[i] - '0']++;
  }
}

void print() {
  for(int i = 0; i < 10; i++) {
    if(digit_num[i] != 0) {
      cout << i << ":" << digit_num[i] << endl;
    }
  }
}

int main() {
  string val;
  cin >> val;
  init();
  analyse(val);
  print();
}
