#include <iostream>

#include <vector>

template <typename T>
void Duplicate(std::vector<T> &v)
{
  for (auto it = v.begin(); it != v.end() - 1; ++it)
  {
    if (it != v.end())
    {
      v.push_back(*it);
    }
  }
}

int main()
{
  std::vector<int> v1 = {1, 2, 3};
  Duplicate(v1);
  for (const auto &v : v1)
  {
    std::cout << v << " ";
  }
  std::cout << "\n";
  return 0;
}
