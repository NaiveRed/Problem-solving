#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution
{
public:
  Node *flatten(Node *head)
  {
    stack<Node *> s;
    for (Node *current = head; current; current = current->next)
    {
      if (current->child)
      {
        if (current->next)
          s.push(current->next);
        current->next = current->child;
        current->child->prev = current;
        current->child = nullptr;
      }

      if (!current->next && !s.empty())
      {
        // Reach the end of one level
        Node *prev_level = s.top(); // The next node on the previous level
        s.pop();
        current->next = prev_level;
        prev_level->prev = current;
      }
    }

    return head;
  }
};