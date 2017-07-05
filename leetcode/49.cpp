#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//直接使用map<string, vector<string>> //前面的key string 表示一个已经排序好的字符，
std::vector<std::vector<string> > groupAnagrams(std::vector<string>& strs) {
  std::map<string, vector<string> > maps;
  int size = strs.size();
  string temp;
  for(int i = 0; i < size; i++) {
    temp = strs[i];
    sort(temp.begin(), temp.end());
    if(maps.find(temp) != maps.end()) {
      maps[temp].push_back(strs[i]);
    } else {
      std::vector<string> tempVector;
      maps[temp] = tempVector;
      maps[temp].push_back(strs[i]);
    }
  }
  std::vector<std::vector<string> > rsl;
  std::vector<string> tempVector;
  for(std::map<string, std::vector<string> >::iterator it = maps.begin(); it != maps.end(); it++) {
    sort(it->second.begin(), it->second.end());
    rsl.push_back(it->second);
  }

  return rsl;
}

void print(std::vector<std::vector<string> > rsl) {
  int size_o = rsl.size();
  for(int i = 0; i < size_o; i++) {
    int size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  std::vector<string> strs(6, "");
  strs[0] = "eat";
  strs[1] = "tea";
  strs[2] = "tan";
  strs[3] = "ate";
  strs[4] = "nat";
  strs[5] = "bat";
  print(groupAnagrams(strs));
}
