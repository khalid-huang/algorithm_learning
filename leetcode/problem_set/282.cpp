#include <iostream>
#include <vector>
#include <string>

using namespace std;

int str2int(string val) {
    int rsl = 0, size = val.size();
    for(int i = 0; i < size; i++) {
        rsl = rsl * 10 + (val[i] - '0');
    }
    return rsl;
}

void print(vector<string> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << endl;
    }
}

void backTrack(vector<string>& rsl, string cur, string num, int target,
        int curSum, int preVal) {
    // cout << cur << " " << num << " " << target << " " << curSum << endl;
    cout << "curPath: " << cur << endl;
    cout << "curNum: " << num << endl;
    cout << "curSum: " << curSum << endl;
    cout << "----------------" << endl;
    if(num.size() == 0) {
        if(target == curSum) {
            rsl.push_back(cur);
        }
        return;
    }
    int size = num.size();
    for(int i = 1; i <= size; i++) {
        //以0开头的只能一次
        if(i != 1 && num[0] == '0') {
            break;
        }

        int val = str2int(num.substr(0, i));
        string valS = num.substr(0, i);
        if(cur.empty()) {
            //当cur还是空的时候，直接放进去
            backTrack(rsl, cur + valS, num.substr(i), target, curSum + val, val);
        } else {
            //还有一个优先级的问题，乘法的问题; 解决的思路是先加上或减去，但是保存起来到下一轮，如果是乘法的，就补回来
            backTrack(rsl, cur + "+" + valS, num.substr(i), target, curSum + val, val);
            backTrack(rsl, cur + "-" + valS, num.substr(i), target, curSum - val, -val);
            backTrack(rsl, cur + "*" + valS, num.substr(i), target, curSum - preVal + preVal * val, preVal * val);
        }
    }

}

vector<string> addOperators(string num, int target) {
    vector<string> rsl;
    string cur;
    backTrack(rsl, cur, num, target, 0, 0);
    return rsl;
}

int main() {
    string num;
    // cin >> num;
    num = "232";
    int target;
    // cin >> target;
    target = 8;
    print(addOperators(num, target));
}