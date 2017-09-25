#include <iostream>
#include <cmath>

using namespace std;

//直接找是超时的； 这个适合判断单个是不是素数
bool isPrime(int n) {
  int up = sqrt(n) + 1;
  for(int i = 2; i < up; i++) {
    if(n != i && n % i == 0) {
      return false;
    }
  }
  return true;
}

// int countPrimes(int n) {
//   int count = 0;
//   for(int i = 2; i < n; i++) {
//     if(isPrime(i)) {
//       ++count;
//     }
//   }
//   return count;
// }


//适合于判断区间内的素数个数
//Eratosthenes筛选法求素数 http://www.cnblogs.com/luzheng1/archive/2013/04/09/3009344.html
//算法是先假设所有的数字都是素数，然后用倍数的方式一步步减少
//在计数的时候，先计数有多少个从是素数转到不是素数，这样就可以避免再进行一轮循环
int Eratosthenes(int n) {
  if(n <= 2) {
    return 0;
  }

  int count = 2;
  int prime[n];
  //初始化
  for(int i = 2; i < n; i++) {
    prime[i] = 1;
  }
  int up = sqrt(n) + 1;
  for(int i = 2; i < up; i++) {
    if(prime[i]) {
      //删除i的倍数
      for(int j = i * i; j < n; j += i) {
        if(prime[j] == 1)
          ++count;
        prime[j] = 0;
      }
    }
  }
  return n - count;
  //下面这个如果要自己实现的话，起码要用二分查找；用vector会好很好
  // return count;
}

//用vector
// int countPrimes(int n) {
//     vector<bool> prime(n, true);
//     prime[0] = false, prime[1] = false;
//     for (int i = 0; i < sqrt(n); ++i) {
//         if (prime[i]) {
//             for (int j = i*i; j < n; j += i) {
//                 prime[j] = false;
//             }
//         }
//     }
//     return count(prime.begin(), prime.end(), true);
// }

int countPrimes(int n) {
  return Eratosthenes(n);
}

int main() {
    int n;
    cin >> n;
    cout << countPrimes(n) << endl;
}
