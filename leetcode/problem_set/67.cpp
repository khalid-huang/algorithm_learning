#include <iostream>

using namespace std;

string addBinary(string a, string b) {
  int c = 0, i = a.size() -1, j = b.size() - 1;
  string rsl;
  while(i >= 0 || j >= 0 || c == 1) {
    c += (i >= 0 ? a[i--] - '0' : 0);
    c += (j >= 0 ? b[j--] - '0' : 0);
    rsl = char(c % 2 + '0') + rsl;
    c /= 2;
  }
  return rsl;
}

string addBinary1(string a, string b) {
  string temp;
  if(a.size() < b.size()) {
    temp = b;
    b = a;
    a = temp;
  }
  int size_a = a.size(), size_b = b.size();
  int remain = 0;
  string rsl;
  for(int i = 1; i <= size_b; i++) {
    if(a[size_a - i] == '1' && b[size_b - i] == '1') {
      rsl += (remain == 1 ? "1" : "0");
      remain = 1;
    } else if(a[size_a - i] == '1' || b[size_b - i] == '1') {
      rsl += (remain == 1 ? "0" : "1");
      remain = (remain == 1 ? 1 : 0);
    } else {
      rsl += (remain == 1 ? "1" : "0");
      remain = 0;
    }
  }
  for(int i = size_b + 1; i <= size_a; i++) {
    if(remain == 1 && a[size_a - i] == '1') {
      remain = 1;
      rsl += "0";
    } else if(remain == 1 || a[size_a - i] == '1') {
      rsl += "1";
      remain = 0;
    } else {
      rsl += "0";
    }
  }
  if(remain == 1) {
    rsl += "1";
  }
  string rsl_r;
  int size =rsl.size();
  for(int i = size - 1; i >= 0; i--) {
    rsl_r.push_back(rsl[i]);
  }
  return rsl_r;
}

int main() {
  string a, b;
  cin >> a >> b;
  cout << addBinary(a, b) << endl;
}
