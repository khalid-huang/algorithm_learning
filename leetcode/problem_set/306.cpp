#include<iostream>

//如下是使用了直接的加法，但是针对大数的，需要使用大数加法，直接使用字符串加法；
using namespace std;

int str2int(string num) {
    int size = num.size();
    // int val  = 0;
    long val = 0;
    for(int i = 0; i < size; i++) {
        val = val * 10  + (num[i] - '0');
    }
    return val;
}

void search(string num, int val1, int val2, bool& rsl) {
    int size = num.size();

    // int val3 = 0;
    long val3 = 0;
    for(int i = 0; i < size; i++) {
        //不能0开头
        if(i > 0 && num[0] == '0') {
            break;
        } 
        val3 = val3 * 10 + (num[i] - '0');
        if(val1 + val2 > val3) {
            continue;
        } else if(val1 + val2 == val3) {
            if(i != size - 1) {
                search(num.substr(i+1),val2, val3, rsl);
                break;
            } else {
                rsl = true;
                break;
            }
        } else {
            break;
        }
    }
}

bool isAdditiveNumber(string num) {
    int size = num.size(), remain;
    // int val1, val2;
    long val1, val2;
    bool rsl = false;
    for(int i = 1; i <= size; i++) {
        //不能前导0开头
        if(num[0] == '0' && i > 1) {
            break;
        }
        for(int j = 1; j <= size; j++) {
            remain = size - i - j;
            if(remain < i && remain < j) {
                break;
            }
            //数字不能0开头; 除了0本身
            if(num[i] == '0' && j > 1) {
                continue;
            }
            val1 = str2int(num.substr(0, i));
            val2 = str2int(num.substr(i, j));
            search(num.substr(i+j, size),val1, val2, rsl);
        }
    }
    return rsl;
}

int main() {
    string num;
    num = "121474836472147483648"; // 1 + 2147483647
    cout << isAdditiveNumber(num) << endl;
}