#include <iostream>
#include <vector>

using namespace std;

//minPro保存了到当前最小的积，而maxPro保存了到当前最大的积；一遇到负数的时候，就要交换，因为相乘负号会改变符号
int maxProduct(std::vector<int>& nums) {
  int size = nums.size();
  int minPro = nums[0], maxPro = nums[0], r = nums[0];
  int temp;
  for(int i = 1; i < size; i++) {
    if(nums[i] < 0) {
      //swap min and max
      minPro = minPro ^ maxPro;
      maxPro = minPro ^ maxPro;
      minPro = minPro ^ maxPro;
    }
    minPro = min(nums[i], nums[i] * minPro);
    maxPro = max(nums[i], nums[i] * maxPro);

    r = max(r, maxPro);
  }
  return r;
}

int main() {
  std::vector<int> nums;
  nums.push_back(-2);
  nums.push_back(0);
  nums.push_back(2);
  cout << maxProduct(nums) << endl;
}
