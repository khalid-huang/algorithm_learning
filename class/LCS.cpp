#include <iostream>
#include <vector>

using namespace std;

int c[100][100]; //注意这个的c[i][j]是表示X从0到i与Y从0至j的最长公共子串的长度值，在递推式里面的下标是从1开始的，这里是从0开始的


void printC(vector<int> c) {
    int size = c.size();
    for(int i = 0; i < size; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

//用一维数组实现
void LCS(string str1, string str2) {
    int len1 = str1.size(), len2 = str2.size();
    vector<int> c(len2, 0);
    int end = 0, len = 0; //用于记录公共串的位置
    for(int i = 0; i < len1; i++) {
        //反着来，可以将二维变成一维
        for(int j = len2 - 1; j >= 0; j--) {
            if(str1[i] == str2[j]) {
                if(i == 0 || j == 0) {
                    c[j] = 1;
                } else {
                    c[j] = c[j-1] + 1; //利用左上角的值进行加1 
                }
            } else {
                c[j] = 0;
            }
            if(c[j] > len) {
                len = c[j];
                end = j;
            }
        }
        printC(c);
    }
    cout << "最长公共子串长度为: " << len << endl << endl;
    cout << "最长公共子串为: ";
    int start = end - len + 1;
    for(int i = start; i <= end; i++) {
        cout << str2[i];
    }
    cout << endl;
}



//用递归实现
int LCS1(string str1, string str2, int i, int j) {
    //这个是为了防止在减1之后出现负数的情况；
    if(i < 0 || j < 0) {
        return 0;
    }
    // if(i == 0 || j == 0) {
    //     c[i][j] = 0;
    //     return 0 ;
    // }
    if(str1[i] == str2[j]) {
        c[i][j] = LCS1(str1, str2, i - 1, j - 1) + 1;
        return c[i][j];
    }
    if(str1[i] != str2[j]) {
        c[i][j] = max(LCS1(str1, str2, i - 1, j), LCS1(str1, str2, i, j - 1));
        return c[i][j];
    }
}

//动态规范，二维数组
int LCS2(string str1, string str2) {
    int size1 = str1.size(), size2 = str2.size(), tmp;
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            if(str1[i] == str2[j]) {
                //如果是第一个的话，就直接是1
                if(i == 0 || j == 0) {
                    c[i][j] = 1;
                } else {
                    c[i][j] = c[i-1][j-1] + 1;
                }
            } else {
                tmp = 0;
                if(i > 0) {
                    tmp = tmp > c[i-1][j] ? tmp : c[i-1][j];
                }
                if(j > 0) {
                    tmp = tmp > c[i][j-1] ? tmp : c[i][j-1];
                }
                c[i][j] = tmp;
            }
        }
    }
    return c[size1-1][size2-1];
}

void printC(int size1, int size2) {
    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    string str1 = "abckd";
    string str2 = "eabcke";
    cout << "测试数据为: " << str1 << "和" << str2 << endl << endl; 
    LCS(str1, str2);

    // LCS1(str1, str2, str1.size()-1, str2.size()-1);
    // printC(str1.size(), str2.size());

    // LCS2(str1, str2);
    // printC(str1.size(), str2.size());
    cout << c[str1.size()-1][str2.size()-1] << endl;
}