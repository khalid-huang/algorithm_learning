//动态规划题目，利用f[k,ii]表示使用k轮交换后截止元素p[ii]可以得到的最大利润
//f[k,ii] = max(f[k, ii-1], max(p[ii] - p[jj] + f[k-1, jj]))
//         = max(f[k,ii-1], p[ii] + max(f[k-1,jj] - p[jj]));

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(std::vector<int>& prices) {
  int size = prices.size();
  if(size <= 1) {
    return 0;
  }
  int maxPro = 0, K = 2, maxTmp;
  std::vector<std::vector<int> > f(K+1, std::vector<int>(size, 0));
  for(int k = 1; k <= K; k++) {
    maxTmp = f[k-1][0] - prices[0];
    for(int ii = 1; ii < size; ii++) {
      f[k][ii] = max(f[k][ii-1], prices[ii] + maxTmp);
      maxTmp = max(maxTmp, f[k-1][ii] - prices[ii]); //保存最大数
      maxPro = max(f[k][ii], maxPro); //保存最大数
    }
  }
  return maxPro;
}

int main() {
  std::vector<int> prices;
  prices.push_back(7);
  prices.push_back(2);
  prices.push_back(1);
  prices.push_back(3);
  prices.push_back(6);
  // prices.push_back(2);

  cout << maxProfit(prices) << endl;
}
