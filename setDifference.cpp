#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{

  return out;
};
int main()
{
  std::vector<int> v1 = {5, 5, 3, 2, 2, 5, 9, 2, 5, 3, 3, 2};
  std::vector<int> v2 = {5, 2, 3, 4, 2, 5, 7, 2, 5, 3, 2};
  std::list<int> v;
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());
  auto it = SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
  const char *separator = "";
  for (const auto &element : v)
  {
    std::cout << separator << element;
    separator = " ";
  }
  std::cout << "\n";
  return 0;
}
