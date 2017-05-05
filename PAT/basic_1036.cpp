#include <iostream>

using namespace std;

void print(int num, char c) {
  int j;
  int row = 0.5 + num * 0.5; //四舍五入
  // row = row + (row - 1); //加上空行；
  // cout << row;
  for(int i = 1; i <= row; i++) {
    if(i == 1 || i == row) {
      j = num;
      while(j--) {
        cout << c;
      }
      cout << endl;
      continue;
    }
    //奇数
    if(i & 1) {
      cout << c;
      j = num - 2;
      while(j--) {
        cout << " ";
      }
      cout << c;
      cout << endl;
    } else {
      cout << endl;
      continue;
    }
  }
}

int main() {
  int num;
  char c;
  cin >> num >> c;

  print(num, c);
}
