//这种循环的打法厉害，可以好好学一下，固定一个数字，其他两个根据这个数字的情况进行坐标改变
//size_t是一个无符号正数，所以当size_t size = 0时，使用size-2会得到一个很大的数字
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void printV(std::vector<int> v) {
  size_t size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector< vector<int> > threeSum(std::vector<int>& nums) {
  vector< vector<int> > rsl;
  size_t size = nums.size();
  cout << size << endl;
  sort(nums.begin(), nums.end());
  // printV(nums);
  int target, front, back, twoSum;
  for(int i = 0; i < size - 2; i++) {
    cout << i << "-" << size - 2 << endl;
    cout << "lll" << endl;
    target = -nums[i];
    front = i+1;
    back = size - 1;
    // cout << i << "-" << front << "-" << back << endl;
    while(front < back) {
      twoSum = nums[front] + nums[back];
      // if(i == 1) {
      //   cout << front << "-" << back << endl;
      //   cout << twoSum << ":" << target << endl;
      // }

      if(twoSum < target) {
        ++front;
      } else if(twoSum > target) {
        --back;
      } else {
        // cout << "一次" << endl;
        vector<int> triple(3, 0);
        triple[0] = nums[i];
        triple[1] = nums[front];
        triple[2] = nums[back];

        rsl.push_back(triple);

        //过掉重复的项
        while(front < back && nums[front] == triple[1]) {
          ++front;
        }
        while(front < back && nums[back] == triple[2]) {
          --back;
        }
      }
    }

    while(i < size - 2 && nums[i+1] == -target) {
      ++i;
    }
  }

  return rsl;
}

void print(vector< vector<int> > rsl) {
  size_t size = rsl.size();
  for(int i = 0; i < size; i++) {
    size_t size1 = rsl[i].size();
    cout << "[ ";
    for(int j = 0; j < size1; j++) {
      cout << rsl[i][j] << ", ";
    }
    cout << "]" << endl;
  }
}


int main() {
  // std::vector<int> nums(6,0);
  // nums[0] = -1;
  // nums[1] = 0;
  // nums[2] = 1;
  // nums[3] = 2;
  // nums[4] = -1;
  // nums[5] = -4;

  std::vector<int> nums;
  print(threeSum(nums));
}
