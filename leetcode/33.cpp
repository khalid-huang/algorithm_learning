//http://www.cnblogs.com/grandyang/p/4325648.html

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  int size = nums.size();
  if(size == 0) {
    return -1;
  }
  int middle = (size - 1) >> 1;
  // cout << nums[middle] << " " << nums[size - 1] << endl;
  int isOrderRight = nums[middle] < nums[size - 1] ? 1 : 0;
  int leftOrRight = -1;
  int down = 0, up = 0;

  //哪边有序就利用哪边来判断数字应该在哪个区域里面，非此即彼
  if(isOrderRight == 1) {
    if(target >= nums[middle] && target <= nums[size-1]) {
      leftOrRight = 1;
    } else {
      leftOrRight = -1;
    }
  } else {
    if(target <= nums[middle] && target >= nums[0]) {
      leftOrRight = -1;
    } else {
      leftOrRight = 1;
    }
  }
  cout << isOrderRight << " " << leftOrRight << endl;
   if(leftOrRight == 1) {
    down = middle;
    up = size;
  } else {
    down = 0;
    up = middle + 1;
  }

  // cout << down  << " " << up << endl;
  int rsl = -1;
  for(int i = down; i < up; i++) {
    if(target == nums[i]) {
      rsl = i;
    }
  }
  return rsl;
}

int main() {
  std::vector<int> nums(6, 0);
  nums[0] = 5;
  nums[1] = 6;
  nums[2] = 7;
  nums[3] = 1;
  nums[4] = 2;
  nums[5] = 3;

  int target;
  cin >> target;
  cout << search(nums, target) << endl;
}
