#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> freqs;
  std::string word;
  while (std::cin >> word)
  {
    ++freqs[word];
  }
  for (const auto &[word, freq] : freqs)
  {
    std::cout << word << "\t" << freq << "\n";
  }
}
