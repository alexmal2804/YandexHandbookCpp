#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T> &v)
{
  std::vector<T> tmp = v;
  std::copy(tmp.begin(), tmp.end(), back_inserter(v));
}

int main()
{
  std::vector<int> v1 = {1, 2, 3};
  Duplicate(v1);
  for (const auto v : v1)
  {
    std::cout << v << " ";
  }
  std::cout << "\n";
  return 0;
}
