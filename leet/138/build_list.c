#include <stdlib.h>  // For malloc
#include "node.h"

struct Node* buildList(int data[][2], size_t size) {
    if (size == 0) return NULL;

    // Allocate memory for an array of nodes
    Node* nodes = (Node*)malloc(size * sizeof(Node));
    if (nodes == NULL) return NULL;  // Handle allocation failure

    // Set val/next/random
    for (size_t i = 0; i < size; i++) {
        nodes[i].val = data[i][0];
        nodes[i].next = i+1 < size ? &nodes[i+1] : NULL;
        int r = data[i][1];
        nodes[i].random = r == -1? NULL : &nodes[r];
    }

    return nodes;


}
