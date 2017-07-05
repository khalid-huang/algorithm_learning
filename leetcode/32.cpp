//连续有序,需要记住那个每个左括号的位置，所以每个左括号的一边都去代表一个数字，如果消去了一个左括号，就把两个数字加起来
//使用两个栈来处理，字符栈用来匹配括号的，而数字栈是用来计录当前的有序数字的；它里面的情况：
//1）如果有(进来的话。就直接push 0表示当前这个(还没有匹配掉
//2）如果有）进来的话，如果字符栈为空，就直接数字栈push0表示一个结束（不规范）
//）如果字符栈不为空，表示有左括号可以匹配，就当将数字栈的栈顶数字出栈并进行加1，记为n,同时字符栈出栈一个左括号；同时要考虑连续性的问题，如果数字栈在里面在栈顶元素出栈后，还有数字的话，就将前面得到的n与栈顶元素相加作为新的栈顶元素，表示这是一个连续的括号匹配对。
#include <iostream>
#include <stack>

using namespace std;

int longestValidParentheses(string s) {
  stack<char> c_stack;
  stack<int> i_stack;

  int size = s.size(), i_temp, ii_temp;
  for(int i = 0; i < size; i++) {
    if(s[i] == '(') {
      c_stack.push('(');
      i_stack.push(0);
    } else { // s[i] == ')'
      if(c_stack.empty()) {
        i_stack.push(0);
        continue;
      } else {
        //匹配成功一个
        c_stack.pop();
        i_temp = i_stack.top() + 1;
        i_stack.pop();
        //如果栈顶还有元素的话，要表示是一个连续的对，需要进行叠加
        if(!i_stack.empty()) {
          ii_temp = i_stack.top();
          i_stack.pop();
          ii_temp += i_temp;
          i_stack.push(ii_temp);
        } else {
          //没有 话，就直接进栈
          i_stack.push(i_temp);
        }
      }
    }
  }

  int max = 0;
  while(!i_stack.empty()) {
    if(max < i_stack.top()) {
      max = i_stack.top();
    }
    i_stack.pop();
  }
  return max * 2;
}

string s;
int main() {
  cin >> s;
  cout << longestValidParentheses(s) << endl;
}
