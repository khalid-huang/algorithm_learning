#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

std::vector<int> coefficients;
std::vector<int> exponents;

void print() {
  // cout << "kkk" << endl;
  stringstream rsl_ss;
  string str;
  size_t size = coefficients.size();
  if(size == 1 && exponents[0] == 0) {
    cout << "0 0" << endl;
    return;
  }
  int mul;
  for(int i = 0; i < size; i++) {
    mul = coefficients[i] * exponents[i];
    if(mul != 0) {
      rsl_ss << mul << " " << exponents[i] - 1 << " ";
    }
  }
  str = rsl_ss.str();
  cout << str.substr(0, str.size()-1) << endl;
}

int main() {
  int coefficient, exponent;
  while(cin.get() != '\n') {
    cin.unget();
    cin >> coefficient >> exponent;
    coefficients.push_back(coefficient);
    exponents.push_back(exponent);
  }
  print();
}
