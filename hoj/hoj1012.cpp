#include <iostream>
#include <iomanip>
using namespace std;
double e[10];

double factorial_reciprocal(int val) {
  double rsl = 1;
  for(int i = 1; i < val + 1; i++) {
    rsl *= i;
  }
  // cout << 1.0 / rsl << endl;
  return 1.0 / rsl;
}

void calE() {
  double pre = 0;
  for(int i = 0; i < 10; i++) {
    pre += factorial_reciprocal(i);
    e[i] = pre;
  }
}

void printE() {
  cout << "n e" << endl;
  cout << "- -----------" << endl;
  cout << setprecision(10);
  for(int i = 0; i < 10; i++) {
    cout << i << " " << e[i];
    if(i == 8) {
      cout << "0";
    }
    cout << endl;
  }
}

int main() {
    calE();
    printE();
}
