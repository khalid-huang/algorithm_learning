#include <iostream>
#include <vector>

using namespace std;

void sortColors(std::vector<int>& nums) {
  int count[3] = {0,0,0};
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    ++count[nums[i]];
  }
  int k = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0;j < count[i]; j++) {
      nums[k++] = i;
    }
  }
}

int main() {
  std::vector<int> nums(6,0);
  nums[0] = 1;
  nums[1] = 0;
  nums[2] = 1;
  nums[3] = 1;
  nums[4] = 2;
  nums[5] = 2;
  sortColors(nums);
  int size = nums.size();
  for(int i = 0;i < size; i++) {
    cout << nums[i];
  }
}
