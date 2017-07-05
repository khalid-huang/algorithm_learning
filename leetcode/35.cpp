#include <iostream>
#include <vector>

using namespace std;

//变种的二分，尽量往下找，找到相等的第一个或是不相等的，比它小的，但最大的；
int searchInsert(std::vector<int>& nums, int target) {
  int down = 0, up = nums.size() - 1, middle;

  while(down < up) {
    middle = down + ((up - down) >> 1); //移位的优先级比加法低的
    // middle = (down + up) / 2;
    // cout << down << "-" << up << "-" << middle << endl;
    // cout << target << "-" << nums[middle] << endl;
    if(target <= nums[middle]) {
      up = middle;
    } else {
      down = middle + 1;
    }
  }
  // cout << up << endl;
  if(nums[up] == target) {
    return up;
  } else if(target < nums[up]){
    return up;
  } else {
    return up + 1;
  }
}

int main() {
  std::vector<int> nums(1, 0);
  nums[0] = 1;
  // nums[1] = 3;
  // nums[2] = 5;
  // nums[3] = 6;
  int target;
  cin >> target;
  cout << searchInsert(nums, target) << endl;
}
