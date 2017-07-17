#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string int2str(int val) {
  stringstream ss;
  ss << val;
  return ss.str();
}

string getPermutation(int n ,int k) {
  int factor[10] = {1};
  for(int i = 1; i <= 9; i++) {
    factor[i] = i * factor[i-1];
  }

  vector<string> digits;
  for(int i = 1; i < 10; i++) {
    digits.push_back(int2str(i));
  }

  int temp;
  string rsl;
  while(n > 0) {
    temp = (k - 1) / factor[n-1];
    rsl.insert(rsl.size(), digits[temp]);
    digits.erase(digits.begin() + temp);
    k = k - temp * factor[n-1];
    n--;
  }
  return rsl;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << getPermutation(n ,k) << endl;
}
