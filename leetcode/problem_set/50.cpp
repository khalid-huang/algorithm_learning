#include <iostream>

using namespace std;

double myPow(double x, int n) {
  double ans = 1;
  unsigned long long p; //这里要用unsigned , 不能使用int因为。如果是最大的负数籽这正数的话，使用取反，还是会得到一个负数的，因为itn型 的最大负数比最大正数多了一个; [-2147483648, 2147483647]
  //也就是最大负数10000000先减1,得到01111111,再取反还是得到10000000；也就是其本身了
  if(n < 0) {
    p = -n;
    x= 1/x;
  } else {
    p = n;
  }

  while(times != 0) {
    if(times & 1 == 1) {
      ans *= x;
    }
    x = x * x;
    times = times >> 1;
  }
  return ans;
}

int main() {
  double x;
  int n;
  cin >> x >> n;
  cout << myPow(x, n) << endl;
}
