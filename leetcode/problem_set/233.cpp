//这个题目呢，要分位数进行统计，思路就是去计算每个位数的1的个数，将当前的数字进行切分成两半，以当前的位数为分界线；然后统计这个位数的情况
//加上8主要是为了计算出来的那个1,比如50和52在计算个数的时候，52明显要多出一个1的；就用加上8进位就可以了；而如果是1的话，还要用用b来进行加法
#include <iostream>

using namespace std;

int countDigitOne(int n) {
  int a, b;
  int ones = 0;
  for(long long m = 1; m <= n; m *= 10) {
    a = n / m, b = n % m;
    ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1); //b+1的1是a % 10为1多出来的1；
  }
  return ones;
}

int main() {
  int n;
  n = 99;
  cout << countDigitOne(99) << endl;
}
