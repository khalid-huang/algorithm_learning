#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
  int h_size = haystack.size();
  int n_size = needle.size();
  int i, j, target_index = -1;
  int up = h_size - n_size + 1;
  for(i = 0; i < up; i++) {
    for(j = 0; j < n_size; j++) {
      if(haystack[i+j] != needle[j]) {
        break;
      }
    }
    if(j == n_size) {
      target_index = i;
      break;
    }
  }
  return target_index;
}

int main() {
  string haystack, needle;
  cin >> haystack >> needle;
  cout << strStr(haystack, needle) << endl;
}
