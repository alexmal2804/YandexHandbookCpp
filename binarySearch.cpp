#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/*
В этой задаче нужно применить функцию std::lower_bound и
итераторы для быстрого поиска ближайшего элемента в отсортированном массиве.
Формат ввода
В первой строке входных данных содержатся натуральные числа n и k, не превосходящие
100000. Во второй строке задаются n целых чисел первого массива,
отсортированного по неубыванию, а в третьей строке – k целых чисел второго массива.
Каждое число в обоих массивах по модулю не превосходит 2⋅10^9.
Второй массив, в отличие от первого, не отсортирован.
Формат вывода: Для каждого из k чисел выведите в отдельной строке число из первого массива, наиболее близкое к данному. Если таких несколько, выведите меньшее из них.
Пример 1
Ввод
5 5
1 3 5 7 9
2 4 8 1 6
Вывод
1
3
7
1
5
*/
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  size_t n, k;
  std::vector<int> sortedArray;
  std::cin >> n >> k;
  sortedArray.reserve(n);
  for (size_t i = 0; i != n; ++i)
  {
    int elem;
    std::cin >> elem;
    sortedArray.push_back(elem);
  }
  for (size_t j = 0; j != k; ++j)
  {
    int element;
    std::cin >> element;
    auto iter = std::lower_bound(sortedArray.begin(), sortedArray.end(), element);
    auto prevIter = iter;
    if (iter == sortedArray.begin())
    {
      std::cout << *iter << "\n";
      continue;
    }
    if (iter == sortedArray.end())
    {
      --iter;
      std::cout << *iter << "\n";
      continue;
    }
    --prevIter;
    auto resIter = std::abs(static_cast<long long>(*prevIter) - element) >
                           std::abs(static_cast<long long>(*iter) - element)
                       ? iter
                       : prevIter;
    std::cout << *resIter << "\n";
  }

  return 0;
}
