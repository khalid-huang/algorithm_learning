#include <iostream>
#include <vector>

using namespace std;

void binarySearch(std::vector<int>& nums, int first, int last, int& rsl) {
  cout << first << "-" << last << endl;
  if(first == last) {
    rsl = nums[first];
    return;
  }
  int mid = first + (last - first) / 2;
  cout << "#" << nums[mid] << "-" << nums[last] << endl;
  if(nums[mid] < nums[last]) { //从mid到last有序
    binarySearch(nums, first, mid, rsl);
  } else {
    binarySearch(nums, mid+1, last, rsl);
  }

}

int findMin(std::vector<int>& nums) {
  int first = 0, last = nums.size() - 1;
  int rsl;
  binarySearch(nums, 0, last, rsl);
  return rsl;
}

int main() {
  std::vector<int> nums;
  nums.push_back(4);
  // nums.push_back(5);
  // nums.push_back(6);
  // nums.push_back(0);
  // nums.push_back(1);
  // nums.push_back(2);

  cout << findMin(nums) << endl;
}
