#include "tree.h"

/*
clang ./semester4/algorithms/homeworks/tree/tree.c \
./semester4/algorithms/homeworks/tree/main.c \
-o ./semester4/algorithms/homeworks/tree/tree_hm && \
./semester4/algorithms/homeworks/tree/tree_hm
*/

int main(void)
{
    Node *root = NULL;
    Node *p;
    int i, j, k;
    int n_nodes, height;

    srand((unsigned)time(NULL));

    root = add_node(10, root);
    printf("10 ");
    for (i = 0; i < 7; i++) {
        k = rand() % 21;
        root = add_node(k, root);
        printf("%d ", k);
    }
    printf("\n");

    // Обходы 
    printf("\n--- preorder ---\n");
    preorder(root);

    printf("\n--- postorder ---\n");
    postorder(root);

    printf("\n--- inorder ---\n");
    inorder(root);

    // Количество узлов и высота 
    n_nodes = 0;
    count_nodes(root, &n_nodes);
    printf("\nNodes in tree: %d\n", n_nodes);

    height = 0;
    tree_height(root, 0, &height);
    printf("Tree height:   %d\n", height);

    // Попытка найти и удалить до 3 случайных элементов
    for (j = 0, i = 0; i < 5 && j < 3; i++) {
        k = rand() % 21;
        p = find_tree(root, k);
        if (p) {
            printf("\nFound: ");
            pr_node(p);
            root = del_tree(root, k);
            printf("After deletion:\n");
            inorder(root);
            j++;
        } else {
            printf("\nValue %d not found\n", k);
        }
    }

    printf("\n--- end delete ---\n");
    postorder(root);

    // Удаляем всё дерево 
    printf("\n--- deleting entire tree ---\n");
    del_all(root);
    root = NULL;
    printf("root = %p\n", (void *)root);

    return 0;
}
