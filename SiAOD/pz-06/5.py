import numpy as np

# Ввод массива X
n = int(input("Введите размер массива X: "))
X = []

print("Введите элементы массива X:")
for _ in range(n):
    X.append(float(input()))

# Преобразуем массив в вектор NumPy
X = np.array(X)

# Построение матрицы A
A = np.outer(X, X)

# Вычисление суммы квадратов элементов матрицы
sum_of_squares = np.sum(A ** 2)

# Вычисление корня из суммы
result = np.sqrt(sum_of_squares)

# Вывод результатов
print("Матрица A:")
print(A)
print(f"Результат вычисления: {result}")
