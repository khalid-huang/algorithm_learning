#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int vals[101];
std::vector<int> inputs;

void init() {
  for(int i = 0; i < 101; i++) {
    vals[i] = 0;
  }
  inputs.clear();
}

void update_vals(int val) {
  while(val!= 1) {
    if(val & 1) {
      val = (3 * val + 1) / 2;
    } else {
      val = val / 2;
    }
    if(val <= 100) {
      vals[val] = 0;
    }
    // cout << val << endl;
  }
}

void update() {
  int size = inputs.size();
  for(int i = 0; i < size; i++) {
    if(vals[inputs[i]] == 1) {
      // cout << "input:" << inputs[i] << endl;
      update_vals(inputs[i]);
      // cout << "inputs end" << endl;
    }
  }
}

void print() {
  stringstream ss_rsl;
  string rsl;
  for(int i = 100; i >= 0; i--) {
    if(vals[i] == 1) {
      ss_rsl << i << " ";
    }
  }
  rsl = ss_rsl.str();
  cout << rsl.substr(0, rsl.length()-1) << endl;
}

int main() {
  int num, val;
  init();
  cin >> num;
  while(num--) {
    cin >> val;
    vals[val] = 1;
    inputs.push_back(val);
  }
  update();
  print();
}
