#include <iostream>
#include <vector>

using namespace std;

void backTrack(std::vector<int>& nums, std::vector<std::vector<int> >& rsl, std::vector<int>& tempList, int start) {
  rsl.push_back(tempList);
  int size = nums.size();
  for(int i = start; i < size; i++) {
    if(i != start && nums[i] == nums[i-1]) { //防止重复
      continue;
    }
    tempList.push_back(nums[i]);
    backTrack(nums, rsl, tempList, i+1);
    tempList.pop_back();
  }
}

std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums) {
  std::vector<std::vector<int> > rsl;
  std::vector<int> tempList;
  int start = 0;
  sort(nums.begin(),nums.end());
  backTrack(nums, rsl, tempList, start);
  return rsl;
}

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

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(4);
  v.push_back(4);
  v.push_back(4);

  print(subsetsWithDup(v));
}
