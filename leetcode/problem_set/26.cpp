#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(std::vector<int> nums) {
  int size = nums.size();
  if(size == 0) {
    return 0;
  }

  int cur = 1, val = nums[0], rsl = 1;
  while(cur < size) {
    if(val != nums[cur]) {
      ++rsl;
      nums[rsl-1] = nums[cur]; //不能重新开空间，就让这个新的数字进入确定的位置；
      val = nums[cur];
      ++cur;
    } else {
      ++cur;
    }
  }
  return rsl;
}

int main() {
  std::vector<int> nums(4,0);
  nums[0] = 1;
  nums[1] = 1;
  nums[2] = 2;
  nums[3] = 3;

  cout << removeDuplicates(nums) << endl;
}
