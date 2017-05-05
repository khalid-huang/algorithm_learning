#include <iostream>
#include <vector>
using namespace std;

bool contain(std::vector<int> v, int val) {
  size_t size = v.size();
  for(int i = 0; i < size; i++) {
    if(v[i] == val) {
      return true;
    }
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  int nums[N];
  std::vector<int> indexs;

  for(int i = 0; i < N; i++) {
    nums[i] = 0;
  }

  int index, grade;
  for(int i = 0; i < N; i++) {
    cin >> index >> grade;
    nums[index-1] += grade;
    // if(!contain(indexs, index)) {
    //   indexs.push_back(index);
    // }
  }

  int max_grade = 0, max_index;
  // size_t size = indexs.size();
  // for(int i = 0; i < size; i++) {
  //   if(max_grade < nums[indexs[i]]) {
  //     max_grade = nums[indexs[i]];
  //     max_index = indexs[i] + 1;
  //   }
  // }
  //
  for(int i = 0; i < N; i++) {
    // cout << nums[i] << endl;
    if(nums[i] > max_grade) {
      max_grade = nums[i];
      max_index = i+1;
    }
  }
  cout << max_index << " " << max_grade << endl;
}
