#include <iostream>
#include <unordered_set>

int main()
{
  std::unordered_set<int> numbers;
  // std::set<std::string> isDuplicateNumber;
  int currentNumber;
  while (std::cin >> currentNumber)
  {
    auto [iter, has_been_inserted] = numbers.insert(currentNumber);
    if (has_been_inserted)
    {
      std::cout << "NO" << "\n";
    }
    else
    {
      std::cout << "YES" << "\n";
    }
  }
  return 0;
}
