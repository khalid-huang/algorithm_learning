#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > fourNum(std::vector<int>& nums, int target) {
  vector< vector<int> > rsl;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  int twoTarget, twoSum, back, front, pre_vi, pre_vj;
  for(int i = 0; i < size - 3; i++) {
    for(int j = i+1; j < size - 2; j++) {
      twoTarget = target - nums[i] - nums[j];

      front = j + 1;
      back = size - 1;
      while(front < back) {
        twoSum = nums[front] + nums[back];
        if(twoSum < twoTarget) {
          ++front;
        } else if(twoSum > twoTarget) {
          --back;
        } else {
          // cout << twoSum << " " << twoTarget << endl;
          // cout << i << "-" << j << "-" << front << "-" <<  back << endl;
          // cout << endl;
          vector<int> fourNum(4,0);
          fourNum[0] = nums[i];
          fourNum[1] = nums[j];
          fourNum[2] = nums[front];
          fourNum[3] = nums[back];

          rsl.push_back(fourNum);
          while(front < back && nums[front] == fourNum[2]) {
            ++front;
          }
          while(front < back && nums[back] == fourNum[3]) {
            --back;
          }
        }
      }

      pre_vj = nums[j];
      while(j < size - 2 && nums[j+1] == pre_vj) {
        j++;
      }
    }
    pre_vi == nums[i];
    while(i < size - 3 && nums[i+1] == pre_vi) {
      i++;
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
  std::vector<int> nums(6,0);
  nums[0] = 1;
  nums[1] = 0;
  nums[2] = -1;
  nums[3] = 0;
  nums[4] = -2;
  nums[5] = 2;
  print(fourNum(nums, 0));
}
