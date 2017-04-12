#include <iostream>

using namespace std;

int digit_sum(int val) {
  int sum = 0;
  while(val) {
    sum += val % 10;
    val /= 10;
  }
  return sum;
}

int main() {
  int val, sum;
  while(cin >> val && val != 0) {
    sum = val;
    while(true) {
      sum = digit_sum(sum);
      if(sum >= 0 && sum < 10) {
        break;
      }
    }
    cout << sum << endl;
  }
}
