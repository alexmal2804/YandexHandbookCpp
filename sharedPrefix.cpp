#include <iostream>
#include <vector>
#include <string>
/*
Напишите функцию для вычисления наибольшего общего префикса строк, переданных в векторе words:
std::string CommonPrefix(const std::vector<std::string>& words);
Например, для пустого вектора функция должна вернуть пустую строку, а для вектора из строк "apple",
 "apricot" и "application" — строку "ap".
Примечание
В решении не должно быть функции main: она будет в нашей тестирующей программе. Подключите
необходимые библиотеки и напишите код функции CommonPrefix.
*/
std::string CommonPrefix(const std::vector<std::string> &words)
{
  if (words.empty() || words[0].empty())
  {
    return "";
  }
  std::string strPref = words[0].substr(0, 1);
  bool compareOk = true;
  size_t pos = 1;
  while (compareOk)
  {
    for (size_t j = 1; j != words.size(); ++j)
    {
      if (words[j].find(strPref) != 0)
      {
        compareOk = false;
        break;
      }
    }
    if (compareOk)
    { 
      if (pos < words[0].size()) {
        strPref += words[0][pos];
        ++pos;
      } else {
        break;
      }
    }
  }
  if (!compareOk) {
    return strPref.substr(0, strPref.size() - 1);
  } 
  return strPref;
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
  result = CommonPrefix(words);
  std::cout << result << std::endl;
  return 0;
}
