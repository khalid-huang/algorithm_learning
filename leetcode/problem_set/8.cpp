#include <iostream>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int myAtoi(string str) {
  if(str == "") {return 0;}
  int size = str.size();
  int sign, i;
  while(i < size && str[i] == ' ') {
    ++i;
  }

  sign = 1;
  if(i < size && str[i] == '+' || str[i] == '-') {
    sign = str[i] == '-' ? sign * -1 : sign;
    i++;
  }

  int val = 0;

  while(i < size && str[i] >= '0' && str[i] <= '9') {
    if(val > val * 10 + (str[i] - '0')) {
      val = -1;
      break;
    } else {
      val = val * 10 + (str[i] - '0');
      ++i;
    }
  }
  if(val == -1) {
    if(sign == -1) {
      return INT_MIN;
    } else {
      return INT_MAX;
    }
  }
  return sign * val;
}

int main() {
  string s;
  cin >> s;
  cout << myAtoi(s) << endl;
}
