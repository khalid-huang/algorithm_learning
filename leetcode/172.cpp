#include <iostream>

using namespace std;

//超时
// int trailingZeroes(int n) {
// int count2 = 0, count5 = 0, cur;
// while(n > 0) {
// cur = n;
// while(cur % 2 == 0) {
//   ++count2;
//   cur /= 2;
// }
// while(cur % 5 == 0) {
//   ++count5;
//   cur /= 5;
// }
// --n;
// }
// return count2 < count5 ? count2 : count5;
// }

//还超时
int trailingZeroes(int n) {
  int count = 0, cur = 5, temp, basic = 1;
  while(cur <= n) {
    temp = basic;
    while(temp % 5 == 0) {
      ++count;
      temp /= 5;
    }
    ++basic;
    cur = basic * 5;
    ++count;
  }
  return count;
}

//使用n/i表示，比如50 / 5表示在这50个数里面，每5个数里面就有一个5；接着50 / 25，表示每25个数里面还有一个5,记录一开始没有记录的。
int trailingZeroes(int n) {
    int result = 0;
    for(long long i=5; n/i>0; i*=5){
        result += (n/i);
    }
    return result;
}

int main() {
  int n;
  cin >> n;
  cout << trailingZeroes(n) << endl;
}
