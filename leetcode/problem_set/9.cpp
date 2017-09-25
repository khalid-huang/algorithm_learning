#include <iostream>
using namespace std;

bool isPalindrome(int x) {
  if(x < 0) {
    return false;
  }
  int val = 0;
  int temp = x;
  while(temp != 0) {
    val = val * 10 + temp % 10;
    temp = temp / 10;
  }
  // cout << val << endl;
  if(x == val) {
    // cout << "1" << endl;
    return true;
  } else {
    return false;
  }
}

int main() {
  int x;
  cin >> x;
  cout << isPalindrome(x) << endl;
}
