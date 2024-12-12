import numpy as np

# Ввод размерности матрицы
n = int(input("Введите количество строк (n): "))
m = int(input("Введите количество столбцов (m): "))

# Ввод матрицы
print("Введите элементы матрицы построчно:")
A = []
for i in range(n):
    row = list(map(int, input(f"Строка {i+1}: ").split()))
    A.append(row)

# Преобразуем в NumPy массив для удобства (можно оставить списком)
A = np.array(A)

# Множество для хранения уникальных элементов
seen = set()

# Замена повторяющихся элементов на нули
for i in range(n):
    for j in range(m):
        if A[i, j] in seen:
            A[i, j] = 0  # Если элемент уже был, заменяем на 0
        else:
            seen.add(A[i, j])  # Иначе добавляем его в множество

# Вывод результата
print("Матрица после замены повторяющихся элементов нулями:")
print(A)