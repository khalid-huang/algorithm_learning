#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(std::vector<int>& nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    if((i - 1 < 0 || nums[i] > nums[i-1]) && (i+1 == size || nums[i] > nums[i+1])) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> nums;
  nums.push_back(1);
  // nums.push_back(2);
  // nums.push_back(3);
  // nums.push_back(1);
  cout << findPeakElement(nums) << endl;
}
