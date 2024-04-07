#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node *create_node(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL) {
        fprintf(stderr, "[FATAL] Malloc error\nNeeded %zu bytes\n", sizeof(Node));
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node *insert(Node *root, Node *node) {
    // clang-format off
    if (root == NULL) return node;
    else if (node->data < root->data) root->left  = insert(root->left, node);
    else if (node->data > root->data) root->right = insert(root->right, node);
    else free(node);
    return root;
    // clang-format on
}

void pre_order(Node *root) {
    if (root == NULL) return;
    printf("[%d] ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node *root) {
    if (root == NULL) return;
    in_order(root->left);
    printf("[%d] ", root->data);
    in_order(root->right);
}

void post_order(Node *root) {
    if (root == NULL) return;
    post_order(root->left);
    post_order(root->right);
    printf("[%d] ", root->data);
}

void free_tree(Node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// void search(Node *R, int data);

Node *insert_left(Node *root, Node *ins) {
    if (root == NULL) return ins;
    root->left = insert_left(root->left, ins);
    return root;
}

Node *rmv_node(Node *root, int search_data) {
    if (root == NULL) {
        printf("Empty tree");
        return NULL;
    } else if (root->data == search_data) {
        printf("[VAL: %d ROOT ADR: %p ROOT DATA: %p]", root->data, root, root->data);
        Node *tmp = root;
        root = insert_left(root->left, root->right);
        free(tmp);
        return root;
    } else if (root->data < search_data) {
        root->right = rmv_node(root->right, search_data);
        return root;
    } else if (root->data > search_data) {
        root->left = rmv_node(root->left, search_data);
        return root;
    }
}
