#include <iostream>
#include <string>
using namespace std;

long get_D_val(string input, int num) {
  size_t size = input.size();
  int basic = 1;
  long val = 0;
  for(int i = 0; i < size; i++) {
    if(input[i] - '0' == num) {
      val += basic * num;
      basic *= 10;
    }
  }
  return val;
}

int main() {
  int DA, DB;
  string A, B;
  long DA_val, DB_val;
  cin >> A >> DA >> B >> DB;
  DA_val = get_D_val(A, DA);
  DB_val = get_D_val(B, DB);
  cout << DA_val + DB_val << endl;
}
