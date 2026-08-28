#include <iostream>
#include <vector>
#include <random>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>> &matrix)
{
  size_t n = matrix.size();
  size_t k = matrix[0].size();
  int max = matrix[0][0];
  int i_max = 0;
  int j_max = 0;
  for (size_t i = 0; i != n; ++i)
  {
    for (size_t j = 0; j != k; ++j)
    {
      if (matrix[i][j] > max)
      {
        max = matrix[i][j];
        i_max = i;
        j_max = j;
      }
    }
  }
  std::pair<size_t, size_t> p = {i_max, j_max};
  return p;
}
int main()
{
  size_t n;
  size_t k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(k));
  std::mt19937 rng(std::random_device{}());
  int min = 1;
  int max = 1000;
  std::uniform_int_distribution<int> dist(min, max);
  for (size_t i = 0; i != n; ++i)
  {
    for (size_t j = 0; j != k; ++j)
    {
      matrix[i][j] = dist(rng);
    }
  }
  for (size_t i = 0; i != n; ++i)
  {
    for (size_t j = 0; j != k; ++j)
    {
      if (j != 0)
      {
        std::cout << " ";
      }
      std::cout << matrix[i][j];
    }
    std::cout << std::endl;
  }
  auto [x_max, y_max] = MatrixArgMax(matrix);
  std::cout << x_max << " " << y_max << std::endl;
  return 0;
}
