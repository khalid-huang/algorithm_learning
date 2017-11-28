#include <iostream>
#include <vector>

using namespace std;

//algorithm is nice.
string removeDuplicateLetters(string s) {
    vector<int> cnt(26, 0);
    int size = s.size();
    for(int i = 0; i < size; i++) {
        ++cnt[s[i] - 'a'];
    }

    vector<int> visited(26, 0);
    string rsl = "0"; //减少内部判断用的，只要比a小的ascill就可以了
    for(int i = 0; i < size; i++) {
        if(visited[s[i] - 'a'] == 1) {
            --cnt[s[i]-'a'];
            continue;
        }
        while(rsl[rsl.size()-1] > s[i] && cnt[rsl[rsl.size()-1] - 'a'] > 0) {
            visited[rsl[rsl.size()-1] - 'a'] = 0;
            rsl.erase(rsl.size()-1,1);
        }
        rsl += s[i];
        --cnt[s[i] - 'a'];
        visited[s[i] - 'a'] = 1;
        cout << rsl << endl;
    }
    return rsl.substr(1);
}

int main() {
    string s;
    // s = "bcabc";
    cin >> s;
    cout << removeDuplicateLetters(s) << endl;    
}