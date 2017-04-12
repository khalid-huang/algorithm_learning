#include <iostream>
#include <string>
using namespace std;

string pingyin[10] = {"ling", "yi", "er", "san", "si", "wu",
              "liu", "qi", "ba", "jiu"};

void print(long sum) {
  string rsl = "";
  int temp;
  while(sum) {
    temp = sum % 10;
    sum /= 10;
    rsl = pingyin[temp] + " " + rsl;
  }
  rsl = rsl.substr(0,rsl.length()-1);
  // cout << rsl.length() << endl;
  cout << rsl << endl;
}

long cal(string val) {
  int size= val.length();
  long sum = 0;
  for(int i = 0; i < size; i++) {
    sum += val[i] - '0';
  }
  return sum;
}

int main() {
  string val;
  long sum = 0;
  cin >> val;
  sum = cal(val);
  // cout << sum << endl;
  print(sum);
}
