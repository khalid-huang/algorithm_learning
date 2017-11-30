#include <iostream>
#include <vector>

using namespace std;

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
    }
    cout << "最长公共子串长度为" << len << endl;
    int start = end - len + 1;
    for(int i = start; i <= end; i++) {
        cout << str2[i];
    }
    cout << endl;
}

int main() {
    string str1 = "21232523311324";
    string str2 = "312123223445";
    LCS(str1, str2);
}