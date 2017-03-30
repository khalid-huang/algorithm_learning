#include <iostream>
#include <vector>

using namespace std;

void get_inputs(vector<int>& nums, int t) {
  int temp;
  nums.clear();
  while(t--) {
    cin >> temp;
    nums.push_back(temp);
  }
}

int getCostTime(std::vector<int> nums) {
  int nums_size = nums.size();
  int run_time = nums[0] * 6;
  int stay_time = 0;
  int diff;
  for(int i = 1; i < nums_size; i++) {
    diff = nums[i] - nums[i-1];
    if(diff > 0) {
      run_time += diff * 6;
    } else {
      run_time += (-diff) * 4;
    }
  }
  stay_time = nums_size * 5;
  return run_time + stay_time;
}

int main() {
  vector<int> nums;
  int t, total_time;
  while(cin >> t) {
    if (t == 0) {
      break;
    } else {
      get_inputs(nums, t);
      total_time = getCostTime(nums);
      cout << total_time << endl;
    }
  }
}
