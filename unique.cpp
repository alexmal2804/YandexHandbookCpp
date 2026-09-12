#include <iostream>
#include <vector>
#include <algorithm>
template <typename Iter>
Iter Unique(Iter first, Iter last)
{
  return;
}
int main()
{
  std::vector<int> v = {5, 5, 3, 2, 2, 5, 9, 2};
  auto it = Unique(v.begin(), v.end());
  for (size_t i = 0; i != v.size(); ++i)
  {
    if (i != 0)
    {
      std::cout << " ";
    }
    std::cout << v[i];
  }
  std::cout << "\n";
  return 0;
}
