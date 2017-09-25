// 二分的变种，关键在于判断有序边在哪一边
// https://leetcode.com/problems/search-in-rotated-sorted-array/#/discuss
#include <iostream>
#include <vector>

using namespace std;

bool search(std::vector<int>& nums, int target) {
  if(nums.size() == 0) {
    return false;
  }

  int down = 0, up = nums.size() - 1, mid;

  while(down <= up) {
    cout << down << " " << up << endl;
    mid = down + ((up-down) >> 1);
    if(nums[mid] == target) {
      cout << nums[mid] << " " << mid << " " << target << endl;
      return true;
    }

    //左边有序,利用左边进行判断目标位置
    if(nums[down] < nums[mid]) {
      if(target >= nums[down] && target < nums[mid]) {
        up = mid - 1;
      } else {
        down = mid + 1;
      }
    } else if(nums[down] > nums[mid]){
      //右边有序，利用右边进行判断目标位置
      if(target > nums[mid] && target <= nums[up]) {
        down = mid + 1;
      } else {
        up = mid - 1;
      }
    } else {
      //相等的情况无法判断哪边有序，就小幅度增加down；
      down++;
    }
  }
  return false;
}

int main() {
  std::vector<int> nums;
  // nums.push_back(4);
  // nums.push_back(5);
  // nums.push_back(6);
  // nums.push_back(7);
  // nums.push_back(0);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  int target;
  cin >> target;
  cout << search(nums, target) << endl;
}
