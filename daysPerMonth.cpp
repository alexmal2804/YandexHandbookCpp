#include <iostream>

bool IsLeapYear(int year)
{
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
  {
    return true;
  }
  else
  {
    return false;
  }
  return false;
}

int main()
{
  unsigned int year = 0;
  unsigned int month = 0;
  while (year <= 0 || month <= 0)
  {
    std::cin >> month >> year;
  }
  switch (month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      std::cout << "31" << std::endl;
      break;
    case 2:
      if (IsLeapYear(year)) {
        std::cout << "29" << std::endl;
      }else {
        std::cout << "28" << std::endl;
      }
      break;
    default:
        std::cout << "30" << std::endl;
  } 
  return 0;
}