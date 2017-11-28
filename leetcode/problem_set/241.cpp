#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> rsl) {
    int size = rsl.size();
    for(int i = 0;i < size; i++) {
        cout << rsl[i] << " ";
    }
    cout << endl;
}

int str2int(string input) {
    int rsl = 0, size = input.size();
    for(int i = 0; i < size; i++) {
        rsl = rsl * 10 + (input[i] - '0');
    }
    return rsl;
}

vector<int> diffWaysToComputes(string input) {
    vector<int> rsl;
    vector<int> left;
    vector<int> right;
    int size = input.size();

    for(int i = 0; i < size; i++) {
        char cur = input[i];
        if(cur == '+' || cur == '-' || cur == '*') {
            left = diffWaysToComputes(input.substr(0, i));
            right = diffWaysToComputes(input.substr(i+1, size - i - 1));
            
            int size_left = left.size();
            int size_right = right.size();
            for(int j = 0; j < size_left; j++) {
                for(int k = 0; k < size_right; k++) {
                    if(cur == '+') {
                        rsl.push_back(left[j] + right[k]);
                    } else if(cur == '-') {
                        rsl.push_back(left[j] - right[k]);
                    } else {
                        rsl.push_back(left[j] * right[k]);
                    }
                }
            }
        }
    }
    //if only has number
    if(rsl.empty()) {
        rsl.push_back(str2int(input));
    }
    return rsl;
}

int main() {
   string input;
   cin >> input;
   print(diffWaysToComputes(input)); 
}