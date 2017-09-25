//算法的思想是 https://yq.aliyun.com/articles/863
//找递增的序列
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector<int> nums) {
  int size= nums.size();
  for(int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void nextPermutation(std::vector<int>& nums) {
  int size = nums.size();
  if(size <= 1) {
    // return nums;
    return;
  }
  //查找到第一个递增的两元素序列
  int cur = size - 2;
  while(cur - 1 >= 0 && nums[cur] >= nums[cur+1]) {
    --cur;
  }
//   cout << cur << endl;
//如果是直接到了首元素的话，表示要回头了；但要排除[1,2]这种情况
  if(cur == 0 && nums[0] > nums[1]) {
    sort(nums.begin(), nums.end());
    return;
  }

  //查找从cur往后的，比nums[cur]大的，但最小的
  int secondIndex = cur+1;
//   cout << "secondIndex: " << secondIndex << endl;
  int i;
  for(i = cur + 2; i < size; i++) {
    if(nums[i] > nums[cur] && nums[i] < nums[secondIndex]) {
      secondIndex = i;
    }
  }
//   cout << cur << " " << secondIndex << endl;
// 在cur放最小的元素
  int temp = nums[cur];
  nums[cur] = nums[secondIndex];
  nums[secondIndex] = temp;
  //对后面的元素进行排序
  sort(nums.begin() + cur + 1, nums.end());
//   cout << "done" << endl;
  return;
}

int main() {
  std::vector<int> nums(3, 0);
  nums[0] = 3;
  nums[1] = 2;
  nums[2] = 1;
  // nums[3] = 4;
  // nums[4] = 0;
  // nums[5] = 2;
  nextPermutation(nums);
  print(nums);
}
