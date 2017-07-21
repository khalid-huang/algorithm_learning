#include <iostream>
#include <vector>

using namespace std;

void print(std::vector<std::vector<int> > rsl) {
  int size_o = rsl.size(), size_i;
  for(int i = 0;i < size_o; i++) {
    size_i = rsl[i].size();
    for(int j = 0; j < size_i; j++) {
      cout << rsl[i][j] << " ";
    }
    cout << endl;
  }
}

void backTrack(std::vector<std::vector<int> >& rsl, std::vector<int> tempList, int n, int k, int start) {
  if(tempList.size() == k) {
    rsl.push_back(tempList);
    return;
  }
  for(int i = start; i <= n; i++) {
    tempList.push_back(i);
    backTrack(rsl, tempList, n, k, i+1);
    tempList.pop_back();
  }
}

std::vector<std::vector<int> > combine(int n, int k) {
  std::vector<std::vector<int> > rsl;
  std::vector<int> tempList;
  backTrack(rsl,tempList, n, k, 1);
  return rsl;
}

int main() {
  int n, k;
  cin >> n >> k;
  print(combine(n, k));
  // print(combine(n, k));
}
