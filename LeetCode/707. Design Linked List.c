#include <stdio.h>
#include <stdlib.h>

// The first node will be the head
typedef struct MyLinkedList_tag {
  int val;
  struct MyLinkedList_tag* next;
} MyLinkedList;

MyLinkedList* getNodeByIndex(MyLinkedList* obj, int index) {
  while (index >= 0) {
    obj = obj->next;
    --index;
    if (obj == NULL) return NULL;
  }
  return obj;
}
/************************/

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
  MyLinkedList* node = malloc(sizeof(MyLinkedList));
  if (node == NULL) return NULL;
  node->next = NULL;
  return node;
}

/** Get the value of the index-th node in the linked list. If the index is
 * invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
  MyLinkedList* node = getNodeByIndex(obj, index);
  return node ? node->val : -1;
}

/** Add a node of value val before the first element of the linked list. After
 * the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
  MyLinkedList* node = myLinkedListCreate();
  node->val = val;
  node->next = obj->next;
  obj->next = node;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
  MyLinkedList* node = myLinkedListCreate();
  node->val = val;
  while (obj->next != NULL) obj = obj->next;
  obj->next = node;
}

/** Add a node of value val before the index-th node in the linked list. If
 * index equals to the length of linked list, the node will be appended to the
 * end of linked list. If index is greater than the length, the node will not be
 * inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
  // index-1 for prev, since we need to add before index
  MyLinkedList* prev = getNodeByIndex(obj, index - 1);
  if (prev == NULL) return;
  MyLinkedList* node = myLinkedListCreate();
  node->val = val;
  node->next = prev->next;
  prev->next = node;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
  MyLinkedList* prev = getNodeByIndex(obj, index - 1);
  if (prev == NULL || prev->next == NULL) return;
  obj = prev->next;
  prev->next = obj->next;
  free(obj);
}

void myLinkedListFree(MyLinkedList* obj) {
  while (obj != NULL) {
    MyLinkedList* node = obj->next;
    free(obj);
    obj = node;
  }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/
int main() {
  MyLinkedList* obj = myLinkedListCreate();
  myLinkedListAddAtHead(obj, 1);
  myLinkedListAddAtTail(obj, 2);
  myLinkedListAddAtIndex(obj, 2, 3);
  printf("%d %d %d\n", myLinkedListGet(obj, 0), myLinkedListGet(obj, 1),
         myLinkedListGet(obj, 2));
  myLinkedListDeleteAtIndex(obj, 1);
  printf("%d %d %d\n", myLinkedListGet(obj, 0), myLinkedListGet(obj, 1),
         myLinkedListGet(obj, 2));
  myLinkedListFree(obj);
  return 0;
}
