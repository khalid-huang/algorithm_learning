#include <iostream>

using namespace std;

const int N = 2;

struct Matrix {
    long m[N][N];
};

Matrix base = {
    1, 1,
    1, 0
};

Matrix I = {
    1, 0,
    0, 1
};

void print(Matrix a) {
    for(int i = 0;i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << a.m[i][j] << " ";
        }
        cout << endl;
    }
}

// 递归法
int fibonacci(int n) {
    if(n <= 1) {
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

//递推法
int fibonacci2(int n) {
    int ppre = 1, pre = 1, cur = 1, temp;
    while(cur < n) {
        temp = ppre + pre;
        ppre = pre;
        pre = temp;
        ++cur;
    }
    return pre;
}


//矩阵法；一般用于求带求模的，如下的问题形式是：求斐波那契数列中的第n位mod 10000的值

Matrix matrix_mul(Matrix a, Matrix b, int modVal) {
    Matrix c;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            c.m[i][j] = 0;
            for(int k = 0; k < N; k++) {
                c.m[i][j] += a.m[i][k] * b.m[k][j] % modVal;
            }
            c.m[i][j] %= modVal; 
        }
    }
    return c;
}

Matrix power(Matrix base, int power, int modVal) {
    Matrix ans = I, cur = base;
    while(power) {
        if(power & 1 == 1) {
            ans = matrix_mul(ans, cur, modVal);
            --power;
        }
        power >>= 1;
        cur = matrix_mul(cur, cur, modVal);
        print(ans);
    }
    return ans;    
}

int fibonacci3(int n, int modVal) {
    Matrix ans = power(base, n, modVal);
    return ans.m[0][0];
}

int main() {
    int n;
    cin >> n;
    // cout << fibonacci2(n) << endl;
    cout << fibonacci3(n, 10000) << endl;
}