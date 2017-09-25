#include <iostream>
#include <vector>

using namespace std;

int calNums(int size, int target, std::vector<int>& cakes) {
  int cur = 0, rsl = 0;
  for(int i = 0; i < size; i++) {
    if(cur < target) {
      cur += cakes[i];
    } else {
      cur = cakes[i];
      ++rsl;
    }
  }
  return cur == 0 ? rsl : rsl + 1;
}

int main() {
  int n, k;
  cin >> n >> k;
  std::vector<int> cakes(n, 0);
  for(int i = 0;i < n; i++) {
    cin >> cakes[i];
  }
  cout << calNums(n, k, cakes) << endl;
  return 0;
}
