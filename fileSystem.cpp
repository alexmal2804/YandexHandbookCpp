#include <iostream>
#include <vector>
#include <set>
/*
Дан список всех файлов в некоторой файловой системе. Необходимо вывести все непустые директории этой файловой
системы в лексикографическом порядке.
Гарантируется, что все пути начинаются от корня файловой системы. Все пути состоят из слешей (/),
латинских символов, цифр и точек. Два слеша никогда не стоят подряд.
Формат ввода
На вход подаются строки, описывающие пути ко всем файлам в системе.
Каждый путь содержится в отдельной строке. Число строк не превосходит 10000.
Формат вывода
Выведите все непустые директории в этой файловой системе в лексикографическом порядке.
Каждый путь должен начинаться со слеша и заканчиваться слешом.
Пример 1
Ввод
/docs/README.txt
/docs/LICENSE.txt
/boot/grub
/init
Вывод
/
/boot/
/docs/
*/
std::vector<std::string> SplitDir(const std::string &str, char delimiter)
{
  std::vector<std::string> resVector;
  if (str.empty())
  {
    return {""};
  }
  const size_t posBeginWord = 0;
  size_t posEndWord = str.rfind(delimiter);
  if (posEndWord == std::string::npos)
  {
    return {""};
  }
  resVector.push_back(std::string(1, delimiter));
  while (posEndWord != std::string::npos)
  {
    resVector.push_back(str.substr(posBeginWord, posEndWord + 1));
    if (posEndWord == 0) {
      break;
    }
    posEndWord = str.rfind(delimiter, posEndWord - 1);
  }
  return resVector;
}

int main()
{
  std::string path;
  std::set<std::string> directories;
  char delimiter = '/';
  size_t i = 0;
  while (std::cin >> path && i < 10000)
  {
    std::vector<std::string> directoriesVector = SplitDir(path, delimiter);
    size_t dirsLen = directoriesVector.size();
    for (size_t i = 0; i < dirsLen - 1; i++)
    {
      directories.insert(directoriesVector[i]);
    }
  }
  // std::string slesh = std::string(1, delimiter);
  // directories.insert(slesh);
  for (std::string dir : directories)
  {
    std::cout << dir << "\n";
  }
  return 0;
}
