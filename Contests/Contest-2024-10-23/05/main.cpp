#include <iostream>
#include <vector>

class IComparator
{
public:
  virtual bool compare(int a, int b) const = 0;
};

bool less(int a, int b)
{
  return a < b;
}

void greater(int a, int b, bool &verdict)
{
  verdict = a > b;
}

double key_func(int value)
{
  return abs(value);
}

class LessAdapter : public IComparator
{
  using func = bool (*)(int a, int b);
  func cmp;

public:
  LessAdapter(func cmp) : cmp(cmp)
  {
  }

  bool compare(int a, int b) const override
  {
    return cmp(a, b);
  }
};

// Ваш код здесь

class GreaterAdapter : public IComparator
{
  using func = void (*)(int a, int b, bool &verd);
  func comp;

public:
  GreaterAdapter(func comp) : comp(comp)
  {
  }

  bool compare(int fir, int sec) const override
  {
    bool result;
    comp(fir, sec, result);
    return result;
  }
};

class KeyFuncLessAdapter : public IComparator
{
  using func = double (*)(int value);
  func function_k;

public:
  KeyFuncLessAdapter(func function_k) : function_k(function_k)
  {
  }

  bool compare(int fir, int sec) const override
  {
    return function_k(fir) < function_k(sec);
  }
};

void bubbleSort(std::vector<int> &arr, const IComparator &comp)
{
  for (int i = 0; i < arr.size() - 1; i++)
    for (int j = 0; j < arr.size() - i - 1; j++)
      if (comp.compare(arr[j], arr[j + 1]))
        std::swap(arr[j], arr[j + 1]);
}

int main()
{
  int size;
  std::cin >> size;
  std::vector<int> arr(size);
  for (auto &i : arr)
    std::cin >> i;

  bubbleSort(arr, LessAdapter(less));
  for (auto i : arr)
    std::cout << i << ' ';
  std::cout << std::endl;

  bubbleSort(arr, GreaterAdapter(greater));
  for (auto i : arr)
    std::cout << i << ' ';
  std::cout << std::endl;

  bubbleSort(arr, KeyFuncLessAdapter(key_func));
  for (auto i : arr)
    std::cout << i << ' ';
  std::cout << std::endl;

  bubbleSort(arr, KeyFuncLessAdapter([](int value) -> double
                                     { return abs(value) % 2; }));
  for (auto i : arr)
    std::cout << i << ' ';
}