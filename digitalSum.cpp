#include <iostream>

int main()
{
  long long num;
  int sum = 0;
  std::cin >> num;
  while (num > 0)
  {
    sum += num % 10; /* code */
    num /= 10;
  }
  sum += num;
  std::cout << sum << std::endl;
  return 0;
}