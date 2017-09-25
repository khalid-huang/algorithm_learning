#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(std::vector<int>& nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int longestConsecutive(std::vector<int>& nums) {
  if(nums.size() == 0) {
    return 0;
  }

  sort(nums.begin(), nums.end());
  int count = 1, maxCount = 1, size = nums.size(), pre = nums[0];
  for(int i = 1; i < size; i++) {
    while(i < size && nums[i] == nums[i-1]) {
      ++i;
    }
    if(nums[i] - pre == 1) {
      ++count;
    }
    if(nums[i] - pre != 1 || i == size - 1) {
      maxCount = max(maxCount, count);
      count = 1;
      ++i;
    }
    pre = nums[i];
  }
  return maxCount;
}

int main() {
  std::vector<int> nums;
  nums.push_back(100);
  nums.push_back(4);
  nums.push_back(200);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);

  cout << longestConsecutive(nums) << endl;
}
