#include <iostream>
#include <vector>
#include <string>
/*
Функция должна вернуть вектор строк, полученный разбиением строки str на части по
указанному символу-разделителю delimiter. Если разделитель встретился в начале или
 в конце строки str, то в начале (соответственно, в конце) вектора с результатом
  должна быть пустая строка. Если два разделителя встретились рядом, то пустая
  строка между ними тоже должна попасть в ответ. Для пустой строки надо вернуть
  вектор, содержащий одну пустую строку.

Например, Split("What_is_your_name?", '_') должна вернуть вектор из строк What, is,
 your и name?.
*/
std::vector<std::string> Split(const std::string &str, char delimiter)
{
  
}
int main()
{
  std::string inputString;
  std::vector<std::string> resVectorByStrings;
  while (!(std::cin >> inputString))
  {
    return 1;
  }
  resVectorByStrings = Split(inputString,'_');
  for (std::string resStr : resVectorByStrings){
    std::cout << resStr << " ";
  }
  std::cout << std::endl;

  return 0;
}
