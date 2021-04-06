#include <bits/stdc++.h>
using namespace std;

// Method 1: maintain the order of `s` be the same as queue. (top is front)
// push: O(n), pop&peek: O(1)
class MyQueue {
 private:
  stack<int> s, helper;

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    if (s.empty())
      s.push(x);
    else {
      while (!s.empty()) {
        helper.push(s.top());
        s.pop();
      }
      s.push(x);
      while (!helper.empty()) {
        s.push(helper.top());
        helper.pop();
      }
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int x = s.top();
    s.pop();
    return x;
  }

  /** Get the front element. */
  int peek() { return s.top(); }

  /** Returns whether the queue is empty. */
  bool empty() { return s.empty(); }
};

// Method 2: use `helper` to get reversed order of elements.
// push: amortized O(1), pop&peek: O(1)
class MyQueue1 {
 private:
  stack<int> s, helper;

 public:
  /** Initialize your data structure here. */
  MyQueue1() {}

  /** Push element x to the back of queue. */
  void push(int x) { s.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int x = peek();
    helper.pop();
    return x;
  }

  /** Get the front element. */
  int peek() {
    if (helper.empty())
      while (!s.empty()) {
        helper.push(s.top());
        s.pop();
      }
    int x = helper.top();
    return x;
  }

  /** Returns whether the queue is empty. */
  bool empty() { return s.empty() && helper.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
