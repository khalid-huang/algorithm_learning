#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;


void print(vector<int>& nums) {
  int size = nums.size();
  for(int i = 0; i < size; i++) {
      cout << nums[i] << " ";
  }
  cout << endl;
}

struct cmp {
    bool operator()(int &a, int &b) const {
        //因为优先出列判定为!cmp，所以反向定义实现最小值优先
        return a < b;
    }
};

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

void print(priority_queue<int, vector<int>, cmp> q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    
}

int main() {
// //   vector<int> nums;
//   nums.push_back(10);
//   nums.push_back(9);
//   nums.push_back(2);
//   nums.push_back(5);
//   nums.push_back(3);
//   nums.push_back(7);
//   nums.push_back(101);
//   nums.push_back(6);
// //   cout << lengthOfLIS(nums) << endl;

//     vector<int> nums1 = nums;
//     vector<int> nums2 = nums;
//     nums1[0] = 3;
//     cout << nums1[0] << " " << nums[0] << " " << nums2[0] << endl;
    priority_queue<int, vector<int>, cmp> q;
    q.push(1);
    q.push(2);
    print(q);
}
