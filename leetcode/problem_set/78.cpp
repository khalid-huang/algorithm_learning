#include <iostream>
#include <vector>

using namespace std;
void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

void backTrack(std::vector<std::vector<int> >& rsl, std::vector<int> tempList, std::vector<int> nums,int start) {
  rsl.push_back(tempList);
  int size = nums.size();
  for(int i = start; i < size; i++) {
    tempList.push_back(nums[i]);
    backTrack(rsl, tempList, nums, i+1);
    tempList.pop_back();
  }
}

std::vector<std::vector<int> > subsets(std::vector<int> nums) {
  std::vector<std::vector<int> > rsl;
  std::vector<int> tempList;
  int start = 0;
  backTrack(rsl, tempList, nums, start);
  return rsl;
}

int main() {
  std::vector<int> nums(3,0);
  nums[0] = 1;
  nums[1] = 2;
  nums[2] = 3;

  print(subsets(nums));
}
