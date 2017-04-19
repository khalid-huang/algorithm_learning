//有两个地方要注意，首先一个是如果输入是234要先变为0234；如果输入是6174,也要输出7641-1467=6174
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

int cmp(const char &a, const char &b) {
  if(a > b) {
    return 1;
  } else {
    return 0;
  }
}

string int2str(int val) {
  stringstream ss_val;
  ss_val << val;
  return ss_val.str();
}

int str2int(string str) {
  int val = 0, basic = 10;
  size_t size = str.size();
  for(int i = 0; i < size; i++) {
    val = val * basic + (str[i] - '0');
  }
  return val;
}

bool check_kaprekar(string val) {
  if(val == "6174") {
    return true;
  } else {
    return false;
  }
}

bool check_same(string val) {
  char first = val[0];
  size_t size = val.size();
  for(int i = 1; i < size; i++) {
    if(first != val[i]) {
      return false;
    }
  }
  return true;
}

int sort_get_val(string val,string type) {
  size_t size = val.size();
  char split_chars[size+1];
  int val_int = 0, basic = 10;;
  for(int i = 0; i < size; i++) {
    split_chars[i] = val[i];
  }
  if(type == "up") {
    sort(split_chars, split_chars+size);
  } else {
    sort(split_chars, split_chars+size, cmp);
  }

  for(int i = 0; i < size; i++) {
    val_int = val_int * 10 + (split_chars[i] - '0');
  }
  return val_int;
}

string fill_zero(int val_int) {
  string val = int2str(val_int);
  int fill_size = 4 - val.size();
  string zero = "";
  for(int i = 0; i < fill_size; i++) {
    zero += "0";
  }
  return zero + val;
}

int main() {
  string val;
  int val_int;
  int big, small, temp;
  cin >> val;
  while(true) {
    val_int = str2int(val);
    val = fill_zero(val_int);

    if(check_same(val)) {
      cout << val << " - " << val << " = 0000" << endl;
      break;
    }

    big = sort_get_val(val, "down");
    small = sort_get_val(val, "up");
    temp = big-small;
    cout << fill_zero(big) << " - " << fill_zero(small) << " = " << fill_zero(temp) << endl;
    val = int2str(temp);

    if(check_kaprekar(val)) {
      break;
    }
  }
}
