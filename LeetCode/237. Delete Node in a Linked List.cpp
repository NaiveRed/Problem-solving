#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void deleteNode(ListNode* node) {
    ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    // delete next; // Delete when it was allocated on heap
  }
};
int main() {
  Solution solution;
  ListNode node1(5), node2(6), node3(7);
  node1.next = &node2;
  node2.next = &node3;
  solution.deleteNode(&node1);
  cout << node1.val << " " << node2.val << " " << node3.val << endl;
  return 0;
}
