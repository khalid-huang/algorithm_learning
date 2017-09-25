#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> v) {
  int size = v.size();
  for(int i = 0;i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int minimumTotal(std::vector<std::vector<int> >& triangle) {
  int size = triangle.size();
  int size_i,  tempMin;
  for(int i = 1; i < size; i++) {
    size_i = i+1;
    for(int j = 0; j < size_i; j++) {
      if(j - 1 >= 0) {
        tempMin = triangle[i-1][j-1];
      }
      // cout << "1: " << tempMin << endl;
      if(j < size_i - 1 && (j-1<0 || (j-1>=0 && tempMin > triangle[i-1][j]))) {
        tempMin = triangle[i-1][j];
      }
      // cout << "2: " << tempMin << endl;
      triangle[i][j] += tempMin;
      tempMin = 0;
    }
    // print(triangle[i]);
  }
  int rsl = triangle[size-1][0];
  for(int i = 1; i < size; i++) {
    rsl = rsl < triangle[size-1][i] ? rsl : triangle[size-1][i];
  }
  return rsl;
}

int main() {
  std::vector<std::vector<int> > triangle;
  std::vector<int> v1;
  v1.push_back(2);
  std::vector<int> v2;
  v2.push_back(3);
  v2.push_back(4);
  std::vector<int> v3;
  v3.push_back(6);
  v3.push_back(5);
  v3.push_back(7);
  std::vector<int> v4;
  v4.push_back(4);
  v4.push_back(1);
  v4.push_back(8);
  v4.push_back(3);
  triangle.push_back(v1);
  triangle.push_back(v2);
  triangle.push_back(v3);
  triangle.push_back(v4);

  cout << minimumTotal(triangle) << endl;
}
