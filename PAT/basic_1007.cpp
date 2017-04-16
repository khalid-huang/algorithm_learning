//换一种思路，因为已经有两个的差值是2,所以可以用i和i-2表示，只要判断这两个数字是不是素数就可以了，这样更加方便；

#include <iostream>
using namespace std;

int N, number;

bool isPrime(int val) {
  for(int i = 2; i * i <= val; i++) {
    if(val % i == 0 && val != i) {
      return false;
    }
  }
  return true;
}

// int get_next_prime(int val) {
//   val = val + 1;
//   while(true) {
//     if(isPrime(val)) {
//       break;
//     } else {
//       val++;
//     }
//   }
//   return val;
// }

// void cal() {
//   int pre = 2, cur;
//   while(cur < N) {
//     cur = get_next_prime(pre);
//     if(cur >= N) {
//       break;
//     }
//     if(cur - pre == 2) {
//       number++;
//     }
//     pre = cur;
//   }
// }

void cal() {
  for(int i = 5; i <= N; i++) {
    if(isPrime(i - 2) && isPrime(i)) {
      number = number + 1;
    }
  }
}

int main() {
  cin >> N;
  number = 0;
  cal();
  cout << number << endl;
  // int val;
  // while(cin >> val) {
  //   cout << isPrime(val) << endl;
  // }
}
