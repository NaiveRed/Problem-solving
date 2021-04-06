#include <bits/stdc++.h>
using namespace std;

class MinStack {
 private:
  stack<int> s, min_s;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (min_s.empty() || x <= min_s.top()) min_s.push(x);
  }

  void pop() {
    int x = s.top();
    s.pop();
    if (x == min_s.top()) min_s.pop();
  }

  int top() { return s.top(); }

  int getMin() { return min_s.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
