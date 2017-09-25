#include <iostream>
#include <vector>

using namespace std;

int maximumGap(std::vector<int>& nums) {
  int size = nums.size();
  if(size < 2) {
    return 0;
  }

  std::vector<int> nums_backup(nums.begin(), nums.end());

  int m = nums_backup[0];
  for(int i = 1; i < size; i++) {
    m = m > nums_backup[i] ? m : nums_backup[i];
  }

  int basicExp = 1, R = 10;
  std::vector<int> aux(size);
  while(m / basicExp > 0) {
    std::vector<int> count(R, 0);

    for(int i = 0; i < size; i++) {
      count[(nums_backup[i] / basicExp) % 10]++;
    }

    for(int i = 1;i < R; i++) {
      count[i] += count[i-1];
    }

    for(int i = size - 1; i >= 0; i--) {
      aux[--count[(nums_backup[i] / basicExp)% 10]] = nums_backup[i];
    }

    for(int i = 0; i < size; i++) {
      nums_backup[i] = aux[i];
    }
    basicExp *= 10;
  }
  int rsl = 0, diff;
  for(int i = 1; i < size; i++) {
    diff = aux[i] - aux[i-1];
    rsl = rsl > diff ? rsl : diff;
  }
  return rsl;
}

int main() {
  std::vector<int> nums;
  nums.push_back(1);
  nums.push_back(10);
  nums.push_back(4);
  nums.push_back(4);
  nums.push_back(9);
  cout << maximumGap(nums) << endl;
}
