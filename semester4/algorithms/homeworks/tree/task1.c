#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Node* insert_balanced(int arr[], int left, int right, Node *root) {
    if (left > right)
        return root;

    int mid = (left + right) / 2;

    root = add_node(arr[mid], root);

    root = insert_balanced(arr, left, mid - 1, root);
    root = insert_balanced(arr, mid + 1, right, root);

    return root;
}

void sum_at_level(Node *root, int current_level, int k, int *sum) {
    if (!root) return;

    if (current_level == k) {
        *sum += root->key;
        return;
    }

    sum_at_level(root->left,  current_level + 1, k, sum);
    sum_at_level(root->right, current_level + 1, k, sum);
}

void task1()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *root = NULL;
    root = insert_balanced(arr, 0, n - 1, root);

    printf("Сбалансированное дерево:\n");
    inorder(root);
    printf("\n");

    int h = 0;
    tree_height(root, 0, &h);
    printf("Высота дерева: %d\n\n", h);

    int k;
    printf("Введите уровень k: ");
    if (scanf("%d", &k) != 1 || k < 1 || k > h) {
        printf("Некорректный уровень!\n");
        del_all(root);
        return;
    }

    int sum = 0;
    sum_at_level(root, 1, k, &sum);

    printf("Сумма элементов на уровне %d = %d\n", k, sum);
}
