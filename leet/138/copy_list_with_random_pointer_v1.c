  // Note: this version gives "Node with val 11 was not copied but a reference to the original one".
#include "build_list.h"
#include <stdlib.h>
#include <stdio.h>

struct Node* copyRandomListV1(struct Node* head) {
  if (!head) return NULL;

  // Computer size
  size_t sz = 0;
  Node* node = head;
  while (node) {
    ++sz;
    node = node->next;
  }

  typedef struct RestorePtr{
    Node* original_random;
  } RestorePtr;

  RestorePtr* restore_ptr = (RestorePtr*)malloc(sizeof(RestorePtr)*sz);

  Node* ret = (Node*)malloc(sizeof(Node) * sz);
  node = head;
  for (size_t i = 0; i < sz; ++i) {
    ret[i].val = node->val;
    ret[i].next = i+1 < sz ? ret+i+1  : NULL;
    ret[i].random = node->random; //will fix in a second pass below

    // Using random to get a mapping from old to new. Avoid hash table this way.
    restore_ptr[i].original_random = node->random;
    node->random = &ret[i];
    node = node->next;
  }

  // Fix it.
  for (size_t i = 0; i < sz; ++i) {
    Node* r = ret[i].random;
    ret[i].random = r ? r->random : NULL;
  }

  // Restore random ptr
  node = head;
  for (size_t i = 0; i < sz; ++i) {
    node->random = restore_ptr[i].original_random;
    node = node->next;
  }

  free(restore_ptr);
  return ret;
}

