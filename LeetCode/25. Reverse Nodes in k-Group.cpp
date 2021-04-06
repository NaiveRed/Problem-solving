#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Method 1: Recursive
class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head) return nullptr;
    // 1. Check there exists k node.
    // E.g., 1->2->3->4->5, node is at 1
    ListNode* node = head;
    for (int i = 1; i <= k; ++i)
      if (node)
        node = node->next;
      else
        return head;  // remain the nodes if less than k
    // Now node is at k+1 position
    // E.g., 1->2->3->4->5, k=3, node is at 4

    // 2. Get the head of next group.
    // E.g., 1->2->3-> 4(prev)->5.
    ListNode* prev = reverseKGroup(node, k);  // The head of next group.

    // 3. Reverse the nodes of current part.
    // and the first node should link to the head of next group.
    // E.g., 1(node)-> next_group(prev).
    // E.g., 2(node)->1(prev)-> next_group.
    node = head;
    for (int i = 1; i <= k; ++i) {
      // Reversed linked
      ListNode* tmp_next = node->next;
      node->next = prev;

      // E.g.,
      // i==1: 1(node)->4(prev)->5, 2(tmp_next)->3
      // i==2: 2(node)->1(prev)->4->5, 3(tmp_next)->4
      // i==3: 3(node)->2(prev)->1->4->5, 4(tmp_next)->5

      // Advance
      prev = node;
      node = tmp_next;
    }

    // 4. Return the new head
    // i==4: 3(prev)->2->1->4->5, 4(node)->5
    return prev;
  }
};
