#include "stack.h"

// Задание 1
// Разделить стек на положительные и отрицательные
void task1() {
    pStack src = createStack();
    pStack pos = createStack();
    pStack neg = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c >= 0)
            push(pos, c);
        else
            push(neg, c);
    }

    printf("Положительные:  ");
    showStack(pos);
    printf("Отрицательные:  ");
    showStack(neg);

    clearStack(pos); free(pos);
    clearStack(neg); free(neg);
    clearStack(temp); free(temp);
    free(src);
}

// Задание 2
// Разделить на чётные и нечётные, вывести вершины
void task2() {
    pStack src = createStack();
    pStack even_s = createStack();  
    pStack odd_s = createStack(); 
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c % 2 == 0)
            push(even_s, c);
        else
            push(odd_s, c);
    }

    if (!isEmpty(even_s))
        printf("Вершина чётных: %d\n", peek(even_s));
    else
        printf("Вершина чётных: null\n");

    if (!isEmpty(odd_s))
        printf("Вершина нечётных: %d\n", peek(odd_s));
    else
        printf("Вершина нечётных: null\n");

    clearStack(even_s); free(even_s);
    clearStack(odd_s); free(odd_s);
    clearStack(temp); free(temp);
    free(src);
}

// Задание 3
// Перемещать из первого во второй, пока вершина первого не станет чётной
void task3() {
    pStack first = createStack();
    pStack second = createStack();

    fillRandom(first, 10);
    printf("Исходный стек: ");
    showStack(first);

    while (!isEmpty(first) && (peek(first) % 2 != 0)) {
        push(second, pop(first));
    }

    pStack temp = createStack();
    while (!isEmpty(second)) {
        push(temp, pop(second));
    }
    while (!isEmpty(temp)) {
        push(second, pop(temp));
    }

    if (!isEmpty(first))
        printf("Вершина первого:  %d\n", peek(first));
    else
        printf("Вершина первого:  null\n");

    if (!isEmpty(second))
        printf("Вершина второго:  %d\n", peek(second));
    else
        printf("Вершина второго:  null\n");

    clearStack(first); free(first);
    clearStack(second); free(second);
    clearStack(temp); free(temp);
}

// Задание 4
// Удалить из стека все элементы с чётными значениями
void task4() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (c % 2 != 0) {
            push(src, c);
        }
    }

    printf("После удаления чётных: ");
    showStack(src);

    clearStack(src); free(src);
    clearStack(temp); free(temp);
}

// Задание 5
// Удалить каждый второй элемент
void task5() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    int count = 1;
    while (!isEmpty(temp)) {
        int c = pop(temp);
        if (count % 2 != 0) {
            push(src, c);
        }
        count++;
    }

    printf("После удаления каждого 2-го: ");
    showStack(src);

    clearStack(src); free(src);
    clearStack(temp); free(temp);
}

// Задание 6
// Вывести содержимое стека, начиная с обратного конца (т.е. со дна)
void task6() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек (с вершины):  ");
    showStack(src);

    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    printf("С обратного конца (со дна): ");
    while (!isEmpty(temp)) {
        int c = pop(temp);
        printf("%d ", c);
        push(src, c);  // восстанавливаем исходный стек
    }
    printf("\n");

    clearStack(src); free(src);
    clearStack(temp); free(temp);
}

// Задание 7
// Текстовый редактор: '#' стирает один символ, '@' стирает все
// Чтение из файла input.txt, запись результата в output.txt
void task7() {
    pStack charStack = createStack();
    pStack temp = createStack();

    // --- Открываем входной файл ---
    FILE* fin = fopen("input.txt", "r");
    if (!fin) {
        printf("Ошибка: не удалось открыть input.txt\n");
        free(charStack);
        free(temp);
        return;
    }

    printf("Чтение из файла input.txt...\n");
    printf("Содержимое файла: \"");

    int ch;
    // --- Посимвольное чтение из файла ---
    while ((ch = fgetc(fin)) != EOF) {
        printf("%c", (char)ch);

        if ((char)ch == '#') {
            // Стирающий символ — удалить вершину
            if (!isEmpty(charStack)) {
                pop(charStack);
            }
        } else if ((char)ch == '@') {
            // Символ-убийца — очистить весь стек
            clearStack(charStack);
        } else if ((char)ch != '\n' && (char)ch != '\r') {
            // Обычный символ — помещаем в стек
            // (переносы строк игнорируем)
            push(charStack, ch);
        }
    }
    fclose(fin);
    printf("\"\n");

    // --- Переворачиваем стек для правильного порядка ---
    while (!isEmpty(charStack)) {
        push(temp, pop(charStack));
    }

    // --- Записываем результат в выходной файл ---
    FILE* fout = fopen("output.txt", "w");
    if (!fout) {
        printf("Ошибка: не удалось создать output.txt\n");
        clearStack(temp); free(temp);
        free(charStack);
        return;
    }

    printf("Результат:       \"");
    while (!isEmpty(temp)) {
        char c = (char)pop(temp);
        printf("%c", c);
        fputc(c, fout);
    }
    printf("\"\n");

    fclose(fout);
    printf("Результат записан в output.txt\n");

    free(charStack);
    free(temp);
}

// Задание 8
// Поменять местами крайние элементы стека (вершину и дно)
void task8() {
    pStack src = createStack();
    pStack temp = createStack();

    fillRandom(src, 10);
    printf("Исходный стек: ");
    showStack(src);

    if (isEmpty(src) || src->len == 1) {
        printf("Менять нечего (0 или 1 элемент)\n");
        clearStack(src); free(src);
        free(temp);
        return;
    }

    // 1) Извлекаем вершину
    int topVal = pop(src);

    // 2) Перекладываем всё из src в temp
    while (!isEmpty(src)) {
        push(temp, pop(src));
    }

    // 3) Извлекаем дно (оно теперь на вершине temp)
    int bottomVal = pop(temp);

    // 4) Кладём старую вершину на место дна
    push(src, topVal);

    // 5) Возвращаем середину обратно
    while (!isEmpty(temp)) {
        push(src, pop(temp));
    }

    // 6) Кладём старое дно на место вершины
    push(src, bottomVal);

    printf("После обмена:  ");
    showStack(src);

    clearStack(src); free(src);
    free(temp);
}

// Задание 9
// Проверка правильности скобочной последовательности
void task9() {
    const char* input = "{[]({[]})}";  // можно менять для тестов
    printf("Строка: \"%s\"\n", input);

    pStack bracketStack = createStack();
    int valid = 1;
    int i = 0;

    while (input[i] != '\0' && valid) {
        char ch = input[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            // Открывающая скобка — кладём в стек
            push(bracketStack, (int)ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            // Закрывающая скобка — проверяем пару
            if (isEmpty(bracketStack)) {
                valid = 0;
            } else {
                int top = pop(bracketStack);
                if ((ch == ')' && top != '(') ||
                    (ch == ']' && top != '[') ||
                    (ch == '}' && top != '{')) {
                    valid = 0;
                }
            }
        }
        // Остальные символы игнорируем
        i++;
    }

    // Если стек не пуст — есть незакрытые скобки
    if (!isEmpty(bracketStack)) {
        valid = 0;
    }

    if (valid)
        printf("Последовательность правильная\n");
    else
        printf("Последовательность НЕправильная\n");

    clearStack(bracketStack);
    free(bracketStack);
}