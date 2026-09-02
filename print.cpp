#include <iostream>

int main()
{
  unsigned int year = 0;
  while (year <= 0)
  {
    std::cin >> year;
  }
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}