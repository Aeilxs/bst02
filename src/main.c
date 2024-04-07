#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rnum;
    srand(time(NULL));
    Node *root = NULL;

    for (int i = 0; i < 20; i++) {
        rnum = rand() % 101;
        printf("==========================\n");
        printf("[INSERT n°%3d] [RNUM:%3d]\n", i + 1, rnum);
        root = insert(root, create_node(rnum));
    }

    return 0;
}
