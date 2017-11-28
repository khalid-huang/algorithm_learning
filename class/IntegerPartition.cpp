#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int> > rsl) {
    int size =  rsl.size();
    for(int i = 0; i < size; i++) {
        int size_o = rsl[i].size();
        for(int j = 0; j < size_o; j++) {
            cout << rsl[i][j] << " ";
        }
        cout << endl;
    }
}

int dp(int n, int m) {
    if(n == 1 || m == 1) {
        return 1;
    }
    if(n < m) {
        return dp(n, n);
    }
    if(n == m) {
        return 1 + dp(n, m-1);
    }
    if(n > m) {
        return dp(n, m-1) + dp(n-m, m);
    }
}

//tmp不能使用引用类型的，因为每个路径都有自己的一个值
int dp1(vector<vector<int> >& rsl_vec, vector<int> tmp, int n, int m) {
    //如果只有1的情况
    if(n >= 0 && m == 1) {
        if(n == 0) {
            rsl_vec.push_back(tmp);
        } else {
            tmp.push_back(1);
            dp1(rsl_vec, tmp, n-1, m);
        }
        return 1;
    }
    if(n == 1 && m > 1) {
        tmp.push_back(1);
        rsl_vec.push_back(tmp);
        return 1;
    }
    if(n < m) {
        return dp1(rsl_vec, tmp, n, n);
    }
    if(n == m) {
        //相等的话，会有一种情况产生，就要使用这种情况并入栈；之后再回溯出来
        tmp.push_back(m);
        rsl_vec.push_back(tmp);
        tmp.pop_back();
        return dp1(rsl_vec, tmp, n, m-1) + 1;
    }
    if(n > m) {
        //这里要区分好，q(n-m, m)这种情况其实是将m去掉了来考虑的，但是实际组合中是有m的，所以要加回去；而q(n, m-1)这种情况是去掉了m的，实际上去掉的。
        tmp.push_back(m);
        int a1 = dp1(rsl_vec, tmp, n-m, m);
        tmp.pop_back();
        int b1 = dp1(rsl_vec, tmp, n, m-1);
        return a1 + b1;
    }
}


int integerPartition(int n) {
    // int rsl;
    // rsl = dp(n, n);
    // return rsl;

    int rsl;
    vector<vector<int> > rsl_vec;
    vector<int> tmp;
    rsl = dp1(rsl_vec, tmp, n, n);
    print(rsl_vec);

    return rsl;
}

int main() {
    int n; 
    cin >> n;
    cout << integerPartition(n) << endl;
    //print(integerPartition(n));
}