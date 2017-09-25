#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print(std::vector<int> v) {
  int v_size = v.size();
  for(int i = 0; i < v_size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

//这个题目的关键在于对每一个位置都进行一次全部的匹配，如果匹配成功就可以加入结果集，如果不可以就往下
std::vector<int> findSubstring(string s, std::vector<string>& words) {
  map<string, int> str_num;
  int word_num = words.size();
  //初始化
  for(int i = 0; i < word_num; i++) {
    if(str_num.find(words[i]) == str_num.end()) {
      str_num[words[i]] = 1;
    } else {
      ++str_num[words[i]];
    }
  }
  cout << str_num["good"] << endl;
  map<string, int> str_num_copy = str_num;
  int word_size = words[0].size();
  int s_size = s.size(), up = s_size - word_size * word_num + 1;
  string subStr;
  std::vector<int> rsl;
  int start, count;
  for(int i = 0; i < up; i++) {
    start = i;
    subStr = s.substr(start, word_size);
    cout << "sub: " << subStr << endl;
    count = 0;
    while(str_num.find(subStr) != str_num.end() && str_num[subStr] > 0) {
      --str_num[subStr];
      cout << subStr << " " << str_num[subStr] << endl;
      ++count;
      start = start + word_size;
      subStr = s.substr(start, word_size);
      cout << "nsub: " << subStr << endl;
    }
    if(count == word_num) {
      cout << "k" << endl;
      rsl.push_back(i);
    }
    if(count > 0) {
      // cout << str_num["foo"] << endl;
      str_num = str_num_copy;
      // cout << str_num["foo"] << endl;
    }
  }

  return rsl;
}

int main() {
  string s;
  // cin >> s;
  s = "wordgoodgoodgoodbestword";
  std::vector<string> words(4,"");
  words[0] = "word";
  words[1] = "good";
  words[2] = "best";
  words[3] = "good";
  print(findSubstring(s, words));
}
