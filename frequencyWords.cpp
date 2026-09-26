#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

/*
Выведите k самых частотных слов текста и их частоты.
Формат ввода. В первой строке указано натуральное число k, не превосходящее
1000. Далее идут строки текста объёмом до 1 Mб. Слова в тексте разделены
пробелами или переводами строк. Различать регистр и обрабатывать пунктуацию не
нужно. Формат вывода. В выводе должно быть не более k самых частотных слов
текста. Через табуляцию после слова напечатайте его частоту. Слова должны быть
упрядочены по убыванию частоты, а при равенстве частот — по алфавиту. Пример
Ввод
3
to be or not to be
that is the question
Вывод
be	2
to	2
is	1
*/

int main() {
  using WordFrequency = std::pair<std::size_t, std::string>;
  struct LowerPriority {
    bool operator()(const WordFrequency &lhs, const WordFrequency &rhs) const {
      if (lhs.first != rhs.first) {
        return lhs.first < rhs.first;
      }
      return lhs.second > rhs.second;
    }
  };

  std::size_t k;
  std::unordered_map<std::string, size_t> freqs;
  std::priority_queue<WordFrequency, std::vector<WordFrequency>, LowerPriority>
      queue;
  std::string word;
  std::size_t printed = 0;

  std::cin >> k;
  while (std::cin >> word) {
    ++freqs[word];
  }
  for (const auto &[word, count] : freqs) {
    queue.push({count, word});
  }
  while (!queue.empty() && printed < k) {
  const auto& [count, word] = queue.top();
  std::cout << word << '\t' << count << '\n';
  queue.pop();
  ++printed;
  }
  return 0;
}
