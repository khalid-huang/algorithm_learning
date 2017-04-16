#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    double A4 = 0;
    int A2_index = 0, A4_num = 0;
    int N, val, type;
    cin >> N;
    while(N--) {
      cin >> val;
      switch (val % 5) {
        case 0:
          if(!(val & 1)) {
            A1 += val;
          }
          break;
        case 1:
          A2_index = A2_index + 1;
          A2 = A2_index & 1 ? A2 + val : A2 - val;
          break;
        case 2:
          A3 = A3 + 1;
          break;
        case 3:
          A4 = A4 + val;
          A4_num = A4_num + 1;
          break;
        case 4:
          A5 = A5 < val ? val : A5;
          break;
      }
    }
    if(A1 != 0) {
      cout << A1 << " ";
    } else {
      cout << "N ";
    }
    if(A2_index != 0) {
      cout << A2 << " ";
    } else {
      cout << "N ";
    }
    if(A3 != 0) {
      cout << A3 << " ";
    } else {
      cout <<"N ";
    }
    if(A4_num != 0) {
      cout << fixed << setprecision(1) << A4 / A4_num << " ";
    } else {
      cout << "N ";
    }
    if(A5 != 0) {
      cout << A5 << endl;
    } else {
      cout << "N" << endl;
    }
}
