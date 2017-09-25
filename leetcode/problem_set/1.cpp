#include <iostream>
#include <vector>
using namespace std;

void print(std::vector<int> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int findIndex(std::vector<int>& nums, int target, int except) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    if(target == nums[i] && except != i) {
      return i;
    }
  }
  return -1;
}

std::vector<int> twoSum(vector<int>& nums, int target) {
  int size = nums.size(), diff, pos;
  std::vector<int> rsl;
  for(int i = 0; i < size; i++) {
    diff = target - nums[i];
    pos = findIndex(nums, diff, i);
    if(pos != -1) {
      rsl.push_back(i);
      rsl.push_back(pos);
      break;
    }
  }
  return rsl;
}

int main() {
  std::vector<int> v;
  v.push_back(2);
  v.push_back(7);
  v.push_back(11);
  print(twoSum(v, 9));
}
