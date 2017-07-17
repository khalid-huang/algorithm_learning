//这个题目需要进行剪枝，一个是在范围判断上，一个是访问上

#include <iostream>
#include <vector>

using namespace std;

void backTrack(std::vector<int>& nums, int& flag, int* visited, int position) {

  if(position + nums[position] >= nums.size() - 1) { //剪枝
    flag = 1;
    return;
  }
  int size =  nums.size();
  for(int i = 1; i <= nums[position]; i++) {
    if(position+i <= size - 1 && visited[position+i] == 0) { //剪枝
      visited[position+i] = 1;
      backTrack(nums, flag, visited, position+i);
    }
  }
}

bool canJump(std::vector<int>& nums) {
  int flag = 0;
  int size = nums.size();
  int visited[size];
  for(int i = 0; i < size; i++) {
    visited[i] = 0;
  }
  visited[0] = 1;
  backTrack(nums, flag, visited, 0);
  return flag == 1 ? true : false;
}

int main() {
  std::vector<int> nums(5,0);
  nums[0] = 3;
  nums[1] = 2;
  nums[2] = 1;
  nums[3] = 0;
  nums[4] = 4;

  cout << canJump(nums) << endl;
}
