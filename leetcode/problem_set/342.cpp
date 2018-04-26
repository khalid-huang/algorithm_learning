#include<iostream>
using namespace std;

bool isPowerOfFour(int num) {
    if((num & (num - 1)) == 0 && num != 0) {
        if((num & 0x55555555) == num) {
            return true;
        }
    }
    return false; 
}

int main() {
    int num;
    cin >> num;
    cout << isPowerOfFour(num) << endl;
}