#include <iostream>
using namespace std;

int main() {
  int t, i;
  cin >> t;
  long a, b, c;
  for(int i = 1; i < t + 1; i++) {
    cin >> a >> b >> c;
    if(a + b > c) {
      cout << "Case #" << i << ": " << "true" << endl;
    } else {
      cout << "Case #" << i << ": " << "false" << endl;
    }
  }
}
