#include <iostream>
#include <vector>

using namespace std;


void print(vector<int>& nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
      cout << nums[i] << " ";
  }
  cout << endl;
}

int lengthOfLIS(vector<int>& nums)  {
  vector<int> tails(nums.size(), 0);
  int size = 0, x;
  for (int k = 0; k < nums.size(); k++) {
      x = nums[k];
      int i = 0, j = size;
      while (i != j) {
          int m = (i + j) / 2;
          if (tails[m] < x)
              i = m + 1;
          else
              j = m;
      }
      tails[i] = x;
      if (i == size) ++size;
  }
  print(tails);
  return size;
}

int main() {
  vector<int> nums;
  nums.push_back(10);
  nums.push_back(9);
  nums.push_back(2);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(7);
  nums.push_back(101);
  nums.push_back(6);
  cout << lengthOfLIS(nums) << endl;
}
