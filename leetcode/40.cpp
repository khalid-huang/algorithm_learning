#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void backtrack(std::vector<std::vector<int> >& rslList, std::vector<int>& tempList, std::vector<int> candidates, int target, int start) {
  if(target < 0) {
    return;
  } else if(target == 0) {
    rslList.push_back(tempList);
    return;
  } else {
    int size = candidates.size();
    for(int i = start; i < size; i++) {
      if(i > start && candidates[i] == candidates[i-1]) continue; //去除重复的情况；方法 是如果这个数字跟它前面的数字是一样的话，就直接过，因为上一次已经遍历过种数字了
      tempList.push_back(candidates[i]);
      backtrack(rslList, tempList, candidates, target - candidates[i], i+1);
      tempList.pop_back();
    }
  }
}

std::vector<std::vector<int> > combinationSum2(std::vector<int> candidates, int target) {
  std::vector<std::vector<int> > rslList;
  std::vector<int> tempList;
  backtrack(rslList, tempList, candidates, target, 0);
  return rslList;
}

void print(std::vector<std::vector<int> > v) {
  for(int i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i].size(); j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int target;
  vector<int> candidates(7, 0);
  candidates[0] = 10;
  candidates[1] = 1;
  candidates[2] = 2;
  candidates[3] = 7;
  candidates[4] = 6;
  candidates[5] = 1;
  candidates[6] = 5;
  cin >> target;
  sort(candidates.begin(), candidates.end());
  print(combinationSum2(candidates, target));
}
