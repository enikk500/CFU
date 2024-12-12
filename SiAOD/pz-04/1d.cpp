#include <iostream>
#include <cmath> // Для функции pow и factorial

using namespace std;

// Функция для вычисления факториала
unsigned long long factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  unsigned long long result = 1;
  for (int i = 2; i <= n; ++i)
  {
    result *= i;
  }
  return result;
}

// Основная функция для вычисления суммы
double calculateSeriesSum(double x, double epsilon)
{
  double sum = 0.0; // Итоговая сумма
  int k = 0;        // Счетчик итераций
  double term;      // Текущий член ряда

  do
  {
    // Вычисление члена ряда
    term = pow(-1, k) * pow(x / 2, 2 * k + 1) / (factorial(k) * factorial(k + 1));

    // Добавляем текущий член ряда к сумме
    sum += term;

    // Увеличиваем счетчик
    ++k;
  } while (abs(term) > epsilon); // Условие остановки: |term| <= epsilon

  return sum;
}

int main()
{
  // Ввод данных
  double x, epsilon;
  cout << "Введите x: ";
  cin >> x;
  cout << "Введите точность epsilon: ";
  cin >> epsilon;

  // Вычисление суммы
  double result = calculateSeriesSum(x, epsilon);

  // Вывод результата
  cout << "Сумма ряда с точностью " << epsilon << " равна: " << result << endl;

  return 0;
}
