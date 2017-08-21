//链表的实现可以查看leetcode 147
#include <iostream>
#include <vector>

using namespace std;

//插入排序就是一边当有序，一边无序，每次从无序里面取第一个数字排入到有序的一边；从后往前找，这样可以把找数和移动结合起来
void insertSort(std::vector<int>& nums) {
  int size = nums.size();
  int temp, j;
  for(int i = 1; i < size; i++) {
    temp = nums[i];
    j = i-1;
    while(j >= 0 && temp < nums[j]) {
      nums[j+1] = nums[j]; //后移
      --j;
    }
    nums[j+1] = temp;
  }
}

void print(std::vector<int> nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  std::vector<int> nums;
  nums.push_back(21);
  nums.push_back(7);
  nums.push_back(20);
  nums.push_back(8);
  nums.push_back(9);

  insertSort(nums);
  print(nums);
}
