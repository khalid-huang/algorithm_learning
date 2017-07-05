//虽然解得有点麻烦，但是算法是可以的，想想怎么用更加简洁的表达方式
//参考：https://leetcode.com/problems/median-of-two-sorted-arrays/#/solutions
//主要思路就是生成两个新的数组，leftPart和rightPart; 主要是比较的过程比较烦琐；生成的策略其实是依照了快排的方式；
//每次尽量把两个数字放进去

#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> v) {
  int size  = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

double findMedianSortedArray(std::vector<int>& nums1, std::vector<int>& nums2) {
  size_t size1 = nums1.size();
  size_t size2 = nums2.size();
  std::vector<int> leftPart, rightPart;

  int h1, h2, t1, t2, total, cur;
  total = size1 + size2;
  cur = 0;
  h1 = h2 = 0;
  t1 = size1-1, t2 = size2-1;
  while(h1 <= t1 || h2 <= t2) {
    if(h1 > t1) {
      if(h2 == t2) {
        leftPart.push_back(nums2[h2]);
        h2 += 1;
      } else {
        leftPart.push_back(nums2[h2]);
        rightPart.push_back(nums2[t2]);
        h2 += 1;
        t2 -= 1;
      }
      continue;
    }
    if(h2 > t2) {
      if(h1 == t1) {
        leftPart.push_back(nums1[h1]);
        h1 += 1;
      } else {
        leftPart.push_back(nums1[h1]);
        rightPart.push_back(nums1[t1]);
        h1 += 1;
        t1 -= 1;
      }
      continue;
    }
    if(nums1[h1] < nums2[h2]) {
      leftPart.push_back(nums1[h1]);
      h1 += 1;
    } else {
      leftPart.push_back(nums2[h2]);
      h2 += 1;
    }
    if(nums1[t1] > nums2[t2]) {
      rightPart.push_back(nums1[t1]);
      t1 -= 1;
    } else {
      rightPart.push_back(nums2[t2]);
      t2 -= 1;
    }
  }
  size1 = leftPart.size();
  size2 = rightPart.size();
  // print(leftPart);
  // print(rightPart);
  if(total & 1) {
    return leftPart[size1 - 1];
  } else {
    return (leftPart[size1 - 1] * 1.0 + rightPart[size2 - 1] * 1.0) / 2;
  }
}

int main() {
  std::vector<int> nums1;
  std::vector<int> nums2;
  nums1.push_back(1);
  // nums1.push_back(3);
  nums1.push_back(5);
  nums1.push_back(6);

  nums2.push_back(2);
  // nums2.push_back(3);
  // nums2.push_back(6);
  nums2.push_back(7);

  print(nums1);
  print(nums2);
  cout << findMedianSortedArray(nums1, nums2) << endl;
}
