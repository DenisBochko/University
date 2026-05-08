#include "tree.h"

/*
clang ./semester4/algorithms/homeworks/tree/tree.c \
./semester4/algorithms/homeworks/tree/main.c \
./semester4/algorithms/homeworks/tree/task1.c \
-o ./semester4/algorithms/homeworks/tree/tree_hm && \
./semester4/algorithms/homeworks/tree/tree_hm
*/

int main(void)
{
    // Node *root = NULL;
    // root = add_node(50, root);
    // root = add_node(30, root);
    // root = add_node(70, root);
    // root = add_node(20, root);
    // root = add_node(40, root);
    // root = add_node(60, root);
    // root = add_node(80, root);

    // printf("Исходное дерево: \n");
    // inorder(root);

    // save_tree(root, "./semester4/algorithms/homeworks/tree/tree.txt");
    // printf("\nДерево сохранено в tree.txt\n");

    // del_all(root);
    // root = NULL;
    // printf("\nИсходное дерево удалено\n");

    // Node *restored = load_tree("./semester4/algorithms/homeworks/tree/tree.txt");

    // printf("\nВосстановленное дерево: \n");
    // preorder(restored);

    // del_all(restored);

    // return 0;

    task1();
}
