#include <iostream>
#include <sstream>
using namespace std;
int CLK_TCK = 100;

string fillZero(int val) {
  stringstream ss;
  if(val < 10) {
    ss << "0" << val;
  } else {
    ss << val;
  }
  return ss.str();
}

string transform(int cost_time) {
  int hour, minute, second;
  hour =  cost_time / 3600;
  cost_time = cost_time % 3600;
  minute = cost_time / 60;
  cost_time = cost_time % 60;
  second = cost_time;

  stringstream ss;
  ss << fillZero(hour) << ":" << fillZero(minute) << ":" << fillZero(second);
  return ss.str();

}

int main() {
  int C1, C2;
  string rsl;
  cin >> C1 >> C2;

  int diff = (0.5 + (double)(C2 - C1) / 100); //这条处理得很好，自己手动解决，不交给程序自行处理，掌握代码的控制权
  rsl = transform(diff);
  cout << rsl << endl;
}
