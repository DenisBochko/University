#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *add_node(int x, Node *root);
void  pr_node(Node *root);
void  preorder(Node *root);
void  postorder(Node *root);
void  inorder(Node *root);
Node *find_tree(Node *root, int val);
int   rightmost(Node *root);
Node *del_tree(Node *root, int val);
void  count_nodes(Node *root, int *count);
void  tree_height(Node *root, int depth, int *max_h);
void  del_all(Node *root);
void  preorder_to_file(Node *root, FILE *fp);
int   save_tree(Node *root, const char *filename);
Node *load_tree(const char *filename);

void task0();
