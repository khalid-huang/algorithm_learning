//算法就是先固定某个位置，不断交换这个位置的元素（与其他位置进行交换）
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<string> rsl;

void print(std::vector<string> rsl) {
  cout << "pring" << endl;
  int size = rsl.size();
  for(int i = 0; i < size; i++) {
    cout << rsl[i] << endl;
  }
  cout << endl;
}

bool isSwap(string s, int start, int end) {
  if(start == end) {
    return true;
  }
  for(int i = start + 1; i < end; i++) {
    if(s[i] == s[end]) {
      return false;
    }
  }
  return true;
}

void swap(string& s, int i, int j) {
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

void _permutation(string s, int start, int end, string cur) {
  string temp;
  if(start == end) {
    // cur += s[start];
    temp = cur + s[start];
    rsl.push_back(temp);
    return;
  }
  for(int i = start; i <= end; i++) {
    if(isSwap(s, start, end)) {
      swap(s, start, i);
      // cur += s[start];
      temp = cur + s[start];
      _permutation(s, start+1, end, temp);
      swap(s, start, i);
    }
  }
}

void permutation(string s) {
  int end = s.size() - 1;
  int start = 0;
  string cur = "";
  _permutation(s, start, end, cur);
}

int main() {
  string s;
  cin >> s;
  // cout << s << endl;
  // swap(s, 1, 2);
  // cout << s << endl;
  permutation(s);
  sort(rsl.begin(), rsl.end());
  print(rsl);
}
