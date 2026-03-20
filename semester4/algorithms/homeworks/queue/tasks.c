#include "queue.h"

// Задание 1
// Напечатать: сначала < a, затем [a,b], затем > b
void task1() {
    pQueue q = createQueue();
    int n, val, a, b, i, len;

    printf("Введите a и b (a < b): ");
    scanf("%d %d", &a, &b);

    printf("Сколько чисел ввести? ");
    scanf("%d", &n);

    printf("Введите %d чисел: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        put(q, val);
    }

    printf("Исходная очередь: ");
    showQ(q);

    len = q->len;

    pQueue result = createQueue();

    for (i = 0; i < len; i++) {
        val = take(q);
        if (val < a)
            put(result, val);
        put(q, val);
    }

    for (i = 0; i < len; i++) {
        val = take(q);
        if (val >= a && val <= b)
            put(result, val);
        put(q, val);
    }

    for (i = 0; i < len; i++) {
        val = take(q);
        if (val > b)
            put(result, val);
        put(q, val);
    }

    printf("Результат: ");
    showQ(result);

    clearQueue(q);
    clearQueue(result);
}

// Задание 2
// Переместить N элементов из первой очереди во вторую
void task2() {
    pQueue first = createQueue();
    pQueue second = createQueue();
    int n, i;

    fillQueueRandom(first, 10);
    printf("Исходная очередь: ");
    showQ(first);

    printf("Сколько элементов переместить (N)? ");
    scanf("%d", &n);

    if (n > first->len)
        n = first->len;

    for (i = 0; i < n; i++) {
        put(second, take(first));
    }

    if (!isEmpty(first))
        printf("Начало первой очереди:  %d\n", first->beg->value);
    else
        printf("Начало первой очереди:  null\n");

    if (!isEmpty(second))
        printf("Начало второй очереди: %d\n", second->beg->value);
    else
        printf("Начало второй очереди: null\n");

    printf("Первая очередь:  ");
    showQ(first);
    printf("Вторая очередь:  ");
    showQ(second);

    clearQueue(first);
    clearQueue(second);
}

// Задание 3
// Две очереди одинакового размера чередуем в одну
void task3() {
    pQueue q1 = createQueue();
    pQueue q2 = createQueue();
    pQueue result = createQueue();

    fillQueueRandom(q1, 5);
    fillQueueRandom(q2, 5);

    printf("Очередь 1: ");
    showQ(q1);
    printf("Очередь 2: ");
    showQ(q2);

    while (!isEmpty(q1) && !isEmpty(q2)) {
        put(result, take(q1));
        put(result, take(q2));
    }

    printf("Результат: ");
    showQ(result);

    printf("Первый элемент:   %d\n", result->beg->value);
    printf("Последний элемент: %d\n", result->end->value);

    clearQueue(q1);
    clearQueue(q2);
    clearQueue(result);
}

// Задание 4
// Перемещать из первой во вторую, пока начало первой не станет чётным
void task4() {
    pQueue first = createQueue();
    pQueue second = createQueue();

    fillQueueRandom(first, 10);

    printf("Исходная очередь: ");
    showQ(first);

    while (!isEmpty(first) && (first->beg->value % 2 != 0)) {
        put(second, take(first));
    }

    if (!isEmpty(first))
        printf("Начало первой очереди:  %d\n", first->beg->value);
    else
        printf("Начало первой очереди:  null\n");

    if (!isEmpty(second))
        printf("Начало второй очереди: %d\n", second->beg->value);
    else
        printf("Начало второй очереди: null\n");

    printf("Первая очередь:  ");
    showQ(first);
    printf("Вторая очередь:  ");
    showQ(second);

    clearQueue(first);
    clearQueue(second);
}
