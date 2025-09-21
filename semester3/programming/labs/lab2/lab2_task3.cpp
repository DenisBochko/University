#include <cstdio>

int a(); 
int b(); 
int c(); 
int d(); 
int e(); 
int f(); 
int g(); 

int main() {
    // printf("%d\n", a());
    // printf("%d\n", b());
    // printf("%d\n", c());
    // printf("%d\n", d());
    // printf("%d\n", e());
    // printf("%d\n", f());
    // printf("%d\n", g());

    return 0;
}

int a() {
    int a = 0, b;
    while ((b = getchar()) != '.') {
        if (b == 'a') a++;
    }
    return a;
}

int b() {
    int a = 0, b;
    while ((b = getchar()) != '.' && b != 'u') {
        if (b == 'e') a++;
    }

    return a;
}

int c() {
    int a = 0, b = -1, c1;
    while ((c1 = getchar()) != '.') {
        if ((b == 'n' && c1 == 'o') || (b == 'o' && c1 == 'n')) a++;
        b = c1;
    }
    return a;
}

int d() {
    int a = 0;
    int b = 0;
    int c1;
    while ((c1 = getchar()) != '.') {
        if (c1 == '+' || c1 == '-') {
            if (b != 0 && c1 != b) a++;
            b = c1;
        }
    }
    return a;
}

int e() {
    int a = 0, b = -1, c1 = -1, d1;
    while ((d1 = getchar()) != '.') {
        if (b == 'c' && c1 == '+' && d1 == '+') a++;
        b = c1;
        c1 = d1;
    }
    return a;
}

int f() {
    int a = -1, b = -1, c1 = -1, d1;
    while ((d1 = getchar()) != '.') {

        a = b; b = c1; c1 = d1;
        if (a == 'c' && b == 'h' && c1 == 'a' && d1 == 'r') return 1;
    }
    return 0;
}

int g() {
    int a = 0; 
    int b = 0; 
    int c1 = 0;
    int d1;
    while ((d1 = getchar()) != '.') {
        if (c1 != 0 && d1 == c1 + 1 && d1 >= 'a' && d1 <= 'z' && c1 >= 'a' && c1 <= 'z') {
            b++;
        } else if (d1 >= 'a' && d1 <= 'z') {
            b = 1;
        } else {
            b = 0;
        }
        c1 = d1;
        if (b > a) a = b;
    }
    return a;
}
