#include <iostream>
#include <deque>
#include <string>
void MakeTrain()
{
  std::deque<int> train;
  std::string direction;
  int numWagon;
  while (std::cin >> direction >> numWagon)
  {
    if (direction == "+left")
    {
      train.push_front(numWagon);
    }
    else if (direction == "+right")
    {
      train.push_back(numWagon);
    }
    else if (direction == "-left")
    {
      if (static_cast<size_t>(numWagon) >= train.size())
      {
        train = {};
        continue;
      }
      for (size_t i = 0; i != static_cast<size_t>(numWagon); ++i)
      {
        train.pop_front();
      }
    }
    else if (direction == "-right")
    {
      if (static_cast<size_t>(numWagon) >= train.size())
      {
        train = {};
        continue;
      }
      for (size_t i = 0; i != static_cast<size_t>(numWagon); ++i)
      {
        train.pop_back();
      }
    }
  }
  for (size_t i = 0; i != train.size(); ++i)
  {
    if (i != 0)
    {
      std::cout << " ";
    }
    std::cout << train[i];
  }
  std::cout << std::endl;
}
int main()
{
  MakeTrain();
  return 0;
}
