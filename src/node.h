#ifndef NODE_H
#define NODE_H

typedef struct _Node {
    int data;
    struct _Node *left;
    struct _Node *right;
} Node;

Node *create_node(int data);
Node *insert(Node *R, Node *N);
Node *rmv_node(Node *root, int search_data);

void pre_order(Node *R);
void in_order(Node *R);
void post_order(Node *R);

void free_tree(Node *R);
void search(Node *R, int data);

#endif // NODE_H