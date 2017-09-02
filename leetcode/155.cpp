class MinStack {
private:
  stack<int> s1;
  stack<int> s2; //保留当前最小值

public:
  MinStack() {

  }
  void push(x) {
    s1.push(x);
    if(s2.empty() || x <= getMin()) {
      s2.push(x);
    }
  }

  void pop() {
    if(s1.top() == getMin()) {
      s2.pop();
    }
    s1.pop();
  }

  int top() {
    return s1.top();
  }

  int getMin() {
    return s2.top();
  }
}
