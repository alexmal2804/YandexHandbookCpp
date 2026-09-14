#include <iostream>
#include <vector>
#include <algorithm>
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
  size_t n, k;
  std::vector<int> sortedArray;
  std::vector<int> findArray;
  std::cin >> n >> k;
  if (n ==  0 || k == 0) {
    std::cout << "Исходный массив пустой";
    return 0;
  }
  for (size_t i = 0; i != n; ++i){
    int elem;
    std::cin >> elem;
    sortedArray.push_back(elem);
    }
  for (size_t j = 0; j != k; ++j){
    int elem;
    std::cin >> elem;
    findArray.push_back(elem);
  }
  for (const auto &element : findArray){
    auto iter = std::upper_bound(sortedArray.begin(), sortedArray.end(), element);
    if (iter == sortedArray.begin()) {
      std::cout << *iter;
    } else {prevIter = iter}
    if (iter == sortedArray.end()) {

    }
  }

  return 0;
}
