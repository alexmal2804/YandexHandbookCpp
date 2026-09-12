#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
/*
Будем называть символьной n-граммой последовательность из
n последовательно идущих символов в одном слове в тексте. Для данного числа
n подсчитайте суммарное количество каждой n-граммы в тексте.
Формат ввода
В первой строке заданы два числа: m — число слов в тексте (от 1 до 100000) и n — длина
n-граммы (от 1 до 5). Далее идет
m слов. Можно считать, что слова отделены пробелами или переносами строк. Обработку пунктуации и регистра реализовывать не нужно. Читайте слова просто через std::cin >> word.
Формат вывода
Выведите все n-граммы, отсортированные по убыванию частоты, а в случае равных
частот — лексикографически (по алфавиту). Для каждой n-граммы напечатайте также
её частоту (смотрите формат в примере).
Пример
Ввод
6 2
to be or not to be
Вывод
be - 2
to - 2
no - 1
or - 1
ot - 1
*/
int main()
{
  std::map<std::string, size_t> ngram;
  std::vector<std::pair<std::string, size_t>> ngramFreq;
  size_t m, n;
  std::cin >> m >> n;
  for (size_t i = 0; i < m; i++)
  {
    std::string word;
    std::cin >> word;
    size_t lastPos;
    size_t len = word.size();
    if (len < n)
    {
      continue;
    }
    lastPos = len - n;
    for (size_t i = 0; i <= lastPos; ++i)
    {
      std::string ng = word.substr(i, n);
      ngram[ng] += 1;
    }
  }

  for (const auto &[key, value] : ngram)
  {
    ngramFreq.push_back({key, value});
  }
  std::sort(
      ngramFreq.begin(),
      ngramFreq.end(),
      [](const auto &p1, const auto &p2)
      { return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first); });

  for (const auto &[ng, freg] : ngramFreq)
  {
    std::cout << ng << " - " << freg << "\n";
  }
  return 0;
}
