//其实就为短板效应，如果你确定了左边目前的最大值小于右边的，那边，左边的当前值可能储存的最大水量应该就是与左边的最大值的差值了（底是1的情况下）
//其实就为短板效应，如果你确定了左边目前的最大值小于右边的，那边，左边的当前值可能储存的最大水量应该就是与左边的最大值的差值了（底是
#include <iostream>
#include <vector>
using  namespace std;

int trap(std::vector<int> height) {
  int left = 0, right = height.size() - 1;
  int leftmax = 0, rightmax = 0;
  int area = 0;
  while(left < right) {
    leftmax = max(leftmax, height[left]);
    rightmax = max(rightmax, height[right]);

    if(leftmax < rightmax) {
      area += leftmax - height[left];
      ++left;
    } else {
      area += rightmax - height[right];
      ++right;
    }
  }
  return area;
}

int main() {
  std::vector<int> height;
  height.push_back(5);
  height.push_back(2);
  height.push_back(1);
  height.push_back(2);
  height.push_back(1);
  height.push_back(5);
  // height.push_back(3);
  // height.push_back(3);
  // height.push_back(2);
  // height.push_back(2);
  // height.push_back(0);
  // height.push_back(2);

  cout << trap(height) << endl;
}
