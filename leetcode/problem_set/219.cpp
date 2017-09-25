//利用c++ set的插入操作，如果插入失败表示已经存在
//同时动态及时保证set里面与当前的数字都可以符合距离条件

#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
  set<int> set_int;
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    if(i > k) {
      set_int.erase(nums[i-k-1]);
    }
    if(!set_int.insert(nums[i]).second) {
      return true;
    }
  }
  return false;
}

int main() {
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(1);
  int k = 3;
  cout << containsNearbyDuplicate(nums, k) << endl;
}
