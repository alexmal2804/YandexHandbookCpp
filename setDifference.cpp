#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1,
                      InIter2 first2, InIter2 last2,
                      OutIter out)
{
  while (first1 < last1)
    if (*first1 < *first2)
    {
      *out = *first1;
      ++out;
      ++first1;
    }
    else if (*first1 > *first2)
    {
      ++first2;
    }
    else if (*first1 == *first2)
    {
      ++first1;
      ++first2;
    }
    else
    {
      *out = *first1;
      ++out;
      ++first1;
    }
  return out;
};
int main()
{
  std::vector<int> v1 = {1, 3, 5, 5, 7};
  std::vector<int> v2 = {1, 1, 2, 3};
  std::list<int> v;
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());
  auto it = SetDifference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v));
  const char *separator = "";
  for (const auto &element : v)
  {
    std::cout << separator << element;
    separator = " ";
  }
  std::cout << "\n";
  return 0;
}
