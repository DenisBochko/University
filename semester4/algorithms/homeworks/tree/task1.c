#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* Построение сбалансированного дерева из отсортированного массива */
Node* build_balanced(int arr[], int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;

    Node* node = (Node *)malloc(sizeof(Node));
    if (!node) return NULL;

    node->key   = arr[mid];
    node->left  = build_balanced(arr, left, mid - 1);
    node->right = build_balanced(arr, mid + 1, right);

    return node;
}

/* Сумма элементов на уровне k (корень — уровень 1) */
void sum_at_level(Node* root, int current_level, int k, long long* sum)
{
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

    Node *root = build_balanced(arr, 0, n - 1);

    printf("Сбалансированное дерево:\n");
    inorder(root);
    printf("\n");

    /* Используем tree_height из tree.c */
    int h = 0;
    tree_height(root, 0, &h);
    printf("Высота дерева: %d\n\n", h);

    int k;
    printf("Введите уровень k (1..%d): ", h);
    if (scanf("%d", &k) != 1 || k < 1 || k > h) {
        printf("Некорректный уровень!\n");
        del_all(root);
        return;
    }

    long long sum = 0;
    sum_at_level(root, 1, k, &sum);

    printf("Сумма элементов на уровне %d = %lld\n", k, sum);
}
