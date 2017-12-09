#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<string> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << endl;
    }
    // cout << endl;
}

bool is_swap(string s, int start, int target) {
    if(start == target) {
        return true;
    }
    //判断是否之前已经有过一样的字条
    for(int i = start; i < target; i++) {
        if(s[i] == s[target]) {
            return false;
        }
    }
    return true;
}

void swap(string& s, int i, int j) {
    char a = s[i];
    s[i] = s[j];
    s[j] = a;
}

void _perm(string s, int start, int end, string cur, vector<string>& rsl) {
    if(start == end) {
        cur += s[end];
        rsl.push_back(cur);
        return;
    }
    for(int i = start; i <= end; i++) {
        if(is_swap(s, start, i)) {
            swap(s, i, start);
            _perm(s, start + 1, end, cur + s[start], rsl);
            swap(s, i, start);
        }
    }
}

vector<string> permutation(string s) {
    vector<string> rsl;
    int start = 0, end = s.size() - 1;
    string cur = "";
    _perm(s, start, end, cur, rsl);
    return rsl;
}

int main() {
    string s = "abc";
    // swap(s, 0, 1);
    // cout << s << endl;
    print(permutation(s));
}