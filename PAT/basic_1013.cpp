#include <iostream>
using namespace std;

bool isPrime(int val) {
  for(int i = 2; i * i <= val; i++) {
    if(val % i == 0 && i != val) {
      return false;
    }
  }
  return true;
}

int main() {
  int M, N;
  cin >> M >> N;
  int cur = 1, index = 0, index_print = 0;
  while(true) {
    cur++;
    if(isPrime(cur)) {
      index++;
      if(index < M || index > N) {
        continue;
      }
      if(index == N) {
        cout << cur << endl;
        break;
      }
      index_print++;
      if(index_print % 10 != 0) {
        cout << cur << " ";
      } else {
        cout << cur << endl;
      }
    }
  }
}
