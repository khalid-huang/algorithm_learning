#include <iostream>
#include <vector>

using namespace std;

int total[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
char c[10][10] = {
  "",
  "",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz"
};

string getStr(int digits[], int answers[], int size) {
  // int size = digits.size();
  string rsl;
  for(int i = 0; i < size; i++) {
    rsl += c[digits[i]][answers[i]];
  }
  return rsl;
}

std::vector<string> letterCombinations(string digits) {
  //初始化工作
  std::vector<string> rsl;
  int size = digits.size();
  if(size == 0) {
    return rsl;
  }
  int digitsI[size];
  int answers[size];
  for(int i = 0; i < size; i++) {
    answers[i] = 0;
    digitsI[i] = digits[i] - '0';
  }

  while (true) {
    rsl.push_back(getStr(digitsI, answers, size));
    // cout << rsl.size() << endl;
    int k = size - 1;
    while(k >= 0) {
      cout << answers[k] << "-" << total[digitsI[k]] << endl;
      if(answers[k] < total[digitsI[k]] - 1) {
        answers[k]++;
        break;
      } else {
        answers[k] = 0;
        k--;
      }
    }
    // cout << k << endl;
    if(k < 0) {
      break;
    }
  }

  return rsl;
}

void print(std::vector<string> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main() {
  string digits;
  cin >> digits;
  print(letterCombinations(digits));
}
