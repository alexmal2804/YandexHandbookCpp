#include <iostream>

int main()
{
  std::string bracketSeq;
  std::cin >> bracketSeq;
  if (bracketSeq[0] == '}' || bracketSeq[0] == ')' || bracketSeq[0] == ']'){
    std::cout << "NO" << "\n";
    return 0;
  }
  bool isBracketOrder = false;
  for (size_t i = 0; i != bracketSeq.size(); ++i){
    
  }
  return 0;
}
