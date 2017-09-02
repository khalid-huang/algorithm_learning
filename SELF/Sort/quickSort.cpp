//快排可以用于在O(n)时间里面找到第k大的元素；思想是每次只排序元素所在的那一半; 
// 参考http://blog.csdn.net/acceptyly/article/details/47838701

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

//求第k大的数字
int kthLargest(std::vector<int>& nums, int down, int up, int target) {

  int _down = down, _up = up;
  int val = nums[down];
  while(down < up) {
    while(down < up && val <= nums[up]) {
      --up;
    }
    nums[down] = nums[up];

    while(down < up && val > nums[down]) {
      ++down;
    }
    nums[up] = nums[down];
  }

  nums[down] = val;

  if(down == target) {
    return val;
  } else if(target > down) {
    return _quickSort(nums, down + 1, _up, target);
  } else {
    return _quickSort(nums, _down, down - 1, target);
  }
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
