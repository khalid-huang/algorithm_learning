//分析内在的关联

#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int down = 0, up = height.size() - 1, rsl = 0;
  while(down < up) {
    rsl = max(rsl, min(height[down], height[up]) *(up-down));
    cout << up << "-" << down << endl;
    cout << rsl << endl;
    if(height[down] < height[up]) {
      ++down;
    } else {
      --up;
    }
  }
  return rsl;
}

int main() {
  std::vector<int> height;
  // height.push_back(2);
  height.push_back(1);
  height.push_back(2);
  height.push_back(4);
  height.push_back(3);

  cout << maxArea(height) << endl;
}
