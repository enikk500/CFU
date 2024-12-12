#include <iostream>
using namespace std;

// Функция для поиска локальных минимумов и максимумов
void findLocalExtrema(int *arr, int n, int &minCount, int &maxCount)
{
  // Инициализация счетчиков
  minCount = 0;
  maxCount = 0;

  for (int i = 1; i < n - 1; ++i)
  {
    if (arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
    {
      // Текущий элемент является локальным минимумом
      ++minCount;
    }
    else if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
    {
      // Текущий элемент является локальным максимумом
      ++maxCount;
    }
  }
}

int main()
{
  const int N = 7;
  int array[] = {1, 6, 4, 8, 2, 9, 3};
  int minCount = 0;
  int maxCount = 0;

  findLocalExtrema(array, N, minCount, maxCount);

  cout << "Количество локальных минимумов: " << minCount << endl;
  cout << "Количество локальных максимумов: " << maxCount << endl;

  return 0;
}