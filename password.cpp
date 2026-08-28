#include <iostream>
#include <cctype>
/*
Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
состоять из символов таблицы ASCII с кодами от 33 до 126;
быть не короче 8 символов и не длиннее 14;
из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие символы — в пароле должны присутствовать не менее трёх любых.
Напишите программу, которая проверит, что введённый пароль подходит под эти ограничения.
*/
int main()
{
  std::string password;
  std::cin >> password;
  bool isCorrect = false;
  bool isDigital = false;
  bool isUpper = false;
  bool isLower = false;
  bool isOther = false;
  for (char character : password)
  {
    if (character < 33 || character > 126)
    {
      isCorrect = false;
      std::cout << "NO" << std::endl;
      return 0;
    }
    if (password.size() < 8 || password.size() > 14)
    {
      isCorrect = false;
      std::cout << "NO" << std::endl;
      return 0;
    }
    if (character > 47 && character < 58)
    {
      isDigital = true;
    }
    else if (character > 64 && character < 91)
    {
      isUpper = true;
    }
    else if (character > 96 && character < 123)
    {
      isLower = true;
    }
    else
    {
      isOther = true;
    }
  }
  if (isDigital + isLower + isUpper + isOther > 2)
  {
    isCorrect = true;
  }
  else
  {
    isCorrect = false;
  }
  if (isCorrect)
  {
    std::cout << "YES" << std::endl;
    return 0;
  }
  else
  {
    std::cout << "NO" << std::endl;
    return 0;
  }
  return 0;
}