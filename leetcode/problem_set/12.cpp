//http://www.tuicool.com/articles/BZJrEbV
#include <iostream>
#define MAXN 13

using namespace std;

int nums[MAXN] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
string romans[MAXN] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

string intToRoman(int num) {
  string rsl = "";
  for(int i = 0; i < MAXN; i++) {
    while(num >= nums[i]) {
      rsl += romans[i];
      num -= nums[i];
    }
    if(num == 0) {
      break;
    }
  }
  return rsl;
}

int main() {
  int num;
  cin >> num;
  cout << intToRoman(num) << endl;
}
