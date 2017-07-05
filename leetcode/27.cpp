#include <iostream>
#include <vector>

using namespace std;

int removeElement(std::vector<int> nums, int val) {
  int cur = 0, newIndex = 0;
  int size = nums.size();
  while(cur < size) {
    if(nums[cur] == val) {
      ++cur;
    } else {
      nums[newIndex] = nums[cur];
      ++newIndex;
      ++cur;
    }
  }
  return newIndex;
}

int main() {

  std::vector<int> nums(4,0);
  nums[0] = 1;
  nums[1] = 1;
  nums[2] = 2;
  nums[3] = 3;
  int val;
  cin >> val;
  cout << removeElement(nums, val) << endl;
}
