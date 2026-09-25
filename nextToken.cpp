#include <cstddef>
#include <iostream>
#include <string_view>
/*
Вам надо написать функцию NextToken для выделения очередного токена в строке.
Токеном считается последовательность символов до указанного символа-разделителя
(или до конца строки). Сдайте только код функции NextToken и подключите
необходимые библиотеки. Ваша функция будет скомпилирована с нашей функцией main.
Гарантируется, что входная строка не заканчивается на разделитель.
Догадайтесь сами, какие аргументы должна принимать функция NextToken.
Эта функция может менять первый аргумент (sv).
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

int main() {
  std::string_view sv = "Hello world and good bye";

  const char delimiter = ' ';
  std::string_view token;

  // Делим строку на токены по разделителю и перебираем эти токены:
  while (NextToken(sv, delimiter, token)) {
    // обрабатываем очередной token
    // например, печатаем его на экране:
    std::cout << token << "\n";
  }
  return 0;
}
