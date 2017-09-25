#include <iostream>
#include <vector>

using namespace std;

//算法比较简单，就是从每个位置开始往后找，直到找到符合条件的，然后测试下它的大小和是不是满足
int minSubArrayLen(int s, std::vector<int>& nums) {
  int size = nums.size();
  int len = size + 1, cur, sum;
  for(int i = 0; i < size; i++) {
    cur = i;
    sum = nums[cur];
    while(cur + 1 < size && sum < s) {
      sum += nums[++cur];
    }
    if(sum < s) {
      break;
    } else {
      // cout << cur  << " " << i << endl;
      len = len > (cur - i + 1) ? cur - i + 1 : len;
    }
  }
  return len == (size + 1) ? 0 : len;
}

int main() {
  int s;
  std::vector<int> nums;
  s = 7;
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(3);

  cout << minSubArrayLen(s, nums) << endl;
}
