#include <iostream>
#include <vector>

using namespace std;


//http://blog.csdn.net/lengxiao1993/article/details/52303492
// kadane算法变种，就是在遍历一轮的过程中去保存最小的值和最大的差值就可以了
int maxProfit(std::vector<int>& prices) {
  int diff = 0, size = prices.size();
  if(size == 0) {
    return diff;
  }
  int min = prices[0], temp;
  for(int i = 1; i < size; i++) {
    if(prices[i] > min) {
      temp = prices[i] - min;
      diff = temp > diff ? temp : diff;
    } else {
      min = prices[i];
    }
  }
  return diff;
}

int main() {
  std::vector<int> prices;
  prices.push_back(7);
  prices.push_back(6);
  prices.push_back(5);
  prices.push_back(4);
  prices.push_back(3);
  prices.push_back(2);

  cout << maxProfit(prices) << endl;
}
