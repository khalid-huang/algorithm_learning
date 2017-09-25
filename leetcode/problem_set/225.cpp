//记住队列操作的只有队头就可以了
//每次加数的时候维护队列成栈的属性，也就是调换下数字的位置，
//相同的看232

#include <iostream>
#include <queue>

using namespace std;

class Stack {
public:
  queue<int> q;

  void push(int x) {
    q.push(x);
    int t = q.size() - 1;
    for(int i = 0; i < t; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  void pop() {
    q.pop();
  }

  int top() {
    return q.front();
  }

  bool empty() {
    return q.empty();
  }
};
