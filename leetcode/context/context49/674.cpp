#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(std::vector<int>& nums) {
  int size = nums.size(), maxLen = 1;
  if(size == 0) {
    return 0;
  }
  std::vector<int> lens(size, 1);
  for(int i = 1; i < size; i++) {
    if(nums[i] > nums[i-1]) {
      lens[i] = lens[i-1] + 1;
      maxLen = max(maxLen, lens[i]);
    }
  }
  return maxLen;
}

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  v.push_back(4);
  v.push_back(7);

  cout << findLengthOfLCIS(v) << endl;
}
