//计算机是使用补码保持数据的，正数的补码是等于正数，而负数的补码是等于其反码加1 ，而相同的最高位都是符号位，其决定了是使用数据的解读是用原码还是补码


#include <iostream>

using namespace std;


int reverse(int x) {
  int val = x > 0 ? x : -x;
  int sign = x > 0 ? 1 : -1;
  long rsl = 0;
  while(val != 0) {
    rsl = rsl * 10 + val % 10;
    val = val / 10;
  }
  int maxVal = (1 << 31) - 1;
  int minVal = (1 << 31);
  if(rsl < minVal || rsl > maxVal) {
    rsl = 0;
  }
  return sign * rsl;
}

int main() {
  int val;
  cin >> val;
  cout << reverse(val) << endl;
}
