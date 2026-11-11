from math import sqrt

EPS = 0.0001  # Требуемая точность поиска.

def volume(x):
    return x * (30 - 2 * x) * (14 - 2 * x)

def f(x):
    return -volume(x)

# Метод золотого сечения.
# На каждом шаге выбираются две точки внутри интервала [a; b].
# Значения функции в этих точках показывают, в какой части интервала
# минимум точно отсутствует. Эта часть отбрасывается.
# Интервал постепенно сужается до точности EPS.
def golden_section(a, b):
    k = (sqrt(5) - 1) / 2

    x1 = b - k * (b - a)
    x2 = a + k * (b - a)

    iterations = 0

    while b - a > EPS:
        iterations += 1
        if f(x1) < f(x2):
            b = x2
            x2 = x1
            x1 = b - k * (b - a)
        else:
            a = x1
            x1 = x2
            x2 = a + k * (b - a)
    return (a + b) / 2, iterations


# Метод квадратичной аппроксимации Пауэлла.
# По трём точкам и значениям функции в них строится приближающая парабола.
# Вершина этой параболы считается новым приближением к минимуму.
# Затем выбираются новые три точки, которые окружают минимум,
# и процесс повторяется до точности EPS.
def powell(a, b, c):
    iterations = 0

    while c - a > EPS:
        fa = f(a)
        fb = f(b)
        fc = f(c)

        numerator = (
            (b**2 - c**2) * fa
            + (c**2 - a**2) * fb
            + (a**2 - b**2) * fc
        )
        denominator = 2 * (
            (b - c) * fa
            + (c - a) * fb
            + (a - b) * fc
        )
        x = numerator / denominator
        fx = f(x)

        iterations += 1

        if x < b:
            if fx < fb:
                c, b = b, x
            else:
                a = x
        else:
            if fx < fb:
                a, b = b, x
            else:
                c = x
    return b, iterations

x_golden, n_golden = golden_section(0, 7)
x_powell, n_powell = powell(0, 3.5, 6.9)

print("Золотое сечение:")
print(f"x = {x_golden:.6f} см")
print(f"Vmax = {volume(x_golden):.6f} см³")
print(f"Итераций: {n_golden}\n")

print("Метод Пауэлла:")
print(f"x = {x_powell:.6f} см")
print(f"Vmax = {volume(x_powell):.6f} см³")
print(f"Итераций: {n_powell}")

# Проверяем, что оба метода нашли x = 3 с требуемой точностью.
assert abs(x_golden - 3) < EPS
assert abs(x_powell - 3) < EPS
