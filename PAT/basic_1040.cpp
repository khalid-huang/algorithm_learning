//作法很好，参考了 http://blog.csdn.net/ice_camel/article/details/44263451

#include <iostream>

using namespace std;

int analyse(string pat) {
  size_t size = pat.size();
  int numT = 0, numAT = 0, numPAT = 0;
  for(int i = size-1; i >= 0; i--) {
    if(pat[i] == 'T') {
      ++numT;
    } else if(pat[i] == 'A') {
      numAT = numAT + numT;
    } else if(pat[i] == 'P') {
      numPAT = (numPAT + numAT) % 1000000007;
    }
  }
  return numPAT;
}

int main() {
  string pat;
  cin >> pat;
  cout << analyse(pat) << endl;
}
