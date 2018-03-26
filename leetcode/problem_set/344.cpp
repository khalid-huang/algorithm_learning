#include <iostream>

using namespace std;

string reverseString(string s) {
    int size = s.size();
    string rsl = s;
    for(int i = 0; i < size; i++) {
        rsl[i] = s[size - i - 1];
    }
    return rsl;
}

int main() {
    string s;
    cin >> s;
    cout << reverseString(s) << endl;
}