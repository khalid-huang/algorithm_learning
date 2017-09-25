#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

int _quickSort(std::vector<int>& nums, int down, int up, int target) {

  int _down = down, _up = up;
  int val = nums[down];
  while(down < up) {
    while(down < up && val <= nums[up]) {
      --up;
    }
    nums[down] = nums[up];

    while(down < up && val > nums[down]) {
      ++down;
    }
    nums[up] = nums[down];
  }

  nums[down] = val;

  if(down == target) {
    return val;
  } else if(target > down) {
    return _quickSort(nums, down + 1, _up, target);
  } else {
    return _quickSort(nums, _down, down - 1, target);
  }
}

int findKthLargest(std::vector<int>& nums, int k) {
  int down = 0, up = nums.size(), target = nums.size() - k;
  return _quickSort(nums, down, up - 1, target);
}

int main() {
  std::vector<int> nums;
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(4);

  int k = 3;
  cout << findKthLargest(nums, k) << endl;
}
