#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<string> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

bool isPalindrome(string s, int start, int end) {
  while(start <= end) {
    if(s[start++] != s[end--]) {
      return false;
    }
  }
  return true;
}

//回溯
void _partition(std::vector<std::vector<string> >& rsl, std::vector<string> tempList, int index, string s) {
  if(index == s.size()) {
    rsl.push_back(tempList);
    return;
  }
  int size = s.size();
  for(int i = index; i < size; i++) {
    if(isPalindrome(s, index, i)) {
      tempList.push_back(s.substr(index, i - index + 1));
      _partition(rsl, tempList, i+1, s);
      tempList.pop_back();
    }
  }
}

std::vector<std::vector<string> > partition(string s) {
  std::vector<std::vector<string> > rsl;
  std::vector<string> tempList;
  int index = 0;
  _partition(rsl, tempList, index, s);
  return rsl;
}

int main() {
  string s;
  cin >> s;
  print(partition(s));
}
