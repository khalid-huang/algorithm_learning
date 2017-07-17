#include <iostream>

using namespace std;

int lengthOfLastWord(string s) {
  int up = s.size() - 1;
  while(up >= 0 && s[up] == ' ') {
    --up;
  }
  int count = 0;
  while(up >= 0 && s[up] != ' ') {
    ++count;
    --up;
  }
  return count;
}

int main() {
    string s = "Hello word  ";
    cout << lengthOfLastWord(s) << endl;
}
