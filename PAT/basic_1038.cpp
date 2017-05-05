#include <iostream>
#include <sstream>

using namespace std;

int grade[101];

int main() {
  int N;
  cin >> N;

  int index;
  while(N--) {
    cin >> index;
    ++grade[index];
  }

  stringstream ss;
  cin >> N;
  while(N--) {
    cin >> index;
    ss << grade[index] << " ";
  }
  string str = ss.str();
  cout << str.substr(0, str.size()-1) << endl;
}
