#include <iostream>
#include <vector>
#include <string>
/*
Вам надо написать функцию Print, которая умеет печатать в поток
std::cout элементы переданного контейнера через указанную строку-разделитель.
Первый аргумент функции — контейнер. Гарантируется, что по этому контейнеру
можно проитерироваться с помощью стандартного цикла range-based for,
и что элементы контейнера можно напечатать в поток std::cout с помощью
стандартного оператора <<. Второй аргумент функции — строка-разделитель,
которую надо печатать между элементами. В конце необходимо напечатать перевод
строки \n.
*/
template <typename T>
void Print(const T &container, std::string delimiter)
{
  auto iter = container.begin();
  for (auto element : container)
  {
    std::cout << element;
     ++iter;
    if(iter != container.begin() && iter != container.end()) {
      std::cout << delimiter;
    }
   
  }
  std::cout << std::endl;
}
int main()
{
  std::vector<int> data = {1, 2, 3, 4};
  Print(data, ", ");
  return 0;
}
