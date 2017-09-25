#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

void backTrack(std::vector<std::vector<int> >& rsl, std::vector<int>& tempList, int start, int nums, int target) {
  if(tempList.size() == nums && target != 0) {
    return;
  }
  if(tempList.size() == nums && target == 0) {
    rsl.push_back(tempList);
    return;
  }

  for(int i = start; i < 10; i++) {
    if(target >= i) {
      tempList.push_back(i);
      backTrack(rsl, tempList, i+1, nums, target - i);
      tempList.pop_back();
    } else {
      break;
    }
  }
}

std::vector<std::vector<int> > combinationSum(int k, int n) {
  std::vector<std::vector<int> > rsl;
  std::vector<int> tempList;
  backTrack(rsl, tempList, 1, k, n);
  return rsl;
}

int main() {
  int k, n;
  k = 3, n = 9;
  print(combinationSum(k,n));
}
