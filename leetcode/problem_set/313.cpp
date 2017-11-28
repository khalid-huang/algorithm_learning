#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(7);
    primes.push_back(13);
    primes.push_back(19);
    cout << nthSuperuglyNumber(n, primes) << endl;
}