#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(std::vector<int>& nums) {
  int curSum = nums[0], maxSum = nums[0], tempSum;
  int size = nums.size();
  for(int i = 1; i < size; i++) {
    if(curSum >= 0) {
      curSum = curSum + nums[i];
    } else {
      curSum = nums[i];
    }
    if(curSum > maxSum) {
      maxSum = curSum;
    }
  }
  return maxSum;
}

int main() {

}
