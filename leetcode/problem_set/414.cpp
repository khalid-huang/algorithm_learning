#include <iostream>
#include <vector>

using namespace std;

int thirdMax(std::vector<int>& nums) {
  long max1 = -2147483649, max2 = -2147483649, max3 = -2147483649;
  int size = nums.size();
  cout << max1 << endl;
  for(int i = 0; i < size; i++) {
    if(max1 == nums[i] || max2 == nums[i] || max3 == nums[i]) {
      continue;
    }
    if(nums[i] > max1) {
      max3 = max2;
      max2 = max1;
      max1 = nums[i];
    } else if(nums[i] > max2) {
      max3 = max2;
      max2 = nums[i];
    } else if(nums[i] > max3) {
      max3 = nums[i];
    }
  }
  cout << max1 << " " << max2 << " " << max3 << endl;
  return max3 == -2147483649 ? max1 : max3;
}

int main() {
  std::vector<int> nums;
  // nums.push_back(2);
  nums.push_back(2);
  // nums.push_back(3);
  nums.push_back(1);
  nums.push_back(-2147483648);

  cout << thirdMax(nums) << endl;
}
