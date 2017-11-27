#include <iostream>
#include <vector>

#define MAX_INT 0x7fffffff
#define MIN_INT 0x80000000

using namespace std;



int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int buy = MIN_INT, pre_sell = 0, sell = 0, pre_buy; 
    for(int i = 0; i < size; i++) {
        pre_buy = buy;
        buy = max(pre_buy, pre_sell - prices[i]);
        pre_sell = sell;
        sell = max(pre_sell, pre_buy + prices[i]);
    }
    return sell;
}

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(0);
    prices.push_back(2);


    cout << maxProfit(prices) << endl;
}