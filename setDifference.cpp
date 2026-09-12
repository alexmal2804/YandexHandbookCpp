#include <iostream>
#include <vector>
#include <algorithm>
template <typename Iter>
Iter Unique(Iter first, Iter last)
{
  if (first == last)
  {
    return last;
  }
  auto reader = first;
  ++reader;
  while (reader != last)
  {
    if (!(*first == *reader))
    {
      ++first;
      *first = *reader;
    }
    ++reader;
  }
  return ++first;
}
int main()
{
  std::vector<int> v = {5, 5, 3, 2, 2, 5, 9, 2, 5, 3, 3, 2};
  auto it = Unique(v.begin(), v.end());
  v.erase(it, v.end());
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
