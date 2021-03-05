#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* node = head;
    // Create a duplicate node followed by original one.
    // i.e., A -> A' -> B -> B' -> x
    while (node) {
      Node *next = node->next, *dup_node = new Node(node->val);
      dup_node->next = next;
      node->next = dup_node;
      node = next;
    }

    // Set `random` of duplicates.
    node = head;
    while (node) {
      if (node->random) {
        // node->next: duplicate
        // node->random->next: duplicate of random
        node->next->random = node->random->next;
      }
      // Go to next original node.
      node = node->next->next;
    }

    // Set `next` of duplicates.
    // Recover the original list.
    node = head;
    Node *dup_head = node->next, *dup_node = dup_head;
    while (node) {
      Node* ori_next = dup_node->next;
      if (ori_next)
        dup_node->next = ori_next->next;  // Set `next` of the duplicate node
      node->next = ori_next;              // Recover `next` of the original node

      // Advance to next pair
      node = node->next;
      dup_node = dup_node->next;
    }

    return dup_head;
  }
};
