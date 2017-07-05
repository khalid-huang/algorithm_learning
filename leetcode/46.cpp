#include <iostream>
#include <vector>

using namespace std;

bool contains(std::vector<int> tempList, int num) {
  int size = tempList.size();
  for(int i = 0; i < size; i++) {
    if(tempList[i] == num) {
      return true;
    }
  }
  return false;
}

void backtrack(std::vector<int>& nums, std::vector<int>& tempList, std::vector<std::vector<int> >& rsl) {
  if(tempList.size() == nums.size()) {
    rsl.push_back(tempList);
  } else {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
      if(contains(tempList, nums[i])) {
        continue;
      } else {
        tempList.push_back(nums[i]);
        backtrack(nums, tempList, rsl);
        tempList.pop_back();
      }
    }
  }
}

std::vector<std::vector<int> > permute(std::vector<int>& nums) {
  std::vector<int> tempList;
  std::vector<std::vector<int> > rsl;
  backtrack(nums, tempList, rsl);
  return rsl;
}

void print(std::vector<std::vector<int> > rsl) {
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
  std::vector<int> nums(3, 0);
  nums[0] = 1;
  nums[1] = 2;
  nums[2] = 3;
  print(permute(nums));

}
