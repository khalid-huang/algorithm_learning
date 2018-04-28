#include<iostream>

using namespace std;

string vowels = "AEIOUaeiou";

bool isVowels(char c) {
    return vowels.find(c) != string::npos;    
}

string reverseVowels(string s) {

}

int main() {
    // string s;
    // cin >> s;
    // cout << reverseVowels(s) << endl;
    cout << string::npos << endl;
}