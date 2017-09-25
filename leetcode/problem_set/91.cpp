#include <iostream>

using namespace std;

int str2int(string str) {
  int size = str.size(), val;
  for(int i = 0; i < size; i++) {
    val = val * 10 +  (str[i] - '0');
  }
  return val;
}

void _numDecodings(string s, int& count, int pos) {
  int size = s.size();
  if(pos == size) {
    ++count;
    return;
  }
  int part;
  if(pos + 1 < size) {
    part = str2int(s.substr(pos, 2));
    if(10 <= part && part <= 26) {
      _numDecodings(s, count , pos+2);
    }
  }
  part = str2int(s.substr(pos,1));
  if(1 <= part && part <= 9) {
    _numDecodings(s, count, pos+1);
  }
}

int numDecodings(string s) {
  if(s.size() == 0) {
    return 0;
  }
  int count = 0, pos = 0;
  _numDecodings(s, count, pos);
  return count;
}

int main() {
  string s;
  cin >> s;
  cout << numDecodings(s) << endl;
}
