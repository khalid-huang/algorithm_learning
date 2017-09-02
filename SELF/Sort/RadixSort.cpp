//https://www.cs.usfca.edu/~galles/visualization/RadixSort.html
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

//O(n)
void radixSort(std::vector<int>& nums) {
  int size = nums.size();
  int m = nums[0];
  for(int i = 1; i < size; i++) {
    m = m > nums[i] ? m : nums[i];
  }

  int basicExp = 1, R = 10;
  std::vector<int> aux(size);

  while(m / basicExp > 0) { //针对每一位进行排序
    std::vector<int> count(R, 0);
    //统计
    for(int i = 0; i < size; i++) {
      count[(nums[i] / basicExp) % 10]++;
    }
    //进行位置确认
    for(int i = 1; i < R; i++) {
      count[i] += count[i-1];
    }

    //放入aux中
    for(int i = size - 1; i >= 0; i--) {
      aux[--count[(nums[i] / basicExp) % 10]] = nums[i];
    }

    //放回nums
    for(int i = 0; i < size; i++) {
      nums[i] = aux[i];
    }

    basicExp *= 10;
  }
}

int main() {
  std::vector<int> nums;
  nums.push_back(21);
  nums.push_back(7);
  nums.push_back(20);
  nums.push_back(8);
  nums.push_back(9);

  radixSort(nums);
  print(nums);
}
