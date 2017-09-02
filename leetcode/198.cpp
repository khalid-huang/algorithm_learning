#include <iostream>
#include <vector>

using namespace std;

//对于要不就使用前面奇数的和，要不使用前面偶数加上自己的值
int rob(std::vector<int>& nums) {
  int size = nums.size();
  int even = 0, odd = 0;
  for(int i = 0; i < size; i++) {
    if(i & 1) {
      //奇数
      odd = max(even, odd+nums[i]);
    } else {
      //偶数
      even = max(odd, even+nums[i]);
    }
  }
  return max(odd, even);
}

int main() {
  std::vector<int> nums;
  nums.push_back(8);
  nums.push_back(7);
  nums.push_back(5);
  nums.push_back(9);
  nums.push_back(6);
  nums.push_back(4);

  cout << rob(nums) << endl;
}
