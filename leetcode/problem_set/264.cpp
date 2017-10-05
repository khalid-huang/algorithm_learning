#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    vector<int> uglyNumber(n);
    uglyNumber[0] = 1;

    // 三条前进序列，每次先最小
    int t2 = 0, t3 = 0, t5 = 0; 
    for(int i = 1; i < n; i++) {
        uglyNumber[i] = min(uglyNumber[t2] * 2, min(uglyNumber[t3] * 3, uglyNumber[t5] * 5));
        if(uglyNumber[t2] * 2 == uglyNumber[i]) ++t2;
        if(uglyNumber[t3] * 3 == uglyNumber[i]) ++t3;
        if(uglyNumber[t5] * 5 == uglyNumber[i]) ++t5;
    }
    return uglyNumber[n-1];
}

int main() {
    int n;
    cin >> n;
    cout<< nthUglyNumber(n) << endl;
}