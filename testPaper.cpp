#include <iostream>
#include <vector>
#include <deque>
#include <string>
std::vector<std::string> Split(const std::string &str, char delimiter)
{
  std::vector<std::string> resVector;
  if (str.empty())
  {
    return {""};
  }
  size_t posBeginWord = 0;
  size_t posEndWord = str.find(delimiter, posBeginWord);
  if (posEndWord == std::string::npos)
  {
    posEndWord = str.size();
  }
  resVector.push_back(str.substr(posBeginWord, posEndWord - posBeginWord));
  while (posEndWord != str.size())
  {
    posBeginWord = posEndWord + 1;
    posEndWord = str.find(delimiter, posBeginWord) == std::string::npos ? str.size() : str.find(delimiter, posBeginWord);
    resVector.push_back(str.substr(posBeginWord, posEndWord - posBeginWord));
  }
  return resVector;
}
enum class Place
{
  top = 0,
  bottom = 1
};
struct Test
{
  std::string family;
  Place place;
};

std::deque<Test> StackOfPapers(size_t n, std::vector<std::string> testsString)
{
  std::deque<Test> testPlaces;
  for (size_t i = 0; i != n; ++i)
  {
    Test test = { Split(testsString[i], ' ')[0],
                  Split(testsString[i], ' ')[1] == "top" ? Place::top : Place::bottom };
    if (test.place == Place::top ){
      testPlaces.push_front(test);
    } else {
      testPlaces.push_back(test);
    }             
  }
}

int main()
{
  return 0;
}
