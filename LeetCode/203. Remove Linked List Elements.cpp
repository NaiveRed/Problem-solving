#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode *prev_node = head, *current = head;
    while (current)
    {
      if (current->val == val)
      {
        if (head == current)
          head = current->next;
        else
          prev_node->next = current->next;
      }
      else
        prev_node = current;

      current = current->next;
    }
    return head;
  }
};