#include <iostream>
#include <vector>
/*
Известный алгоритм Soundex определяет, похожи ли два английских слова по звучанию. На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.
Вам требуется реализовать этот алгоритм. Он работает так:
Первая буква слова сохраняется.
В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
b, f, p, v: 1
c, g, j, k, q, s, x, z: 2
d, t: 3
l: 4
m, n: 5
r: 6
Любая последовательность идущих подряд одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки получилась меньше четырёх символов, в конце добавляются нули.
Примеры:
ammonium → ammnm → a5555 → a5 → a500.
implementation → implmnttn → i51455335 → i514535 → i514.
Формат ввода
На вход подаётся одно непустое слово из строчных латинских букв. Длина слова не превосходит 20 символов.
Формат вывода
Напечатайте четырёхбуквенный код, соответствующий слову.
*/
int main()
{
  std::string word;
  std::string goal = "";
  std::vector<std::string> dict = {
      "bfpv",
      "cgjkqsxz",
      "dt",
      "l",
      "mn",
      "r"};
  std::string delSymbols = "aehiouwy";
  while (word.size() < 1 || word.size() > 20)
  {
    std::cin >> word;
  }
  goal += word[0];
  word.erase(0, 1);
  for (char symbol : delSymbols)
  {
    std::size_t pos = word.find(symbol);
    while (pos != std::string::npos)
    {
      word.erase(pos, 1);
      pos = word.find(symbol, pos);
    }
  }
  goal += word;
  std::size_t posCount = 1;
  for (std::string dictString : dict)
  {
    for (char symbol : dictString)
    {
      std::size_t pos = goal.find(symbol, 1);
      while (pos != std::string::npos)
      {
        goal.replace(pos, 1, std::to_string(posCount));
        pos = goal.find(symbol, pos + 1);
      }
    }
    ++posCount;
  }
  std::size_t posDigital = 1;
  while (posDigital < goal.size())
  {
    while (posDigital + 1 < goal.size() && goal[posDigital] == goal[posDigital + 1]  )
    {
      goal.erase(posDigital + 1, 1);
    }
    ++posDigital;
  }
  if (goal.size() > 4) {
    goal.resize(4);
  }
  while (goal.size() < 4)
  {
     goal += "0";
  }
  std::cout << goal << std::endl;
  return 0;
}