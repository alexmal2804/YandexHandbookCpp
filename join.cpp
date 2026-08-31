#include <iostream>
#include <vector>
#include <string>
/*
/*
Функция должна вернуть строку, полученную склейкой элементов вектора через указанный разделитель. Например, Join({"What", "is", "your", "name?"}, '_') должна вернуть строку "What_is_your_name?".
Примечание
Если вектор tokens пустой, то функция должна вернуть пустую строку. Если в векторе tokens ровно один элемент, то он и должен вернуться в ответе.
Подключите необходимые заголовочные файлы и напишите только код функции Join. Мы скомпилируем решение с нашей функцией main.
*/
std::string Join(const std::vector<std::string> &tokens, char delimiter)
{
  std::string resStr = "";
  if (tokens.empty())
  {
    return resStr;
  }
  size_t len = tokens.size();
  if (len == 1)
  {
    return tokens[0];
  }
  for (size_t i = 0; i != len; ++i)
  {
    if (i < len - 1)
    {
      resStr += tokens[i] + delimiter;
    }
    else
    {
      resStr += tokens[i];
    }
  }
  return resStr;
}
int main()
{
  std::vector<std::string> words;
  std::string result;
  std::string word;
  while (std::getline(std::cin, word))
  {
    words.push_back(word);
  }
  result = Join(words, '_');
  std::cout << result << std::endl;
  return 0;
}
