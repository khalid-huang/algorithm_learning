// int 与int 相乘还是int,所以p要设置为long
// 遍历的方式可以学习下，怎么安全怎么来；

#include <iostream>
#include <algorithm>

using namespace std;

int N;
long p;
int series[100002];

int get_rsl() {
  int count = 0;
  // long M;
  for(int i = 0; i < N; i++) {
    for(int j = i + count; j < N; j++) {
      if(series[j] > series[i] * p) {
        break;
      }
      if(j - i + 1 > count) {
        count = j - i + 1;
      }
    }
  }
  return count;
}

int main() {
  cin >> N >> p;
  for(int i = 0; i < N; i++) {
    cin >> series[i];
  }
  sort(series, series + N);

  int rsl;
  rsl = get_rsl();
  cout << rsl << endl;
}
