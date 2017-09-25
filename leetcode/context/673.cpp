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

int findNumberOfLCIS(std::vector<int>& nums) {

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
