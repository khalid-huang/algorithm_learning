#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(std::vector<string>& strs) {
  int strs_size = strs.size(), temp_size;
  if(strs_size == 0) {
    return "";
  }
  int min_size = strs[0].size();
  for(int i = 1; i < strs_size; i++) {
    temp_size = strs[i].size();
    min_size = min_size < temp_size ? min_size : temp_size;
  }

  int cur = 0, flag;
  string temp_s;
  char temp_c;
  while(cur < min_size) {
    flag = 1;
    temp_c = strs[0][cur];
    for(int i = 1; i < strs_size; i++) {
      if(temp_c != strs[i][cur]) {
        // cout << "temp_c: " << temp_c << endl;
        cur--;
        flag = 0;
        break;
      }
    }
    if(flag == 0) {
      break;
    }
    cur++;
  }
  //cur表示的是下标
  cur = cur == min_size ? cur : cur + 1;
  return strs[0].substr(0, cur);
}

int main() {
  std::vector<string> strs;
  // strs.push_back("abcd");
  strs.push_back("aa");
  strs.push_back("a");
  cout << longestCommonPrefix(strs) << endl;

}
