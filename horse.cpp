#include <iostream>

int main()
{
  int a1 = 0;
  int a2 = 0;
  int b1 = 0;
  int b2 = 0;

  while (a1 < 1 || a1 > 8 || a2 < 1 || a2 > 8 || b1 < 1 || b1 > 8 || b2 < 1 || b2 > 8)
  {
    std::cin >> a1 >> a2 >> b1 >> b2;
  }
  if (std::abs(b1 - a1) == std::abs(b2 - a2) || b1 == a1 || a2 == b2)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
}
