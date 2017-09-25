#include <iostream>
#include <vector>

using namespace std;


void print(std::vector<string> rsl) {
  int size = rsl.size();
  for(int i = 0; i < size; i++) {
    cout << rsl[i] << ", ";
  }
  cout << endl;
}

int str2int(string str) {
  int val = 0, size = str.size();
  for(int i = 0; i < size; i++) {
    val = val * 10 + (str[i] - '0');
  }
  return val;
}

void backTrack(std::vector<string>& rsl, string& str, string s, int count, int pos) {
  // cout << str << endl;
  if(str.size() == s.size() + 4) {
    rsl.push_back(str.substr(0, str.size()-1));
    return;
  }
  if(count >= 4) {
    return;
  }

  int size = s.size(), tempVal;
  string tempStr;
  for(int i = 1; i <= 3; i++) {
    if(pos + i > size || (i >= 2 && s[pos] == '0')) { //过界的和以0为前导的
      break;
    }
    tempStr = s.substr(pos, i);
    tempVal = str2int(tempStr);
    if(tempVal >= 0 && tempVal <= 255) {
      str = str + s.substr(pos, i) + ".";
      backTrack(rsl, str, s, count + 1, pos+i);
      str = str.substr(0, str.size() - i - 1);
    }
  }
}

std::vector<string> restoreIpAddresses(string s) {
  std::vector<string> rsl;
  string str;
  int pos = 0, count = 0; //count用来剪枝的，因为如果分了四次之后还是没有成功就可以直接结束掉了。pos是用来纪录当前到了哪一步；
  backTrack(rsl, str, s, count, pos);
  return rsl;
}

int main() {
  string s;
  cin >> s;
  print(restoreIpAddresses(s));
}
