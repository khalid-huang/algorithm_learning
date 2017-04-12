#include <iostream>
using namespace std;

int main() {
  int val, step;
  cin >> val;
  step = 0;
  while(val != 1) {
    if(val & 1) {
      //奇数
      val = (3 * val + 1) / 2;
    } else {
      //偶数
      val = val / 2;
    }
    step = step + 1;
  }
  cout << step << endl;
}
