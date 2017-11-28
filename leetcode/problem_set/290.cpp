#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//split可以使用istringstream来处理，因为分割符号是空格
vector<string> split(string str, char symbol) {
    str = str + " ";
    int cur = 0, nums;
    size_t found;
    vector<string> strs;
    while((found = str.find(symbol, cur)) != string::npos) {
        nums = found - cur;
        strs.push_back(str.substr(cur, nums));
        cur = found + 1;
    }
    return strs;
}

//双射的话，可以用map<char, int> 和map<string, int> 来同时对应；
bool wordPattern(string pattern, string str) {
    vector<string> strs = split(str, ' ');
    int size = strs.size();
    if(size != pattern.size()) {
        return false;
    }
    map<char, string> dict;
    for(int i = 0;i < size; i++) {
        cout << pattern[i] << " " << strs[i] << endl; 
        if(dict.find(pattern[i]) == dict.end()) {
            dict[pattern[i]] = strs[i];
        } else {
            cout << dict[pattern[i]] << " " << strs[i] << endl;
            if(dict[pattern[i]] != strs[i]) {
                return false;
            }
        }
    }
    return true;
}

void print(vector<string> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << endl;
    }
    cout << endl;
}

int main() {
    string pattern, str;
    // cin >> pattern >> str;
    pattern = "abbc";
    str = "dog cat cat dog";
    cout << wordPattern(pattern, str) << endl;

}