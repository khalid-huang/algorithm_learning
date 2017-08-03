#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int>& nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void _quickSort(std::vector<int>& nums, int down, int up) {
  if(down > up) {
    return;
  }
  int key = nums[down];
  int _down = down;
  int _up = up;
  while(down < up) {
    //这里空出了down这个位置，从右边找一人数字来填充;特别要注意的是要加上那个down < up的这个条件
    while(down < up && nums[up] >= key) {
      --up;
    }
    nums[down] = nums[up];

    //此时nums[up]这个位置也是可以填充的
    while(down < up && nums[down] < key) {
      ++down;
    }
    nums[up] = nums[down];
  }

  nums[down] = key;
  _quickSort(nums, _down, down-1);
  _quickSort(nums, down+1, _up);
}

void quickSort(std::vector<int>& nums) {
  int down = 0, up = nums.size() - 1;
  _quickSort(nums, down ,up);
  return;
}

int main() {
  std::vector<int> nums;
  nums.push_back(10);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(7);
  quickSort(nums);
  print(nums);
}
