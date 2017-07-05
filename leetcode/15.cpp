#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int abs(int val) {
  return val < 0 ? -val : val;
}

int threeSumCLosest(std::vector<int>& nums, int target) {
  int size = nums.size();

  int diff = -1, closest;
  int twoTarget, front, back, tempDiff, twoSum;

  sort(nums.begin(), nums.end());
  for(int i = 0; i < size - 2; i++) {
    twoTarget = target - nums[i];
    front = i+1;
    back = size - 1;
    while(front < back) {
      twoSum = nums[front] + nums[back];
      tempDiff = abs(twoTarget - twoSum);
      if(diff == -1 || tempDiff < diff) {
        diff = tempDiff;
        closest = nums[i] + nums[front] + nums[back];
      }
      if(twoSum < twoTarget) {
        ++front;
      } else {
        --back;
      }
    }
  }
  return closest;
}

int main() {
  std::vector<int> nums(4,0);
  nums[0] = -1;
  nums[1] = 2;
  nums[2] = 1;
  nums[3] = -4;
  cout << threeSumCLosest(nums, 1) << endl;
}
