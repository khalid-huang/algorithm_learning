#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int>& v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int getFirstLeast(int index, std::vector<int>& nums) {
  int val = nums[index], i = index - 1;
  while(i >= 0 && nums[i] >= val) {
    i--;
  }
  return i;
}

int findNumberOfLCIS(std::vector<int>& nums) {
  int size = nums.size();
  if(size == 0) {
    return 0;
  }
  int maxLen = 1, temp, lastIndex = 0, maxIndex = 0;
  std::vector<int> counts(size, 1);
  for(int i = 1; i < size; i++) {
    lastIndex = getFirstLeast(i, nums);
    temp = lastIndex == -1 ? 0 : counts[lastIndex];
    counts[i] =  temp + 1;
    if(maxLen < counts[i]) {
      maxLen = counts[i];
      maxIndex = i;
    }
  }
  //count maxLen nums
  int maxCount = 0, j = maxIndex;
  while(j != size) {
    if(nums[j++] == nums[maxIndex]) {
      maxCount++;
    }
  }

  //cal the maxLen-1 nums;
  int secondCount = 0;
  for(int i = 0; i < size; i++) {
    if(counts[i] == maxLen - 1 && nums[i] < nums[maxIndex]) {
      ++secondCount;
    }
  }
  print(counts);
  secondCount = secondCount == 0 ? 1 : secondCount;
  cout << secondCount << " " << maxCount << endl;
  return secondCount * maxCount;
}

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(4);
  v.push_back(3);
  v.push_back(5);
  v.push_back(4);
  v.push_back(7);
  v.push_back(2);

  cout << findNumberOfLCIS(v) << endl;
}
