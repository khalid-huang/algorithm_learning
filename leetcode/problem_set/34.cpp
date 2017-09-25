#include <iostream>
#include <vector>

using namespace std;


//两个二分查找，其不同是在于如果nums[middle]等于target的话，对于查找第一个，其方式是往左走(更新j)；而对于找最后一个是往右走(更新i); 修改二分搜索，让其一直找， 直到全部遍历完，而不是找到就中止
std::vector<int> searchRange(std::vector<int> nums, int target) {
  std::vector<int> rsl(2, -1);
  int size = nums.size();
  int i = 0, j = size - 1, middle;
  cout << middle << endl;
  while(i < j) {
    middle = (j + i) >> 1;
    cout << middle << endl;
    cout << middle << "-" << i << "-" << j << endl;
    if(target <= nums[middle]) {
      j = middle;
    } else {
      i = middle + 1; //因为target != nums[middle]
    }
  }
  if(nums[j] != target) {
    return rsl;
  }
  rsl[0] = i;

  j = size - 1;
  while(i < j) {
    middle = (j + i) / 2 + 1; //让其选择右边那个
    cout << middle << "-" << i << "-" << j << "-" << middle << endl;
    if(target < nums[middle]) {
      j = middle - 1; //因为target != middle[middle]
    } else {
      i = middle; // 往下走
    }
  }

  if(nums[i] != target) {
    return rsl;
  }
  rsl[1] = i;
  return rsl;
}

void print(std::vector<int> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  std::vector<int> nums(6, 0);
  nums[0] = 5;
  nums[1] = 7;
  nums[2] = 7;
  nums[3] = 8;
  nums[4] = 8;
  nums[5] = 10;

  int target;
  cin >> target;
  print(searchRange(nums, target));

}
