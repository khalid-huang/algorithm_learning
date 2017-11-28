#include <iostream>
#include <vector>

#define INT_MAX 0x7fffffff

using namespace std;

int numSqaures(int n) {
    vector<int> dp;
    dp.push_back(0);
    while(dp.size() <= n) {
        int sqn = INT_MAX, m = dp.size();
        for(int i = 1; i * i <= m; i++) {
            sqn = min(sqn, dp[m - i * i] + 1);
        }
        dp.push_back(sqn);
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << numSqaures(n) << endl;
}