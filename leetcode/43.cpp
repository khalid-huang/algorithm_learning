#include <iostream>
#include <sstream>

using namespace std;

void getDigit(string num, int numArray[]) {
  int size = num.size();
  for(int i = 0; i < size; i++) {
    numArray[i] = num[i] - '0';
  }
}

string multiply(string num1, string num2) {
  int size_1 = num1.size(), size_2 = num2.size();
  int size_3 = size_1 + size_2;
  int rsl[size_3];
  for(int i = 0; i < size_3; i++) {
    rsl[i] = 0;
  }

  int num1Array[size_1], num2Array[size_2];
  getDigit(num1, num1Array);
  getDigit(num2, num2Array);
  int mul, carry = 0, temp;
  for(int i = 0; i < size_2; i++) {
    for(int j = 0; j < size_1; j++) {
      mul = num2Array[size_2 - i - 1] * num1Array[size_1 - j - 1] + carry;
    //   cout << num2[size_2 - i - 1] << "*" << num1[size_1 - j - 1] << "+" << carry << "=" << mul;
      temp = mul + rsl[i+j];
      carry = temp / 10;
      rsl[i+j] = temp % 10;
    //   cout << " " << "rsl[i+j]" << rsl[i+j] << endl;
    }
    if(carry != 0) {
      rsl[i + size_1] = carry;
      carry = 0;
    }
    // for(int k = i + size_1; k >= 0; k--) {
    //   cout << rsl[k];
    // }
    // cout << endl;
  }

//   cout << endl;

  int i = size_3 - 1;
  while(i > 0 && rsl[i] == 0) {
    --i;
  }

  stringstream ss;
  for(; i >= 0; i--) {
    ss << rsl[i];
  }
  return ss.str();

}

int main() {
  string num1, num2;
  cin >> num1 >> num2;
  cout << multiply(num1, num2) << endl;
}
