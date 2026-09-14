#include <iostream>
#include <algorithm>
#include <vector>
/*
Андрею надо написать шаблонную функцию Process, которая обрабатывает вектор
с числами некоторого типа T. Его функция должна вызвать другую функцию
 PrintResults, чтобы напечатать с определенным форматированием положительные
  числа из вектора. Функция PrintResults принимает на вход пару итераторов,
  как и многие алгоритмы стандартной библиотеки. Поэтому Андрей решил сначала
   скопировать нужные элементы исходного вектора в другой массив, чтобы передать
    его начало и конец в эту функцию. Вот код Андрея:

Этот код почему-то не работает. Найдите ошибку и сдайте исправленное решение.
*/
template <typename T>
void Process(const std::vector<T> &data)
{
  std::vector<T> filtered;

  auto filteredLast = std::copy_if(
      data.begin(),
      data.end(),
      filtered.begin(),
      [](const T &x)
      { return x > 0; });

  PrintResults(filtered.begin(), filteredLast);
}

template <typename T>
void PrintResults(T beginIt, T endIt){
  while (beginIt !== endIt){
    std::cout << *beginIt << "\n";
    ++beginIt;
  }
}
int main()
{
  std::vector<int> v = {12, -7, 4, 22, -17, 8};
  Process(v);
  return 0;
}
