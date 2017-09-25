#include <iostream>
#include <map>
#include <vector>

using namespace std;

int fourSumCount(vector<int>& A, std::vector<int>& B, vector<int>& C, vector<int>& D) {
  map<int, int> sum_count;
  int sum, rsl = 0;
  int size_A = A.size(), size_B = B.size();
  for(int i = 0; i < size_A; i++) {
    for(int j = 0; j < size_B; j++) {
      sum = A[i] + B[j];
      if(sum_count.find(sum) == sum_count.end()) {
        sum_count[sum] = 1;
      } else {
        ++sum_count[sum];
      }
    }
  }

  int size_C = C.size(), size_D = D.size();
  for(int i = 0; i < size_C; i++) {
    for(int j = 0; j < size_D; j++) {
      sum = C[i] + D[j];
      sum = -sum;
      if(sum_count.find(sum) != sum_count.end()) {
        rsl += sum_count[sum];
      }
    }
  }
  return rsl;
}

int main() {
  std::vector<int> A(2,0);
  std::vector<int> B(2,0);
  std::vector<int> C(2,0);
  std::vector<int> D(2,0);

  A[0] = 1;
  A[1] = 2;
  B[0] = -2;
  B[1] = -1;
  C[0] = -1;
  C[1] = 2;
  D[0] = 0;
  D[1] = 2;

  cout << fourSumCount(A, B, C, D) << endl;

}
