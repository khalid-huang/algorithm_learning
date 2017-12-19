#include <iostream>
#include <vector>

using namespace std;

//8皇后问题解决 
int n = 8;
vector<int> queen(n+1);
vector<vector<int> > places;

void print() {
    int size = queen.size();
    for(int i = 1; i < size; i++) {
        cout << queen[i] << " ";
    }
    cout << endl;
}

int abs(int a) {
    return a >= 0 ? a : -a;
}

//第row行的放在col列上是否可行，要与之前的进行下判断就知道了
bool satisfy(int row, int col) {
    for(int i = 1; i < row; i++) {
        //斜率为1或-1,或是在同一列上
        if(abs(queen[i] - col) == abs(i - row) || queen[i] == col) {
            return false; 
        }
    }
    return true;
}

void queenSolution(int cur, int& rsl) {
    if(cur > n) {
        ++rsl;
        places.push_back(queen);
        return;
    }
    for(int i = 1; i <= n; i++) { //对当前行进行1到n列的测试
        if(satisfy(cur, i)) {
            queen[cur] = i;
            queenSolution(cur+1, rsl);
            //queen[cur] = 0;//回溯,但可以不做
        }
    }
    
}

int solution() {
    int cur = 1, rsl = 0;
    queenSolution(cur, rsl);
    return rsl;
}

int main() {
    cout << solution() << endl;
}