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

class Solution {
 public:
  // Time: O(n), Space: O(1)
  bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    ListNode* prev = nullptr;
    // Find the middle node
    while (true) {
      // Found the middle
      // Case 1, number of nodes is even: between `prev` and `slow`
      // Case 2, number of nodes is odd: `slow` is middle
      if (fast == nullptr)
        break;
      else if (fast->next == nullptr)  // number of nodes is odd
      {
        // Move from the middle to right part
        slow = slow->next;
        break;
      }

      fast = fast->next->next;
      // Reverse the node `slow` and move to next
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }

    // Split the list into 2 parts
    // L for backward, R for forward
    ListNode *L = prev, *R = slow;
    while (L != nullptr) {
      if (L->val != R->val) return false;
      L = L->next;
      R = R->next;
    }
    return true;
  }
};
