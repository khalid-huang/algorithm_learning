#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ofstream fout("output.txt");

int getPower(long long unsigned value) {
  int power = 1;
  long long unsigned temp = 1;
  while(temp * 2 <= value) {
    ++power;
    temp = temp * 2;
  }
  return power;
}

string KthGoogleString(long long unsigned K) {

  int power = getPower(K);

  // fout << "power:" << power << endl;
  cout << "power:" << power << endl;
  long long unsigned cur = K;
  int count = 0;
  while(true) {
    // fout << cur << endl;
    cout << cur << endl;
    if(cur == 1 || cur == 2) {
      break;
    }
    //直接中心位置(从1开始计数)
    if(pow(2, power - 1) == cur) {
      break;
    }
    //不是中心位置进行翻转
    cur = pow(2, power) - cur;
    ++count;
    power = getPower(cur);
  }

  if(count & 1) {
    return "1";
  } else {
    return "0";
  }
}

int main() {
  int T;
  long long unsigned K;
  cin >> T;
  while(T--) {
    cin >> K;
    cout << KthGoogleString(K) << endl;
  }
  fclose(stdout);
}
