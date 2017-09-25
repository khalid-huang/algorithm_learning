#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(std::vector<int>& array, int target) {
  int down = 0, up  = array.size() - 1, middle;
  while(down <= up) {
    middle = down + ((up - down) >> 1); //位移的优先级是很低的
    // cout << down << " " << middle << " " << up << endl;
    if(array[middle] == target) {
      return true;
    } else if(array[middle] < target){
      down = middle + 1;
    } else {
      up = middle - 1;
    }
  }
  return false;
}

bool searchMatrix(std::vector<std::vector<int> >& matrix, int target) {
  int cur = 0, size = matrix.size();
  if(size == 0) {
    return false;
  }
  while(cur + 1 < size) {
    if(matrix[cur+1][0] > target) {
      break;
    } else {
      ++cur;
    }
  }
  cout << cur << endl;
  return binarySearch(matrix[cur], target);
}

int main() {
  std::vector<std::vector<int> > matrix;
  std::vector<int> v1;
  v1.push_back(1);
  v1.push_back(1);
  // v1.push_back(5);
  // v1.push_back(7);
  // std::vector<int> v2;
  // v2.push_back(10);
  // v2.push_back(11);
  // v2.push_back(16);
  // v2.push_back(20);
  // std::vector<int> v3;
  // v3.push_back(23);
  // v3.push_back(30);
  // v3.push_back(34);
  // v3.push_back(50);
  matrix.push_back(v1);
  // matrix.push_back(v2);
  // matrix.push_back(v3);
  // cout << binarySearch(v1, 3) << endl;
  int target;
  cin >> target;
  cout << searchMatrix(matrix, target) << endl;
}
