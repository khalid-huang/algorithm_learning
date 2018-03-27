// http://maskray.me/blog/2013-08-27-josephus-problem-two-log-n-solutions

#include <iostream>

using namespace std;

int josephusSolve(int m, int n) {
    int s = 0; //  i = 1时的s
    for(int i = 2; i <= n; i++) {
        s = (s + m) % n;
    }
    return s;
}

int main() {
    int m, n;
    cin >> m >> n; //m表示计数个数， n表示人数；从0开始编号

    cout << josephusSolve(m, n) << endl;
}