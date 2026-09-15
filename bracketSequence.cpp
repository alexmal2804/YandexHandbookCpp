#include <iostream>
#include <string>
#include <string_view>
int main()
{
  std::string bracketSeq;
  std::cin >> bracketSeq;
  if (bracketSeq[0] == '}' || bracketSeq[0] == ')' || bracketSeq[0] == ']')
  {
    std::cout << "NO" << "\n";
    return 0;
  }
  for (size_t i = 0; i != bracketSeq.size(); ++i)
  {
    std::string_view bracketInterval;
    switch (bracketSeq[i])
    {
    case '{':
      bracketInterval = bracketSeq.substr(i, bracketSeq.find('}'));
      break;
    case '(':
      bracketInterval = bracketSeq.substr(i, bracketSeq.find(')'));
      break;
    case '[':
      bracketInterval = bracketSeq.substr(i, bracketSeq.find(']'));
      break;
    default:
      std::cout << "NO" << "\n";
      return 0;
    }
    if (bracketInterval.size() == 2)
    {
      continue;
    }
    for (char bracket : bracketInterval)
    {
      switch (bracket)
      {
      case '{':
        if (bracketInterval.find('}') > 0)
        {
          break;
        }
        else
        {
          std::cout << "NO" << "\n";
          return 0;
        };
      case '(':
        if (bracketInterval.find(')') > 0)
        {
          break;
        }
        else
        {
          std::cout << "NO" << "\n";
          return 0;
        };
      case '[':
        if (bracketInterval.find(']') > 0)
        {
          break;
        }
        else
        {
          std::cout << "NO" << "\n";
          return 0;
        };
      default:
        break;
      }
    }
  }
  std::cout << "YES" << "\n";
  return 0;
}
