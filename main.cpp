#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

int main()
{
  std::vector<int> vec;
  size_t n;
  std::cin >> n;
  for (size_t i = 0; i != n; ++i ){
    vec.push_back(rand());
    std::cout << vec[i];
    if (i != n - 1){
      std::cout << ", ";
    }
  }
  std::cout << "\n";
  return 0;
}
