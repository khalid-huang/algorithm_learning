#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());

    int size = citations.size();
    int rsl = 0;
    for(int i = 0, cts = size; i < size; i++, cts--) {
        // cout << citations[i] << " " << cts << endl;
        if(citations[i] >= cts) {
            rsl = cts;
            break;
        }
    }
    return rsl;
}

int main() {
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << hIndex(citations) << endl;
}