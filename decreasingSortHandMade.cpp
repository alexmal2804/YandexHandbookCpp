#include <iostream>
#include <vector>

/*
Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.
Формат ввода
Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII с кодами от 32 до 126, длина строки не превосходит 100.
Формат вывода
Напечатайте строки в отсортированном по убыванию порядке. Для сравнения строк друг с другом достаточно использовать стандартные операторы сравнения, определённые для std::string.
Пример
Ввод
one
two
three
Вывод
two
three
one
*/
int main()
{
  std::vector<std::string> stringVector;
  std::string currentString;
  while (std::getline(std::cin, currentString))
  {
    stringVector.push_back(currentString);
  }
  for (std::size_t i = 0; i != stringVector.size(); ++i)
  {
    for (std::size_t j = i + 1; j != stringVector.size(); ++j)
    {
      if (stringVector[i] < stringVector[j])
      {
        std::string swap = stringVector[i];
        stringVector[i] = stringVector[j];
        stringVector[j] = swap;
      }
    }
  }
  for (std::size_t i = 0; i != stringVector.size(); ++i)
  {
    std::cout << stringVector[i] << std::endl;
  }
  return 0;
}