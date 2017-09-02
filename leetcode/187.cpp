//使用回溯，太超时了。到这里吧。

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


void print(std::vector<string> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

bool isContain(std::vector<string>& rsl, string s) {
  int size = rsl.size();
  for(int i = 0; i < size; i++) {
    if(rsl[i] == s) {
      return true;
    }
  }
  return false;
}

void backTrack(std::vector<string>& rsl, string s, std::vector<string>& tempList, int start) {
  //代码块1
  if(tempList.size() >= 2) {
    rsl.push_back(tempList[0]);
    return;
  }
  //代码块1

  int size = s.size(), up = size - 10, flag = 0;
  string tempS;
  for(int i = start; i <= up; i++) {
    tempS = s.substr(i, 10);
    if(isContain(rsl, tempS)) {
      continue;
    }
    flag = 0;
    if((tempList.empty() || tempList[0] == tempS)) {
      flag = 1;
      tempList.push_back(tempS);
      backTrack(rsl, s, tempList, i+1);
      tempList.pop_back();
    }
    //这里如果到了最后一次检测了，一定经强制进行一次函数，主要是去执行代码块1
    if(i == up && flag == 0) {
      backTrack(rsl, s, tempList, up+1);
    }
  }
}

//超时；
// std::vector<string> findRepeatedDnaSequences(string s) {
//   std::vector<string> rsl;
//   std::vector<string> tempList;
//   backTrack(rsl, s, tempList, 0);
//   return rsl;
// }

//这是最直接的了。
std::vector<string> findRepeatedDnaSequences(string s) {
  std::vector<string> rsl;
  if(s.size() <= 10) {
    return rsl;
  }

  int size = s.size(), up = size - 9;
  string tempS;
  map<string, int> m;
  for(int i = 0; i < up; i++) {
    tempS = s.substr(i, 10);
    if(m.find(tempS) != m.end()) {
      if(m[tempS] == 1) {
        rsl.push_back(tempS);
      }
      ++m[tempS];
    } else {
      m[tempS] = 1;
    }
  }
  return rsl;
}



int main() {
  // string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  string s = "AAAAAAAAAAAAAAAAA";
  print(findRepeatedDnaSequences(s));
}
