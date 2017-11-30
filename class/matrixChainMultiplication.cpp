#include <iostream>
#include <vector>

using namespace std;

void generteData(vector<vector<int> >& testData) {
    //测试数据
    vector<int> A1;
    A1.push_back(50);
    A1.push_back(10);
    vector<int> A2;
    A2.push_back(10);
    A2.push_back(40);
    vector<int> A3;
    A3.push_back(40);
    A3.push_back(30);
    vector<int> A4;
    A4.push_back(30);
    A4.push_back(5);


    testData.push_back(A1);
    testData.push_back(A2);
    testData.push_back(A3);
    testData.push_back(A4);
}

int lookupChain(vector<vector<int> >& m, vector<vector<int> >& s, vector<int>& A, int first, int last) {
    //动态规划剪枝
    if(m[first][last] > 0) {
        return m[first][last];
    }
    if(first == last) {
        return 0;
    }
    int tmp = lookupChain(m, s, A, first, first) + lookupChain(m, s, A, first+1, last) + A[first-1] * A[first] * A[last];
    s[first][last] = first;
    int tmp1;
    for(int k = first + 1; k < last; k++) {
        tmp1 = lookupChain(m, s, A, first, k) + lookupChain(m, s, A, k+1, last) + A[first-1] * A[k] * A[last];if(tmp < tmp1) {
            tmp = tmp1;
            s[first][last] = k;
        } 
    }
    m[first][last] = tmp;
    return tmp;
}

vector<int> generateA(vector<vector<int> >& testData) {
    int size = testData.size();
    vector<int> A(size+1);
    cout << testData[0][0] << endl;
    A[0] = testData[0][0];
    for(int i = 1; i < size + 1; i++) {
        A[i] = testData[i-1][1];
    }
    return A;
}

void print(vector<vector<int> > s) {
    // int size = s.size();
    // for(int i = 0; i < size; i++) {
    //     int size_o = s[i].size();
    //     for(int j =0; j < size_o; j++) {
    //         cout << s[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void print1(vector<int> tmp) {
    int size = tmp.size();
    for(int i = 0; i < size; i++) {
        cout << tmp[i] << " ";
    }
    cout << endl;
}

int matrixChain(vector<vector<int> >& testData) {
    vector<int> A = generateA(testData);
    print1(A);
    int size = testData.size();
    vector<vector<int> > m(size+1); //用于动态规划保存结果，其中m[i][j]表示第i个矩阵到第j个矩阵的最小乘法次数
    vector<vector<int> > s(size+1); //s[i][j]表示当取A[i:j]取最小乘法次数时，使用的分隔位置
    for(int i = 0; i < size + 1; i++) {
        m[i] = vector<int>(size+1, -1);
        s[i] = vector<int>(size+1, -1);
    }
    
    int first = 1, last = size;
    lookupChain(m, s, A, first, last);

    print(s);//打印括号顺序
    return m[1][size];//返回结果
}

int main() {

    vector<vector<int> > testData;
    generteData(testData);
    cout << matrixChain(testData) << endl;
    
}