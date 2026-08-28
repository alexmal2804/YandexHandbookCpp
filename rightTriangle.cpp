#include <iostream>

int main()
{
  int a = 0;
  int b = 0;
  int c = 0;

  while (a == 0 || b == 0 || c == 0)
  {
    std::cin >> a >> b >> c;
  }
  if (a + b <= c || c + b <= a || c + a <= b)
  {
    std::cout << "UNDEFINED" << std::endl;
    return 0;
  }
  if (a * a + b * b == c * c || c * c + b * b == a * a || c * c + a * a == b * b)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }
  return 0;
}