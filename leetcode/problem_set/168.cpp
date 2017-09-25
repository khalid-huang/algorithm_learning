#include <iostream>
#include <string>

using namespace std;

//关键在于要先将坐标定位好，这里要将1-》A换为0->A; 同时每次看看当前数除以26的余数
string convertToTitle(int n) {
  int num = n, remain;
  char temp;
  string s;
  while(num > 0) {
    remain = (num-1) % 26;
    num = (num-1) / 26;
    temp = char('A' + remain);
    s = temp + s;
  }
  cout << s[0] << endl;
  return s;
}

int main() {
  int n;
  cin >> n;
  cout << convertToTitle(n) << endl;
}
