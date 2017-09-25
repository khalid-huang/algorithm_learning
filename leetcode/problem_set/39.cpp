#include <iostream>
#include <vector>

using namespace std;

void backtrack(std::vector<std::vector<int> >& rslList, std::vector<int> tempList, std::vector<int> candidates, int start, int target) {
  if(target < 0) {
    return;
  } else if(target == 0) {
    rslList.push_back(tempList);
  } else {
    int size = candidates.size();
    for(int i = start; i < size; i++) {
      tempList.push_back(candidates[i]);
      backtrack(rslList, tempList, candidates, i, target - candidates[i]);
      tempList.pop_back(); //回溯；不管是成功还是不成功都会回溯的
    }
  }
}

std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
  std::vector<std::vector<int> > rslList;
  std::vector<int> tempList;
  backtrack(rslList, tempList, candidates, 0, target);
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
  vector<int> candidates(4, 0);
  candidates[0] = 2;
  candidates[1] = 3;
  candidates[2] = 6;
  candidates[3] = 7;
  cin >> target;
  print(combinationSum(candidates, target));
}
