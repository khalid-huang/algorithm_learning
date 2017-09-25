#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool isOperator(string s) {
  if(s == "+" || s == "-" || s == "*" || s == "/") {
    return true;
  } else {
    return false;
  }
}

int calculator(int p1, int p2, string s) {
  if(s == "+") {
    return p1 + p2;
  }
  if(s == "-") {
    return p1 - p2;
  }
  if(s == "*") {
    return p1 * p2;
  }
  if(s == "/") {
    return p1 / p2;
  }
  return 0;
}

int str2int(string s) {
  int start = 0;
  if(s[0] == '-') {
    start = 1;
  }
  int size = s.size(), rsl = 0;
  for(int i = start; i < size; i++) {
    rsl = rsl * 10 + (s[i] - '0');
  }
  return start == 0 ? rsl : -rsl;
}

int evalRPN(std::vector<string>& tokens) {
  int size = tokens.size();
  if(size == 0) {
    return 0;
  }
  int p1, p2, rsl;
  stack<int> s;
  for(int i = 0; i < size; i++) {
    if(isOperator(tokens[i])) {
      p2 = s.top();
      s.pop();
      p1 = s.top();
      s.pop();
      rsl = calculator(p1, p2, tokens[i]);
      s.push(rsl);
    } else {
      rsl = str2int(tokens[i]);
      s.push(rsl);
    }
  }
  return s.top();
}

int main() {
  std::vector<string> tokens;
  tokens.push_back("-2");
  tokens.push_back("1");
  tokens.push_back("+");
  tokens.push_back("3");
  tokens.push_back("*");
  cout << evalRPN(tokens) << endl;
}
