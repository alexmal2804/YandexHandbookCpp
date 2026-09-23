#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
/*
Напишите программу, которая будет обрабатывать последовательность запросов таких
видов: CLEAR — сделать очередь с приоритетами пустой (если в очереди уже были
какие-то элементы, то удалить все). ADD n — добавить в очередь с приоритетами
число n (вмещается в стандартный тип int). EXTRACT — вынуть из очереди с
приоритетами максимальное значение. Следует изменить данные в памяти и вывести
на экран найденное максимальное значение, или, если очередь была пустой, слово
CANNOT. Формат ввода Во входных данных записана произвольная последовательность
запросов CLEAR, ADD и EXTRACT — каждый в отдельной строке. Суммарное количество
всех запросов не превышает 200000. Формат вывода Для каждого запроса типа
EXTRACT выведите его результат в отдельной строке. Пример Ввод ADD 192168812 ADD
125 ADD 321 EXTRACT EXTRACT CLEAR ADD 7 ADD 555 EXTRACT EXTRACT EXTRACT Вывод
192168812
321
555
7
CANNOT
*/
int main() {
  std::priority_queue<int> pr_queue;
  std::string com, param;
  int maxElement;
  bool firstElement = true;
  while (std::cin >> com) {
    if (com == "ADD") {
      std::cin >> param;
      pr_queue.push(std::stoi(param));
      continue;
    }
    if (com == "CLEAR") {
      pr_queue = {};
      continue;
    }
    if (com == "EXTRACT") {
      if (firstElement) {
        std::cout << "\n";
        firstElement = false;
      }
      if (pr_queue.empty()) {
        std::cout << "CANNOT" << "\n";
        continue;
      }
      maxElement = pr_queue.top();
      pr_queue.pop();
      std::cout << maxElement << "\n";
    }
  }
  return 0;
}