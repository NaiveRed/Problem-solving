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

/**
 * left: 2, right: 4
 * 1 -> 2 -> 3 -> 4 -> 5
 * become:
 * ---------------
 * |             v
 * 1   2 <- 3 <- 4   5
 *     \             ^
 *     ---------------
 *
 * Use dummy head to deal with left: 1
 * Time: O(n), Space: O(1)
 */
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right || !head) return head;

    ListNode dummy_head(0, head);
    // Find the node before `left` position
    ListNode* left_prev = &dummy_head;
    for (int i = 0; i < left - 1; ++i) left_prev = left_prev->next;

    // Find the node after `right` position
    // And reverse the nodes between `left`(exclude) and `right`(include).
    ListNode* right_next = left_prev->next;
    // prev is for reversing and its final position will be `right`.
    ListNode* prev = nullptr;
    for (int i = left; i <= right; ++i) {
      ListNode* next = right_next->next;
      right_next->next = prev;
      prev = right_next;
      right_next = next;
    }

    // Link the `left` to the node after `right`
    left_prev->next->next = right_next;
    // Link the previous of `left` to the `right`
    left_prev->next = prev;
    return dummy_head.next;
  }
};
