//使用移位操作，解决
//注意对于temp要使用Long long的，因为如果dividend是最大的2^31 - 1的话，temp << 1可能会大于最大int型 整数的; 而对于dividend和divisort来说，取绝对值也要使用labs，也就是长整形的abs，因为如果其是最大的负数的话，直接取绝对值就变成0了
//好题
#include <iostream>
#include <algorithm>
#define INT_MAX 100000
#define INT_MIN -100000
using namespace std;

int divide(int dividend, int divisor) {
  if(divisor == 0 || (dividend== INT_MIN && divisor == -1)) {
    return INT_MAX;
  }

  int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
  // long long dvd = labs(dividend), dvs = labs(divisor);
  int dvd = abs(dividend), dvs = abs(divisor);
  cout << dvd << " " << dvs << endl;

  int rsl = 0, multiple;
  // long long temp, multiple;
  // int temp, multiple;
  long long temp;
  while(dvd >= dvs) {
    temp = dvs;
    multiple = 1;
    while(dvd >= (temp << 1)) {
      temp = temp << 1;
      multiple = multiple << 1;
    }
    dvd -= temp;
    rsl += multiple;
  }
  return sign * rsl;
}

int main() {
  int divident, divisor;
  cin >> divident >> divisor;
  cout << divide(divident, divisor) << endl;
}
