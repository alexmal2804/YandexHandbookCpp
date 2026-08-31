#include <iostream>
#include <vector>
/*
Дана прямоугольная матрица
A  из  m строк и n столбцов.
Напишите функцию, которая возвращает транспонированную матрицу.
Примечание
Гарантируется, что вектор matrix непуст и все его элементы имеют равную ненулевую длину.
Подключите необходимые заголовочные файлы и напишите только код функции Transpose. Мы скомпилируем решение с нашей функцией main.
 */
std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> &matrix)
{
}
int main()
{
  size_t n;
  size_t m;
  std::cin >> n;
  std::cin >> m;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  std::vector<std::vector<int>> transposeMatrix(m, std::vector<int>(n));
  for (size_t i = 0; i != n; ++i)
  {
    for (size_t j = 0; j != m; ++j)
    {
      std::cin >> matrix[i][j];
    }
  }
  transposeMatrix = Transpose(matrix);
  return 0;
}
