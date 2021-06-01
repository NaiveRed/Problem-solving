#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/*
Assume the common part: 845 (can be null)
whole a: 41845
whole b: 561845
concate two list:
--------- =============
4 1 8 4 5 5 6 1 (8 4 5)
5 6 1 8 4 5 4 1 (8 4 5)
=========== -----------
They will match the second common part finally.
*/
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa || pb) {
      if (pa == pb)  // Include the not intersection case (nullptr)
        return pa;
      pa = pa ? pa->next : headB;
      pb = pb ? pb->next : headA;
    }
    return nullptr;
  }
};
