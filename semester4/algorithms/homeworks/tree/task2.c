#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sub {
    long long phone;
    char owner[64];
    char tariff[32];
    struct Sub *left;
    struct Sub *right;
} Sub;

Sub *add_sub(long long phone, char *owner, char *tariff, Sub *root)
{
    if (!root) {
        root = (Sub *)malloc(sizeof(Sub));
        root->phone = phone;
        strcpy(root->owner, owner);
        strcpy(root->tariff, tariff);
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if (phone < root->phone)
        root->left = add_sub(phone, owner, tariff, root->left);
    else
        root->right = add_sub(phone, owner, tariff, root->right);

    return root;
}

void print_db(Sub *root)
{
    if (!root) return;
    print_db(root->left);
    printf("%lld  |  %s  |  %s\n", root->phone, root->owner, root->tariff);
    print_db(root->right);
}

Sub *find_phone(Sub *root, long long phone)
{
    if (!root) return NULL;
    if (phone == root->phone) return root;
    if (phone < root->phone) return find_phone(root->left, phone);
    return find_phone(root->right, phone);
}

void popular_tariff(Sub *root, char tariffs[][32], int counts[], int *n)
{
    if (!root) return;

    int i;
    for (i = 0; i < *n; i++) {
        if (strcmp(tariffs[i], root->tariff) == 0) {
            counts[i]++;
            break;
        }
    }

    if (i == *n) {
        strcpy(tariffs[*n], root->tariff);
        counts[*n] = 1;
        (*n)++;
    }

    popular_tariff(root->left, tariffs, counts, n);
    popular_tariff(root->right, tariffs, counts, n);
}

void del_all_subs(Sub *root)
{
    if (!root) return;
    del_all_subs(root->left);
    del_all_subs(root->right);
    free(root);
}

void task2()
{
    Sub *db = NULL;

    db = add_sub(9031112233LL, "Иванов Иван",     "Безлимит",  db);
    db = add_sub(9055554477LL, "Петрова Мария",    "Эконом",    db);
    db = add_sub(9161234567LL, "Сидоров Алексей",  "Безлимит",  db);
    db = add_sub(9099876543LL, "Козлова Елена",    "Стандарт",  db);
    db = add_sub(9012345678LL, "Морозов Дмитрий",  "Эконом",    db);
    db = add_sub(9267778899LL, "Новикова Анна",    "Безлимит",  db);
    db = add_sub(9031119988LL, "Фёдоров Сергей",   "Стандарт",  db);
    db = add_sub(9151234567LL, "Волкова Ольга",    "Эконом",    db);

    printf("=== База данных ===\n");
    printf("Телефон       |  Владелец       |  Тариф\n");
    printf("----------------------------------------------\n");
    print_db(db);

    printf("\n=== Поиск ===\n");
    long long num;
    printf("Введите номер: ");
    scanf("%lld", &num);

    Sub *found = find_phone(db, num);
    if (found)
        printf("Владелец: %s, тариф: %s\n", found->owner, found->tariff);
    else
        printf("Не найден.\n");

    printf("\n=== Популярный тариф ===\n");

    char tariffs[50][32];
    int counts[50];
    int n = 0;

    popular_tariff(db, tariffs, counts, &n);

    int max_i = 0;
    for (int i = 1; i < n; i++) {
        if (counts[i] > counts[max_i])
            max_i = i;
    }
    printf("Самый популярный: %s (%d абонентов)\n", tariffs[max_i], counts[max_i]);

    del_all_subs(db);
}
