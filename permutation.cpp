#include <iostream>
#include <vector>

int main()
{
  std::size_t n;
  std::cin >> n;
  std::vector<std::size_t> guests(n);
  std::vector<std::size_t> seats(n);
  for (std::size_t i = 0; i != n; ++i)
  {
    std::cin >> guests[i];
  }
  for (std::size_t i = 0; i != n; ++i)
  {
    for (std::size_t j = 0; j != n; ++j)
      if (i + 1 == guests[j])
      {
        seats[i] = j + 1;
        break;
      }
  }
  for (std::size_t i = 0; i != n; ++i)
  {
    if (i > 0)
    {
      std::cout << ' ';
    }
    std::cout << seats[i];
  }
  std::cout << std::endl;
  return 0;
}