// Single Linked List
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int _v, Node* _next) : val(_v), next(_next) {}
  Node(int _v) : Node(_v, nullptr) {}
};
/**
 * Keep our head, tail and size:
 * Add at head/tail: O(1)
 * Add at other index: O(n)
 * delete index: O(n)
 */
class MyLinkedList {
 public:
  /** Initialize your data structure here. */
  MyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
  ~MyLinkedList() {
    while (head_) {
      Node* node = head_->next;
      delete head_;
      head_ = node;
    }
    tail_ = nullptr;
  }

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (index >= size_ || index < 0) return -1;
    Node* node = head_;
    while (index--) node = node->next;
    return node->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    head_ = new Node(val, head_);  // Update our head pointer
    if (!size_) tail_ = head_;
    ++size_;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    if (!size_)
      addAtHead(val);
    else {
      tail_->next = new Node(val);
      tail_ = tail_->next;  // Update our tail pointer
      ++size_;
    }
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index < 0 || index > size_) return;
    if (!index)
      addAtHead(val);
    else if (index == size_)
      addAtTail(val);
    else {
      Node* node = head_;  // After while-loop: node -> (here) -> index-th node
      for (int i = 1; i < index; ++i) node = node->next;
      node->next = new Node(val, node->next);
      ++size_;
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index < 0 || index >= size_) return;
    Node dummy(0, head_), *node = &dummy;  // the node before index-th node
    for (int i = 0; i < index; ++i) node = node->next;
    Node* tar = node->next;
    node->next = tar->next;
    delete tar;
    if (index == 0) head_ = node->next;
    if (index == size_ - 1) tail_ = index ? node : nullptr;
    --size_;
  }

  friend ostream& operator<<(ostream& out, const MyLinkedList& linked_list);

 private:
  Node *head_, *tail_;
  int size_;
};

ostream& operator<<(ostream& out, const MyLinkedList& linked_list) {
  Node* node = linked_list.head_;
  while (node) {
    out << node->val << " ";
    node = node->next;
  }
  return out;
}

int main() {
  // Your MyLinkedList object will be instantiated and called as such:
  MyLinkedList* obj = new MyLinkedList();
  int param_1 = obj->get(1);
  obj->addAtHead(4);
  obj->addAtTail(6);
  obj->addAtIndex(1, 5);
  obj->addAtTail(7);
  cout << *obj << endl;
  param_1 = obj->get(1);
  obj->deleteAtIndex(3);
  cout << *obj << endl;
  return 0;
}
