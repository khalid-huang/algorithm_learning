#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<int> rsl) {
  int size = rsl.size();
  for(int i = 0;i < size; i++) {
    cout << rsl[i] << " ";
  }
  cout << endl;
}

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
  std::vector<int> index(2);
  int left = 0, right = numbers.size() - 1, temp;
  while(left < right) {
    temp = numbers[left] + numbers[right];
    if(temp == target) {
      index[0] = left+1;
      index[1] = right+1;
      break;
    } else if(temp > target) {
      --right;
    } else {
      ++left;
    }
  }
  return index;
}

int main() {
  std::vector<int> numbers;
  numbers.push_back(2);
  numbers.push_back(7);
  numbers.push_back(11);
  numbers.push_back(15);

  int target = 18;
  print(twoSum(numbers, target));
}
