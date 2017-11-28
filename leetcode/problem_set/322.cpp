#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

bool cmp(int a, int b) {
    return a > b;
}

//超时了
void backTrack(vector<int>& coins,int cur, int amount, int pos, int& rsl, vector<int>& tmp) {
    if(amount == 0) {
        // cout << "done: ";
        // print(tmp);
        rsl = rsl == -1 ? cur : min(rsl, cur);
        return;
    }
    if(rsl != -1 && rsl < cur) {
        return;
    }
    int size = coins.size();
    for(int i = pos; i < size; i++) {
        if(coins[i] <= amount) {
            ++cur;
            tmp.push_back(coins[i]);
            backTrack(coins, cur, amount - coins[i], i, rsl, tmp);
            --cur;
            tmp.pop_back();
        }
    }
}

int coinChange1(vector<int>& coins, int amount) {
    if(amount == 0) {
        return 0;
    }
    int pos = 0, rsl = -1, cur = 0;
    vector<int> tmp;
    // sort(coins.begin(), coins.end(), cmp);
    backTrack(coins, cur, amount, pos, rsl, tmp);
    return rsl;
}

//使用动态规划
//设dp[i]为使用coins数组，拼凑和i所需要的个数；则有如下的迭代式
//dp[i] = min(dp[i- coins[j]]) + 1 (j from 1:size)

int coinChange(vector<int>& coins, int amount) {
    int MAX= amount + 1;
    vector<int> dp(amount + 1, MAX);
    int size = coins.size();
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < size; j++) {
            if(coins[j] <= i) {
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins;
    // coins.push_back(1);
    // coins.push_back(3);
    // coins.push_back(5);
    // // coins.push_back(8);
    // int amount = 24;

    coins.push_back(186);
    coins.push_back(419);
    coins.push_back(83);
    coins.push_back(408);
    int amount = 6249;

    cout << coinChange(coins, amount) << endl;
}