#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/*
Assume the common part: c (can be null)
the remain part of a: a
the remain part of b: b
whole a: ac
whole b: bc
concate two list:
acbc
bcac
they will match the second common part finally
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
