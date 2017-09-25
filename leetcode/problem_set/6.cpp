//这个题目主要是一个找规律的题目，可以通过罗列一些情况看出，每行的每个字母之间是按原字符串一定间隔生成的，这个间隔的规律是间隔和为2 * (numRows - 1); 然后有两个值交替，一个是2 * i,一个是间隔和减去这个数
#include <iostream>

using namespace std;

string convert(string s, int numRows) {
  if(numRows == 1) {
    return s;
  }
  int size = s.size();
  int itv = 2 * (numRows - 1), itv1, itv2, cur;
  string rsl = "";
  for(int i = 0; i < numRows; i++) {
    itv2 = i * 2;
    itv1 = itv - itv2;
    //下面两个调整是为了方便于第一行和最后一行
    itv1 = itv1 == 0 ? itv : itv1;
    itv2 = itv2 == 0 ? itv : itv2;

    cur = i;
    rsl += s[cur];
    while(true) {
      if(cur + itv1 < size) {
        cur += itv1;
        rsl += s[cur];
      } else {
        break;
      }
      if(cur + itv2 < size) {
        cur += itv2;
        rsl += s[cur];
      } else {
        break;
      }
    }
  }
  return rsl;
}

int main() {
  string s = "PAYPALISHIRING";
  int numRows = 3;
  cin >> s >> numRows;
  cout << convert(s, numRows) << endl;
}
