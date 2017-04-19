#include <iostream>
#include <sstream>

using namespace std;

string int2str(int val) {
  stringstream ss_val;
  ss_val << val;
  return ss_val.str();
}

string ten2certern(long val, int basic) {
  if(val == 0) {
    return "0";
  }
  string rsl = "";
  while(val != 0) {
    rsl = int2str(val % basic) + rsl;
    val = val / basic;
  }
  return rsl;
}

int main() {
  long a, b;
  int basic;
  cin >> a >> b >> basic;
  cout << ten2certern(a + b, basic) << endl;
}
