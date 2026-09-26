#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <queue>
/*
Выведите k самых частотных слов текста и их частоты.
Формат ввода. В первой строке указано натуральное число k, не превосходящее 1000. 
Далее идут строки текста объёмом до 1 Mб. Слова в тексте разделены пробелами или переводами строк. 
Различать регистр и обрабатывать пунктуацию не нужно.
Формат вывода. В выводе должно быть не более k самых частотных слов текста.
Через табуляцию после слова напечатайте его частоту. Слова должны быть упрядочены по убыванию частоты,
а при равенстве частот — по алфавиту.
Пример
Ввод
3
to be or not to be
that is the question
Вывод
be	2
to	2
is	1
*/
bool NextToken(std::string_view &sv, const char delimiter,
               std::string_view &token) {
  const size_t ePos = sv.find(delimiter);
  if (sv.size() == 0) {
    return false;
  }
  if (ePos == std::string_view::npos) {
    token = sv;
    sv = "";
    return true;
  }
  const size_t bPos = 0;
  token = sv.substr(bPos, ePos);
  sv = sv.substr(ePos + 1);
  return true;
}

int main()
{
  std::priority_queue<std::string> outputQueue;
  size_t k;
  std::string curString;
  while (std::getline(std::cin,curString)) {
    
  }
  return 0;
}
