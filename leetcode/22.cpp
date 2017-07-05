#include <iostream>
#include <vector>

using namespace std;

/*
  rsl表示结果
  str表示当前的字符串
  left表示还有多少个左括号可以添加
  right表示针对目前的str还需要多少个右括号匹配
 */
void addParentheses(std::vector<string>& rsl, string str, int left, int right) {
  if(left == 0 && right == 0) {
    rsl.push_back(str);
    return;
  }
  if(right > 0) {
    addParentheses(rsl, str+")", left, right-1);
  }
  if(left > 0) {
    addParentheses(rsl, str+"(", left-1, right+1);
  }
}

std::vector<string> generateParenthesis(int n) {
  vector<string> rsl;
  addParentheses(rsl, "", n, 0);
  return rsl;
}

void print(std::vector<string> v) {
  int size = v.size();
  for(int i = 0; i < size; i++) {
    cout << v[i] << endl;
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  print(generateParenthesis(n));
}
