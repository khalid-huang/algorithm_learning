//用两个队列实现一个栈，一个用来放数，一个用来出数

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
  stack<int> s1; //进数
  stack<int> s2; //出数
  MyQueue() {

  }

  void adjust() {
    if(s2.empty()) {
      while(!s1.empty()) {
        s2.push(s1.top());
      }
      s1.pop();
    }
  }

  void push(int x) {
    s1.push(x);
  }

  int pop() {
    adjust();
    int rsl = s2.top();
    s2.pop();
    return rsl;
  }

  int peek() {
    adjust();
    return s2.top();
  }

  bool empty() {
    adjust();
    return s2.empty();
  }
}
