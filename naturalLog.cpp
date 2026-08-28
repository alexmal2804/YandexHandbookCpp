#include <iostream>

int main()
{
  int n;
  double ln2 = 0.0;
  double sign = 1.0;
  std::cin >> n;
  for (int i = 1; i <= n; i++)
  {
    //std::cout << numi <<std::endl;
    ln2 += sign / i;
    sign = -sign;
  }
  std::cout << ln2 << std::endl;
  return 0;
}