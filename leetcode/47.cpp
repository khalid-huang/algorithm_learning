//排序去重
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(std::vector<int>& nums, std::vector<int>& tempList, std::vector<std::vector<int> >& rsl, bool used[]) {
  if(tempList.size() == nums.size()) {
    rsl.push_back(tempList);
  } else {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
      //前面的数字跟它相同，而且前面已经加过（已经回溯过了）
      if(used[i] == true || (i > 0 && nums[i] == nums[i-1] && used[i-1] == false)) continue;
      tempList.push_back(nums[i]);
      used[i] = true;
      backtrack(nums, tempList, rsl, used);
      tempList.pop_back();
      used[i] = false;
    }
  }
}

std::vector<std::vector<int> > permute(std::vector<int>& nums) {
  sort(nums.begin(), nums.end());

  std::vector<int> tempList;
  std::vector<std::vector<int> > rsl;
  int size = nums.size();
  bool used[size];
  for(int i = 0; i < size; i++) {
    used[i] = false;
  }
  backtrack(nums, tempList, rsl, used);
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
  std::vector<int> nums(3,0);
  nums[0] = 1;
  nums[1] = 1;
  nums[2] = 2;
  print(permute(nums));

}
