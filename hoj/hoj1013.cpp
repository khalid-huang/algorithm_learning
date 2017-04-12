//这个题目主要是会涉及到输入的时候是一个很大数字，所以第一轮处理的时候先用string来处理，后面的迭代就可以只用数字来迭代了；

#include <iostream>
#include <string>
using namespace std;

long str_digit_sum(string s) {
  int size = s.length();
  long sum = 0;
  for(int i = 0; i < size; i++) {
    sum += s[i] - '0';
  }
  return sum;
}

int digit_sum(int val) {
  int sum = 0;
  while(val) {
    sum += val % 10;
    val /= 10;
  }
  return sum;
}


int main() {
    string num;
    long x;
    while(cin >> num && num != "0") {
      x = str_digit_sum(num);
      while(x >= 10) {
        x = digit_sum(x);
      }
      cout << x << endl;
    }
}
