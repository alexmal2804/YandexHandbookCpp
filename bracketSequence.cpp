#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <stack>
/*
Принцип:
Встретили открывающую скобку — положили её в стек.
Встретили закрывающую: 
если стек пуст — последовательность неправильная;
проверили, соответствует ли она последней открывающей скобке;
если не соответствует — последовательность неправильная;
если соответствует — удалили открывающую скобку из стека.
После обработки всей строки стек должен быть пуст.
Почему проверяется именно последняя открывающая скобка? 
Потому что пары должны быть вложены: последняя открытая пара обязана закрыться 
первой. Например, для:
{([])}
состояние стека меняется так:
Символ	Стек после обработки
{	{
(	{(
[	{([
]	{(
)	{
}	пусто
А для ([)] при встрече ) наверху стека находится [, 
поэтому сразу определяется ошибка.
*/
int main()
{
  std::string bracketSeq;
  std::stack<char> bracketStack;
  std::cin >> bracketSeq;
  const std::string_view openBracket = {"({["};
  const std::string_view closedBracket = {")}]"};
  bool isCorrect = true;
  for(const char symbol : bracketSeq){
    if (openBracket.find(symbol) != std::string_view::npos){
      bracketStack.push(symbol);
    }
    if (size_t num = closedBracket.find(symbol); num != std::string_view::npos) {
      if (bracketStack.empty() || closedBracket[num] != bracketStack.top()){
        isCorrect = false;
        break;
      } 
    bracketStack.pop();
    }
  }
  if (bracketStack.empty()) {
    isCorrect = false;
  }
  if (isCorrect) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  std::cout << "\n";
 }
