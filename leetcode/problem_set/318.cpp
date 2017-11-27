#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print(vector<int> rsl) {
    int size = rsl.size();
    for(int i = 0; i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

void reset(vector<bool>& visited) {
    int size = visited.size();
    for(int i = 0; i < size; i++) {
        visited[i] = false;
    }
}

vector<int> str2bit(vector<string>& words) {
    int size = words.size();
    int length = 0, var = 0, tmp;
    vector<int> bits(size, 0);
    vector<bool> visited(size, false);
    for(int i = 0; i < size; i++) {
        length = words[i].size();
        var = 0;
        reset(visited);
        for(int j = 0; j < length; j++) {
            tmp = words[i][j] - 'a';
            if(visited[tmp] == false) {
                var += pow(2, words[i][j] - 'a');
                visited[tmp] = true;
            }
        }
        bits[i] = var;
    }
    return bits;
}

int max(int a, int b) {
    return a > b ? a : b;
}


int maxProdcut(vector<string>& words) {
    vector<int> bits = str2bit(words);
    int size = bits.size();
    // print(bits);
    int rsl = 0;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            // cout << "test:" << (bits[i] & bits[j]) << endl;
            if((bits[i] & bits[j]) == 0) {
                // cout << rsl << endl;
                rsl = max(rsl, words[i].size() * words[j].size());
                // cout << rsl << " " << (words[i].size() * words[j].size()) << endl; 
            }
        }
    }
    return rsl;
}

int main() {
    vector<string> words;
    // words.push_back("abc");
    // words.push_back("de");
    words.push_back("abcw");
    words.push_back("baz");
    words.push_back("foo");
    words.push_back("bar");
    words.push_back("xtfn");
    words.push_back("abcdef");

    cout << maxProdcut(words) << endl;
}