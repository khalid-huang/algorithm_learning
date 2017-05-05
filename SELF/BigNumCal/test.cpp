#include<iostream>

using namespace std;

char int2char(int v) {
  return v+'0';
}

int main() {
  int test[4] = {1,2,3,4};
  string str;
  for(int i =0; i < 4;i++) {
    str += int2char(test[i]);
  }
  cout << str << endl;
}
