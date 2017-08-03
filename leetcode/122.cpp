//定律呀，a,b,c求这三个数的最大差值（需要保证的是只能用后面的减前面），其实这个差值一定是(b-a) + (c-b),因为c-a也就等于（b-a） + (c-b)了

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(std::vector<int>& prices) {
  int total = 0, size = prices.size();
  for(int i = 1; i < size; i++) {
    if(prices[i] > prices[i-1]) {
      total += prices[i] - prices[i-1];
    }
  }
  return total;
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
