#include <iostream>
#include <locale>
#include <algorithm>
#include <cctype>

/*
Дана строка из строчных латинских букв и пробелов. Проверьте, является ли она палиндромом без учета пробелов.
Формат ввода
На вход подается одна строка. В строке могут быть пробелы. Подряд может идти произвольное число пробелов. Длина строки не превосходит 100.
Формат вывода
Представьте, что из строки удалили все пробелы. Необходимо вывести YES, если полученная строка — палиндром, и NO в противном случае.
Пример 1
Ввод
hello world
Вывод
NO
Пример 2
Ввод
never odd or even
Вывод
YES
*/

std::string to_lower_copy(const std::string &src)
{
  // std::locale loc;
  std::string res = src;
  std::transform(res.begin(), res.end(), res.begin(),
                 [](unsigned char c)
                 { return std::tolower(c); });
  return res;
}
void remove_all_whitespace(std::string &s)
{
  s.erase(
      std::remove_if(s.begin(), s.end(),
                     [](unsigned char c)
                     { return std::isspace(c); }),
      s.end());
}

bool isPalindrome(const std::string &candidate)
{
  bool res = true;
  std::size_t len = candidate.size();
  for (std::size_t i = 0; i != len / 2; ++i)
  {
    if (candidate[i] != candidate[len - i - 1])
    {

      res = false;
    }
  }
  return res;
}
int main()
{
  std::string word;
  if (!(std::getline(std::cin, word)))
  {
    return 1;
  }
  word = to_lower_copy(word);
  // std::cout << word << std::endl;
  remove_all_whitespace(word);
  // std::cout << word << std::endl;
  if (isPalindrome(word))
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
  return 0;
}