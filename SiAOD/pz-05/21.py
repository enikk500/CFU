def quicksort(arr):
    # Если длина массива 0 или 1, возвращаем его
    if len(arr) <= 1:
        return arr
    
    # Опорный элемент
    pivot = arr[len(arr) // 2]
    
    # Разделяем массив на три части
    left = [x for x in arr if x < pivot]     # Меньше опорного
    middle = [x for x in arr if x == pivot] # Равно опорному
    right = [x for x in arr if x > pivot]   # Больше опорного
    
    # Рекурсивно сортируем левую и правую части
    return quicksort(left) + middle + quicksort(right)

# Ввод массива
n = int(input("Введите количество элементов массива: "))
array = []

print("Введите элементы массива:")
for _ in range(n):
    element = int(input())
    array.append(element)

# Выбор направления сортировки
direction = input("Сортировать по неубыванию (asc8) или невозрастанию (desc)? ")

# Сортировка
if direction.lower() == "asc":
    sorted_array = quicksort(array)
elif direction.lower() == "desc":
    sorted_array = quicksort(array)[::-1]
else:
    print("Неверный выбор направления сортировки. Используем сортировку по неубыванию.")
    sorted_array = quicksort(array)

# Вывод результата
print("Отсортированный массив:", sorted_array)
