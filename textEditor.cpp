#include <iostream>
#include <list>
#include <vector>
#include <string>

int main()
{
  std::list<std::string> text;
  std::vector<std::string> commands;
  std::string buffer;
  std::string currentString;
  std::list<std::string>::iterator textPosition;
  bool isText = true;
  while (std::getline(std::cin, currentString))
  {
    if (currentString.empty() && isText)
    {
      text.push_back(currentString);
      isText = false;
      continue;
    }
    if (isText)
    {
      text.push_back(currentString);
    }
    else
    {
      commands.push_back(currentString);
    }
  }
  textPosition = text.begin();
  for (std::string currentCommand : commands)
  {
    if (currentCommand == "Down")
    {
      if (std::next(textPosition) != text.end())
      {
        ++textPosition;
      }
    }
    else if (currentCommand == "Up")
    {
      if (textPosition != text.begin())
      {
        --textPosition;
      }
    }
    else if (currentCommand == "Ctrl+X")
    {

      if (!textPosition->empty())
      {
        buffer = *textPosition;
        textPosition = text.erase(textPosition);
      }
    }
    else if (currentCommand == "Ctrl+V")
    {
      if (!buffer.empty())
      {
        text.insert(textPosition, buffer);
      }
    }
  }
  for (const std::string &line : text)
  {
    std::cout << line << std::endl;
  }
  return 0;
}
