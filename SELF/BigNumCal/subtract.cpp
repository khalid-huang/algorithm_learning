//只支持全正数的减法
#include <iostream>
using namespace std;

int char2int(char c) {
  return c - '0';
}

char int2char(int v) {
  return v + '0';
}

//主要是比较两个数字的大小，同时判断结果的符号
int preDeal(string& v1, string& v2) {
  if(v1.size() > v2.size() || (v1.size() == v2.size() && v1.compare(v2) > 0)) {
    return 1;
  } else {
    string temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
    return -1;
  }
}

string postDeal(string str) {
  int index = 0;
  while(str[index] == '0') {
    ++index;
  }
  str = str.substr(index);
  return str.size() != 0 ? str : "0";

}

string substract(string v1, string v2) {
  int isPositive = 1; //
  isPositive = preDeal(v1, v2); //保证v1 > v2;

  size_t size1 = v1.size();
  size_t size2 = v2.size();
  int temp;
  int carry = 0;
  string rsl;
  for(int i = 1; i <= size2; i++) {
    temp = char2int(v1[size1 - i]) - char2int(v2[size2- i]) - carry;
    if(temp < 0) {
      carry = 1;
      temp = temp + 10;
    } else {
      carry = 0;
    }
    rsl = int2char(temp) + rsl;
  }

  for(int i = size2 + 1; i <= size1; i++) {
    temp = char2int(v1[size1 - i]) - carry;
    if(temp < 0) {
      carry = 1;
      temp = temp + 10;
    } else {
      carry = 0;
    }
    rsl = int2char(temp) + rsl;
  }
  rsl = postDeal(rsl); //云除前导0
  if(isPositive == -1) {
    rsl = '-' + rsl;
  }
  return rsl;
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  string rsl = substract(v1, v2);
  cout << rsl << endl;
  // cout << preDeal(v1, v2) << endl;
  // cout << v1 << endl << v2 << endl;
}
