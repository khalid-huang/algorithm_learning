//链表的实现可以查看 leetcode 148
#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

//分而治之，http://blog.csdn.net/jkhere/article/details/9048463
void _mergeArray(std::vector<int>& nums, int first, int mid, int last, std::vector<int>& temp) {
  int i = first, j = mid+1, k = 0;
  while(i <= mid && j <= last) {
    if(nums[i] < nums[j]) {
      temp[k++] = nums[i++];
    } else {
      temp[k++] = nums[j++];
    }
  }
  while(i <= mid) {
    temp[k++] = nums[i++];
  }
  while(j <= last) {
    temp[k++] = nums[j++];
  }

  //赋值
  for(i = 0; i < k;i++) {
    nums[first + i] = temp[i];
  }
}

void _mergeSort(std::vector<int>& nums, int first, int last, std::vector<int>& temp) {
  if(first < last) {
    int mid = (first + last) / 2;
    _mergeSort(nums, first, mid, temp);
    _mergeSort(nums, mid+1, last, temp);
    _mergeArray(nums, first, mid, last, temp);
  }
}

void mergeSort(std::vector<int>& nums) {
  int size = nums.size();
  std::vector<int> temp(size);//临时数组
  _mergeSort(nums, 0, size-1, temp);
}

int main() {
  std::vector<int> nums;
  nums.push_back(21);
  nums.push_back(7);
  nums.push_back(20);
  nums.push_back(8);
  nums.push_back(9);

  mergeSort(nums);
  print(nums);
}
