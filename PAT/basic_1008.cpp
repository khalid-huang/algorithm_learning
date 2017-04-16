//用类似于循环数组的方式；
#include <iostream>
#include <sstream>
using namespace std;

int loop_arr[101];
int N, M;

int main() {
  int i, head, end, size, cur;
  stringstream rsl_ss;
  string rsl;
  cin >> N >> M;
  for(i = 0; i < N; i++) {
    cin >> loop_arr[i];
  }
  head = 0;
  end = N-1;
  size = N;

  M = M % size;
  head = (head-M+size) % size;
  cur = head;
  while(true) {
    rsl_ss << loop_arr[cur] << " ";
    cur = (cur + 1) % size;
    if(cur == head) {
      break;
    }
  }
  rsl = rsl_ss.str();
  rsl = rsl.substr(0, rsl.length()-1);
  cout << rsl << endl;
}
