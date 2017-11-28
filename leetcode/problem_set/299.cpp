#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string getRsl(int Aflag, int Bflag) {
    stringstream ss;
    ss << Aflag << "A" << Bflag << "B";
    return ss.str();
}

string getHint(string secret, string guess) {
    int ssize = secret.size(), gsize = guess.size();
    vector<int> count(10, 0);
    vector<int> remain(10, 0);
    int Aflag = 0, Bflag = 0;
    int i , j;

    for(i = 0; i < ssize; i++) {
        ++count[secret[i] - '0'];
    }
    
    //deal A;
    for(i = 0; i < gsize; i++) {
        if(secret[i] == guess[i]) {
            ++Aflag;
            --count[secret[i] - '0'];
        } else {
            ++remain[guess[i] - '0'];
        }
    }
    //deal B;
    for(i = 0; i < 10; i++) {
        Bflag +=  min(count[i], remain[i]);
    }
    
    return getRsl(Aflag, Bflag);
}

int main() {
    string secret, guess;
    secret = "1807";
    guess = "7810";
    cout << getHint(secret, guess) << endl;

}