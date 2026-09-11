#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <cctype>
bool isAllLowercase(const std::string &s)
{
  if (s.empty())
  {
    return false;
  }
  return std::all_of(s.begin(), s.end(), [](unsigned char c)
                     { return std::islower(c); });
}

std::string commonLetters(const std::string &a, std::string &b)
{
  std::unordered_set<char> setA(a.begin(), a.end());
  std::string result;

  for (char c : b)
  {
    if (setA.count(c))
    {
      result.push_back(c);
      setA.erase(c);
    }
  }
  std::sort(result.begin(), result.end());
  return result;
}
int main()
{
  std::string word;
  std::string letters;
  bool isBegin = true;
  size_t i = 0;
  while (std::cin >> word && i < 1000)
  {
    if (word.size() > 100 || !isAllLowercase(word))
    {
      continue;
    }
    if (isBegin)
    {
      letters = commonLetters(word, word);
      isBegin = false;
      continue;
    }
    letters = commonLetters(letters, word);
    ++i;
  }
  std::cout << letters << "\n";
  return 0;
}
