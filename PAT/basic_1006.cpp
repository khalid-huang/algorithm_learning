#include <iostream>
#include <vector>

using namespace std;

std::vector<int> digits;

void get_digits(int val) {
  digits.clear();
  // cout << "1" << endl;
  while(val) {
    digits.push_back(val % 10);
    val = val / 10;
  }
  // cout << "2" << endl;
}

void print_one(int val, int digit) {
  if(digit == 2) {
    for(int i = 0; i < val; i++) {
      cout << "B";
    }
  } else if(digit == 1) {
    for(int i = 0; i < val; i++) {
      cout << "S";
    }
  } else if(digit == 0) {
    for(int i = 1; i <= val; i++) {
      cout << i;
    }
  }
}

void print() {
  int size = digits.size();
  for(int i = size - 1; i >= 0; i--) {
    print_one(digits[i], i);
  }
  cout << endl;
}

int main() {
    int val;
    cin >> val;
    get_digits(val);
    print();
}
