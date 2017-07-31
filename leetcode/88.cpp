#include <iostream>
#include <vector>

using namespace std;

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  int i = m-1, j = n-1, k = m + n - 1;
  while(i > -1 && j > -1) {
    nums1[k--] = (nums1[i] > nums2[j] ? nums1[i--] : nums2[j--]);
  }
  //如果是i多出的话，就无所谓；主要处理j多出的部分
  while(j > -1) {
    nums1[k--] = nums2[j--];
  }
}

int main() {
  int m = 4, n = 4;
  std::vector<int> nums1(m+n, 0);
  nums1[0] = 1;
  nums1[1] = 1;
  nums1[2] = 5;
  nums1[3] = 7;
  std::vector<int> nums2(n,0);
  nums2[0] = 1;
  nums2[1] = 2;
  nums2[2] = 3;
  nums2[3] = 7;

  merge(nums1, m, nums2, n);
  int count = nums1.size();
  for (size_t i = 0; i < count; i++) {
    cout << nums1[i] << " ";
  }
  cout << endl;
}
