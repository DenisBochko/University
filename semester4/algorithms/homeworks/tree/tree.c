#include "tree.h"

// Печать одного узла
void pr_node(Node *root)
{
    if (root) {
        printf("%d(%p)  left=%p  right=%p\n",
               root->key, (void *)root,
               (void *)root->left, (void *)root->right);
    }
}

// Добавление узла в BST 
Node *add_node(int x, Node *root)
{
    if (!root) {
        root = (Node *)malloc(sizeof(Node));
        if (root) {
            root->key   = x;
            root->left  = NULL;
            root->right = NULL;
        }
        return root;
    }

    if (x < root->key)
        root->left  = add_node(x, root->left);
    else
        root->right = add_node(x, root->right);

    return root;
}

// Прямой (нисходящий) обход
void preorder(Node *root)
{
    if (!root) return;
    pr_node(root);
    preorder(root->left);
    preorder(root->right);
}

// Обратный (восходящий) обход
void postorder(Node *root)
{
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    pr_node(root);
}

// Симметричный (инфиксный) обход
void inorder(Node *root)
{
    if (!root) return;
    inorder(root->left);
    pr_node(root);
    inorder(root->right);
}

// Поиск в дереве

Node *find_tree(Node *root, int val)
{
    if (!root)            return NULL;
    if (val == root->key) return root;
    if (val <  root->key) return find_tree(root->left,  val);
    else                  return find_tree(root->right, val);
}

// Крайний правый узел поддерева (для удаления)
int rightmost(Node *root)
{
    while (root->right)
        root = root->right;
    return root->key;
}

// Удаление узла
Node *del_tree(Node *root, int val)
{
    if (!root) return NULL;

    if (val < root->key) {
        root->left = del_tree(root->left, val);
        return root;
    }
    if (val > root->key) {
        root->right = del_tree(root->right, val);
        return root;
    }

    /* val == root->key — нашли узел для удаления */

    // Лист
    if (!root->left && !root->right) {
        free(root);
        return NULL;
    }
    // Только левый потомок
    if (root->left && !root->right) {
        Node *tmp = root->left;
        free(root);
        return tmp;
    }
    // Только правый потомок
    if (!root->left && root->right) {
        Node *tmp = root->right;
        free(root);
        return tmp;
    }
    // Оба потомка: заменяем ключ на крайний правый из левого поддерева
    root->key  = rightmost(root->left);
    root->left = del_tree(root->left, root->key);
    return root;
}

// Подсчёт узлов 
void count_nodes(Node *root, int *count)
{
    if (!root) return;
    (*count)++;
    count_nodes(root->left,  count);
    count_nodes(root->right, count);
}

// Высота дерева 
void tree_height(Node *root, int depth, int *max_h)
{
    if (!root) return;
    depth++;
    if (!root->left && !root->right) {
        if (depth > *max_h)
            *max_h = depth;
        return;
    }
    tree_height(root->left,  depth, max_h);
    tree_height(root->right, depth, max_h);
}

// Полное удаление дерева (постордер)
void del_all(Node *root)
{
    if (!root) return;
    del_all(root->left);
    del_all(root->right);
    printf("DEL: %p -> %d\n", (void *)root, root->key);
    free(root);
}
