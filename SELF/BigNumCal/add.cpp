//只支持全正数的加法

#include <iostream>

using namespace std;

int char2int(char c) {
  return c - '0';
}

char int2char(int v) {
  return v + '0';
}

//唯一注意的是要反序来相加
string bigAdd(string v1, string v2) {
  size_t size1 = v1.size();
  size_t size2 = v2.size();

  string temp;
  if(size1 < size2) {
    temp = v1;
    v1 = v2;
    v2 = temp;
    size1 = v1.size();
    size2 = v2.size();
  }

  int carry = 0;
  int sum;
  string rsl;
  //先遍历完一个的加法；
  for(int i = 1; i <= size2; i++) {
    sum = char2int(v1[size1 - i]) + char2int(v2[size2 - i]) + carry;;
    if(sum > 9) {
      carry = 1;
      sum = sum % 10;
    } else {
      carry = 0;
    }
    rsl = int2char(sum) + rsl;
  }

  //补全剩下的内容
  for(int i = size2+1; i <= size1; i++) {
    sum = char2int(v1[size1 - i]) + carry;
      if(sum > 9) {
      carry = 1;
      sum = sum % 10;
    } else {
      carry = 0;
    }
    rsl = int2char(sum) + rsl;
  }
  if(carry == 1) {
    rsl = int2char(1) + rsl;
  }
  return rsl;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  string rsl = bigAdd(v1, v2);
  cout << rsl << endl;
}
