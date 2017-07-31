#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(std::vector<int>& nums) {
  int i = 0, k = 0, size = nums.size();
  for(; i < size; i++) {
    if(k < 2 || nums[i] > nums[k-2]) {
      nums[k++] = nums[i];
    }
  }
  return k;
}

int main() {

  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  cout << removeDuplicates(nums) << endl;
}
