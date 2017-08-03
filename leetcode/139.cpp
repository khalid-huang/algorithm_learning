#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

bool contain(std::vector<string>& wordDict, string s) {
  int size = wordDict.size();
  for(int i = 0 ; i < size; i++) {
    if(wordDict[i] == s) {
      return true;
    }
  }
  return false;
}

//这样超时啊，其实加入剪枝的操作就可以了
// void backTrack(string s, int start, std::vector<string>& wordDict, bool& rsl, unordered_set<int>& visited) {
//   // if(rsl == true) {
//   //   return;
//   // }
//   if(start >= s.size()) {
//     rsl = true;
//     return;
//   }
//   int len = s.size() - start + 1;
//   for(int i = 1; i < len; i++) {
//     if(visited.find(start+i) == visited.end() && contain(wordDict, s.substr(start, i))) {
//       visited.insert(start + i); //这个不是用来回溯的，这个是用来判断当前是否已经进行过判断。
//       backTrack(s, start + i, wordDict, rsl, visited);
//
//     }
//   }
// }
// bool wordBreak(string s, std::vector<string>& wordDict) {
//   bool rsl = false;
//   int start = 0;
//   unordered_set<int> visited;
//   visited.insert(start);
//   backTrack(s, start, wordDict, rsl, visited);
//   return rsl;
// }

//把上面的递归式广搜改成非递归式的；使用队列，同时需要剪枝
bool wordBreak(string s, std::vector<string>& wordDict) {
  queue<int> q;
  unordered_set<int> visited;
  q.push(0);
  int start;
  while(!q.empty()) {
    start = q.front();
    q.pop();
    if(visited.find(start) == visited.end()) {
      visited.insert(start);
      for(int j = start; j < s.size(); j++) {
        if(contain(wordDict, s.substr(start, j-start+1))) {
          q.push(j+1);
          if(j+1 == s.size()) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
  string s = "leetcode";
  std::vector<string> wordDict;
  wordDict.push_back("leet");
  wordDict.push_back("code");

  cout << wordBreak(s, wordDict) << endl;
}
