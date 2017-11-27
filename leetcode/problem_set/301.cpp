#include <iostream>
#include <vector>

using namespace std;

void print(vector<string>& rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

string getReverse(string s) {
    int size = s.size();
    string rsl(size, ' ');
    for(int i = 0, j = size - 1; i < size; i++, j--) {
        rsl[i] = s[j];
    }
    return rsl;
}

//想法是每轮我们只删除一个非法字符，从左往右删除)，再从右往左删除(
void remove(vector<string>& rsl, string s, int cur, int start, char pair_1, char pair_2) {
    int count = 0, i, j, size = s.size();
    for(i = cur; i < size; i++) {
        if(s[i] == pair_1) ++count;
        if(s[i] == pair_2) --count;
        if(count >= 0) continue;
        for(j = start; j <= i; j++) {
            if(s[j] == pair_2 && (j == start || s[j] != s[j-1])) {
                remove(rsl, s.substr(0, j) + s.substr(j+1, size), i, j,pair_1, pair_2);
            }
        }
        return; //每一轮只删除一个字符
    }
    string reverse_s = getReverse(s);
    if(pair_1 == '(') {
        remove(rsl, reverse_s, 0, 0, pair_2, pair_1); //现在已经完成了从左往右的工作，再作一次从右往左的工作
    } else {
        rsl.push_back(reverse_s); //如果两个方向都完成了，直接push
    }
}


vector<string> removeInvalidParenthese(string s) {
    vector<string> rsl;
    int start = 0, cur = 0;
    char pair_1 = '(', pair_2 = ')';
    remove(rsl, s, cur, start, pair_1, pair_2);
    return rsl;
}


void print(vector<string> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << endl;
    }
}

int main() {
    string s;
    s = "()())()";
    print(removeInvalidParenthese(s));
}