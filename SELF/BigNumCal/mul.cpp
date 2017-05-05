#include <iostream>

using namespace std;

void preDeal(string& v1, string& v2, int rsl[]) {
  if(v1.size() < v2.size()) {
    string temp = v1;
    v1 = v2;
    v2 = temp;
  }
  for(int i = 0; i < 1000; i++) {
    rsl[i] = 0;
  }
}

int char2int(char c) {
  return c - '0';
}

char int2char(int v) {
  return v + '0';
}

string ints2str(int rsl[], int size) {
  string mulRsl;
  for(int i = size-1; i >= 0; i--) {
    cout << rsl[i] << " ";
    mulRsl += int2char(rsl[i]);
  }
  return mulRsl;
}

//去除前导0
string postDeal(string str) {
  int index = 0;
  while(str[index] == '0') {
    ++index;
  }
  // cout << index << endl;
  return str.substr(index);
}

string mul(string v1, string v2) {
  int rsl[1000];
  preDeal(v1, v2, rsl);

  size_t size1 = v1.size();
  size_t size2 = v2.size();
  int carry = 0;
  int temp;
  //i, j表示使用第几位，是与数字对应的，0表示个位，但是在数组里面要进行对应的转换；
  for(int i = 0; i < size2; i++) {
    for(int j = 0; j < size1; j++) {
      temp = char2int(v2[size2 - 1 -  i]) * char2int(v1[size1 - 1 - j]) + carry; //这里要对应好
      // cout << i << ":" << v1[size1 - 1 - i] << " " << j<< ":" << v2[size2-1-j] << " " << temp << endl;
      //这里每轮运算都叠加到rsl数组里面，然后对其取模同时保留进位信息；
      rsl[i+j] += temp;
      carry = rsl[i+j] / 10;
      rsl[i+j] = rsl[i+j] % 10;
      cout << i << ":" << j << " ==> "<< v2[size2- 1 -i] << ":" << v1[size1-1-j] << " " << rsl[i+j] << " " << carry << endl;
    }
  }

  if(carry != 0) {
    rsl[size2 + size1 - 1] = carry; //最高位
  }
  return postDeal(ints2str(rsl, size2 + size1));
}

int main() {
  string v1, v2;
  cin >> v1 >> v2;
  cout << mul(v1, v2) << endl;
}
