#include <iostream>
#include <sstream>
using namespace std;

int nums[10];

string int2str(int i) {
  stringstream ss_val;
  ss_val << i;
  return ss_val.str();
}

string get_capital() {
  string capital;
  for(int i = 1; i < 10; i++) {
    if(nums[i] != 0) {
      nums[i]--;
      capital = int2str(i);
      break;
    }
  }
  return capital;
}


string get_min_number() {
  string rsl;
  rsl = get_capital();
  for(int i = 0; i < 10; i++) {
    while(nums[i] != 0) {
      rsl += int2str(i);
      --nums[i];
    }
  }
  return rsl;
}

int main() {
  for(int i = 0; i < 10; i++) {
    cin >> nums[i];
  }
  cout << get_min_number() << endl;
}
