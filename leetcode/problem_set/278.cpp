#include <iostream>

using namespace std;

bool isBadVersion(int version) {
    int firstOne = 5;
    if(version >= 5) {
        return true;
    } else {
        return false;
    }
}

int _firstBadVersion(int start,int end) {
    if(start == end) {
        return start;
    }
    int middle = start + (end - start) / 2;
    cout << start << " " << middle <<  " " << end  << endl;
    bool tmp = isBadVersion(middle);
    if(tmp == true) {
        return _firstBadVersion(start, middle);
    } else {
        return _firstBadVersion(middle + 1, end);
    }
}

int firstBadVersion(int n) {
    return _firstBadVersion(1, n);
}

int main() {
    int n;
    cin >> n;
    cout << firstBadVersion(n) << endl;
}