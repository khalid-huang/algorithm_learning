//学会奇偶分析
#include<iostream>
#include<fstream>

using namespace std;

string decode(string cipher) {
    int size = cipher.size();
    if(size & 1) {
        //odd
        return "AMBIGUOUS";
    } else {
        //even
        string source(size, ' ');
        source[1] = cipher[0];
        source[size-2] = cipher[size-1];
        for(int i = 1 + 2; i < size; i+=2) {
            source[i] = ('A' + (cipher[i-1] - source[i-2] + 26) % 26);
        }
        for(int i = size - 2 - 2; i >= 0; i-=2) {
            source[i] = ('A' + (cipher[i+1] - source[i+2] + 26) % 26);
        }
        return source;
    }
}

int main() {
    ifstream infile;
    ofstream outfile;
    // infile.open("A-small-practice.in");
    // outfile.open("A-small-practice.out");
    infile.open("A-large-practice.in");
    outfile.open("A-large-practice.out");

    string cipher;
    int t;
    infile >> t;
    for(int i = 1; i <= t; i++) {
        infile >> cipher;
        outfile << "Case #" << i << ": " << decode(cipher) << endl;
    }
    // string temp;
    // cin >> temp;
    // cout << decode(temp) << endl;
}