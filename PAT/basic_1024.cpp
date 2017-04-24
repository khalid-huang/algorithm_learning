#include <iostream>
#include <string>
using namespace std;


string integerPart, decimalPart;
int expNum;
int num_sign;
int exp_sign;

int str2int(string expPart) {
  int i = 0;
  int expNum = 0;
  size_t size = expPart.size();
  while(expPart[i] == '0') {
    i++;
  }
  for(; i < size; i++) {
    expNum = expNum * 10 + (expPart[i] - '0');
  }
  return expNum;
}

string getZeroStr(int num) {
  string str;
  while(num--) {
    str += "0";
  }
  return str;
}

void deal_split(string str) {
  string expPart;
  int decimal_index = str.find(".");
  int exp_index = str.find("E");
  // cout << str << " " << decimal_index << " " << exp_index << endl;
  if(str[0] == '+') {
    num_sign = 1;
  } else {
    num_sign = -1;
  }
  if(str[exp_index+1] == '+') {
    exp_sign = 1;
  }  else {
    exp_sign = -1;
  }
  integerPart = str.substr(1, decimal_index - 1);
  // cout << integerPart << endl;
  decimalPart = str.substr(decimal_index+1, exp_index - (decimal_index + 1));
  // cout << decimalPart << endl;
  expPart = str.substr(exp_index+2);
  // cout << expPart << endl;
  expNum = str2int(expPart);
  // cout << "expNum: " << expNum << endl;
}

void transform() {
  size_t integerPart_size = integerPart.size();
  size_t decimalPart_size = decimalPart.size();
  int moveNum;
  string movePart, fillZeroPart;
  if(exp_sign == -1) {
    moveNum = expNum > integerPart_size ? integerPart_size :expNum;
    movePart = integerPart.substr(integerPart_size - moveNum);
    integerPart = integerPart.substr(0, integerPart_size - moveNum);
    fillZeroPart = getZeroStr(expNum - moveNum);
    decimalPart = fillZeroPart + movePart + decimalPart;
  } else {
    moveNum = expNum > decimalPart_size ? decimalPart_size : expNum;
    movePart = decimalPart.substr(0, moveNum);
    decimalPart = decimalPart.substr(moveNum);
    fillZeroPart = getZeroStr(expNum - moveNum);
    integerPart = integerPart + movePart + fillZeroPart;
  }
}

void print() {
  // cout << "integerPart: " << integerPart << endl;
  // cout << "decimalPart: " << decimalPart << endl;
  string str;
  if(num_sign == -1) {
    str += "-";
  }

  if(integerPart.size()) {
    str += integerPart;
  } else {
    str += "0";
  }

  if(decimalPart.size()) {
    str += ".";
    str += decimalPart;
  }
  cout << str << endl;
}

int main() {
  string str;
  cin >> str;
  deal_split(str);
  // cout << "1" << endl;
  transform();
  // cout << "2" << endl;
  print();
}
