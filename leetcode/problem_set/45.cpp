#include <iostream>
#include <vector>

using namespace std;

int jump(std::vector<int>& nums) {
  int size = nums.size();

  //curMax表示目前可以到达的最远的地方；
  //i表示当前到达的位置
  int curMax = 0, i = 0, nextMax = -1, level = 0;
  while(curMax - i + 1 > 0) {
    ++level;
    for(; i <= curMax; i++) {
      nextMax = max(nextMax , nums[i] + i);
      if(nextMax >= size - 1) {
        return level;
      }
    }
    curMax = nextMax;
  }
  return 0;
}

int main() {
  std::vector<int> nums(5,0);
  nums[0] = 2;
  nums[1] = 3;
  nums[2] = 1;
  nums[3] = 1;
  nums[4] = 4;

  cout << jump(nums) << endl;
}
