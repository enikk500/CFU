def add_polynomials(poly1, poly2):
    # определяем максимальную длину
    max_length = max(len(poly1), len(poly2))
    
    # дополняем полиномы нулями до одинаковой длины
    poly1 = poly1 + [0] * (max_length - len(poly1))
    poly2 = poly2 + [0] * (max_length - len(poly2))
    
    # cкладываем коэффициенты
    result = [poly1[i] + poly2[i] for i in range(max_length)]
    
    return result

# Пример использования
poly1 = [1, 2, 3]  # Представляет 1 + 2x + 3x^2
poly2 = [3, 4]     # Представляет 3 + 4x

result = add_polynomials(poly1, poly2) # в результат саму функцию поли1 и поли2
print("Сумма полиномов:", result)  # тут результат