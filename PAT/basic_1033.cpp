//http://www.jianshu.com/p/c5cf444a6593

#include <iostream>
#include <vector>

using namespace std;

bool Shift_flag = false;
std::vector<char> break_symbol;

bool isContain(std::vector<char> v, char c) {
  size_t size = v.size();
  for(int i = 0; i < size; i++) {
    if(v[i] == c) {
      return true;
    }
  }
  return false;
}

void analyse(string break_key) {
  size_t size = break_key.size();
  for(int i = 0; i < size; i++) {
    if(break_key[i] >= 'A' && break_key[i] <= 'Z') {
      break_symbol.push_back(break_key[i]);
      break_symbol.push_back(break_key[i] + 32);
      continue;
    }
    if(break_key[i] == '+') {
      Shift_flag = true;
      continue;
    }
    break_symbol.push_back(break_key[i]);
  }
}

void printResult(string origin) {
  size_t size = origin.size();
  for(int i = 0; i < size; i++) {
    //判断在不在
    if(isContain(break_symbol, origin[i])) {
      continue;
    }
    if(Shift_flag && origin[i] >= 'A' && origin[i] <= 'Z') {
      continue;
    }
    cout << origin[i];
    //大写字母的
  }
  cout << endl;
}

int main() {
    string break_key, origin;
    // cin >> break_key >> origin;
    getline(cin, break_key);
    cin >> origin;
    analyse(break_key);
    printResult(origin);
}
