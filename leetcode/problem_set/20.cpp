#include <iostream>
#include <stack>

using namespace std;

bool match(char c1, char c2) {
  if((c1 == '(' && c2 == ')') || (c1 == '{' && c2 == '}') || (c1 == '[' && c2 == ']')) {
    return true;
  } else {
    return false;
  }
}

bool isValid(string s) {
  stack<char> myStack;
  int size = s.size();
  for(int i = 0; i < size; i++) {
    if(myStack.empty()) {
      myStack.push(s[i]);
    } else {
      if(match(myStack.top(), s[i])) {
        myStack.pop();
      } else {
        myStack.push(s[i]);
      }
    }
  }

  return myStack.empty() ? true : false;
}

int main() {
  string s;
  cin >> s;
  cout << isValid(s) << endl;
}
