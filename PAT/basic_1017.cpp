#include <iostream>
using namespace std;
#include <sstream>
int remain = 0;
string quotient = "";

string int2str(int val) {
  stringstream ss_val;
  ss_val << val;
  return ss_val.str();
}

// void trim() {
// }

void get_rsl(string first_val, int second_val) {
  size_t size = first_val.size();
  int cur = 0, temp;
  int flag = 0; //表示要不要补0
  while(cur < size) {
    flag = 0;
    while(cur < size && remain < second_val) {
      if(flag == 1 && cur - 1 != 0) {
        quotient += "0";
      }
      remain = remain * 10 + first_val[cur] - '0';
      cur = cur + 1;
      flag = 1;
    }
    if(cur == size && remain < second_val) {
      if(flag == 1) {
        quotient += "0";
      }
      break;
    } else {
      temp = remain / second_val;
      quotient += int2str(temp);
      remain = remain % second_val;
    }
  }
  // trim(); //去掉前导0;
}

int main() {
  string first_val;
  int second_val;
  cin >> first_val >> second_val;
  get_rsl(first_val, second_val);
  cout << quotient << " " << remain << endl;
}
