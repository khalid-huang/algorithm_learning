#include <iostream>
#include <vector>

using namespace std;

//这个问题其实分解一下就是去计算从nums[0]到nums[size-2]的最大值和num[1]到nums[size-1]的最大值哪个大
int rob(std::vector<int> nums) {
  if(nums.size() == 0) {
    return 0;
  }
  if(nums.size() == 1) {
    return nums[0];
  }

  int size = nums.size(), pre1 = 0, temp1 = 0, cur1 = 0;
  for(int i = 0; i < size - 1; i++) {
    // cur1 = max(cur1, pre+nums[i]); 这是公式,下面是实现
    temp1 = pre1;
    pre1 = cur1;
    cur1 = max(pre1, temp1 + nums[i]);
  }
  int pre2 = 0, temp2 = 0, cur2 = 0;
  for(int i = 1; i < size; i++) {
    temp2 = pre2;
    pre2 = cur2;
    cur2 = max(pre2, temp2 + nums[i]);
  }
  return max(cur2, cur1);
}

int main() {
  std::vector<int> num;
  num.push_back(1);
  num.push_back(4);
  num.push_back(5);
  num.push_back(3);
  num.push_back(6);
  cout << rob(num) << endl;
}
