#include <iostream>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int size = s.size();
  int c[size];
  for(int i = 0; i < size; i++) {
    c[i] = 1;
  }
  int max = 1, count;
  for(int i = 1; i < size; i++) {
    count = 1;
    for(int j = i - 1; j >= i - c[i-1]; j--) {
      if(s[i] != s[j]) {
        ++count;
      } else {
        break;
      }
    }
    c[i] = count;
    max = max < count ? count : max;
  }
  // for(int i = 0; i < size; i++) {
  //   cout << c[i] << " ";
  // }
  cout << endl;
  return max;
}

int main() {
  string s = "abcabc";
  cout << lengthOfLongestSubstring(s) << endl;
}
