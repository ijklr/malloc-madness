#include "build_list.h"
#include <stdlib.h>
#include <stdio.h>
// Note: this version gives "Node with val 11 was not copied but a reference to the original one".
Node* copyRandomListV1(struct Node* head);

// More "legit" version because the free() is called correctly.
Node* copyRandomListV2(struct Node* head);

void print_node(Node* node) {
  const Node* head = node;
  for(int i=0; node != NULL; ++i) {
    printf("node %d val: %d this: %ld next: %ld random: %ld random ptr:%p \n", 
           i, node->val, node-head, node->next == NULL? -1 : node->next - head,
           node->random == NULL? -1: node->random - head, (void*)node->random);
    printf("head=%p node=%p n-h=%ld\n", (void*)head, (void*)node, node - head);
    node = node->next;
  }
}

void test_V1() {
  printf("===========V1 test===========\n");
  int data[5][2]= {{7,-1},{13,0},{11,4},{10,2},{1,0}};
  Node* node =  buildList(data, 5);
  print_node(node);
  printf("\n\nabout to copy..\n");
  Node* ret = copyRandomListV1(node);
  printf("\n\ncopied!\n");
  printf("original:\n");
  print_node(node);
  printf("new:\n");
  print_node(ret);
  free(node);
  free(ret);
}

void test_V2() {
  printf("===========V2 test===========\n");
  int data[5][2]= {{7,-1},{13,0},{11,4},{10,2},{1,0}};
  Node* node =  buildList(data, 5);
  print_node(node);
  printf("\n\nabout to copy..\n");
  Node* ret = copyRandomListV2(node);
  printf("\n\ncopied!\n");
  printf("original:\n");
  print_node(node);
  printf("new:\n");
  print_node(ret);
  free(node);
  free(ret);
}

int main(void) {
  test_V1();
  test_V2();
  return EXIT_SUCCESS;
}

