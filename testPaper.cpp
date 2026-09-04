#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_set>

struct Test
{
  std::string family;
  std::string place;
};

std::list<Test> StackOfPapers(const size_t n, std::vector<Test> testsString)
{
  std::list<Test> testPlaces;
  for (size_t i = 0; i != n; ++i)
  {
    Test test = {testsString[i].family, testsString[i].place};
    if (test.place == "top")
    {
      testPlaces.push_front(test);
    }
    else
    {
      testPlaces.push_back(test);
    }
  }
  return testPlaces;
}

std::vector<std::string> findStudents(std::vector<size_t> numbers, std::list<Test> testPlaces)
{
  std::vector<std::string> familyStack;
  for (size_t num : numbers)
  {
    std::list<Test>::iterator iter = testPlaces.begin();
    for (size_t i = 1; i < num; i++)
    {
      if (iter != testPlaces.end())
      {
        ++iter;
      }
    }
    familyStack.push_back(iter->family);
  }
  return familyStack;
}
std::vector<Test> createStack(const size_t n)
{
  const size_t minLen = 2;
  const size_t maxLen = 10;
  const std::unordered_set<std::string> allowed = {"top", "bottom"};
  std::vector<Test> testPlaces;

  for (size_t i = 0; i < n; i++)
  {
    while (true)
    {
      std::string paper, place;
      std::cin >> paper >> place;
      if (paper.size() >= minLen && paper.size() <= maxLen && allowed.count(place))
      {
        testPlaces.push_back({paper, place});
        break;
      }
      std::cerr << "Ошибочный ввод\n";
    }
  }
  return testPlaces;
}
int main()
{
  size_t n, m;
  std::vector<Test> testPlacesStrVector;
  std::list<Test> testPlacesList;
  std::vector<size_t> numPapers;
  std::vector<std::string> familyStrVector;
  while (true)
  {
    std::cin >> n;
    if (n <= 10000)
    {
      break;
    }
    std::cerr << "n должно быть меньше 10000";
  }
  testPlacesStrVector = createStack(n);
  while (true)
  {
    std::cin >> m;
    if (m <= 10000)
    {
      break;
    }
    std::cerr << "m должно быть меньше 10000";
  }
  for (size_t i = 0; i < m; i++)
  {
    size_t np;
    std::cin >> np;
    numPapers.push_back(np);
  }
  testPlacesList = StackOfPapers(n, testPlacesStrVector);
  familyStrVector = findStudents(numPapers, testPlacesList);
  for (std::string family : familyStrVector)
  {
    std::cout << family << std::endl;
  }
  return 0;
}
