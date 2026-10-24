#include <cstddef>
#include <map>
#include <string>
#include <vector>
#include <iostream>

/*Вася пишет новую структуру данных — дерево. В узлах и листьях дерева хранятся
 * строковые ключи. Каждый путь от корня до какого-нибудь узла можно записать,
 * перечисляя последовательные ключи узлов. Типичный пример — иерархия папок в
 * файловой системе. Вася уже выбрал способ хранения дерева (см. ниже).
 Не будем обсуждать, насколько это эффективно.
  Ваша задача — написать реализации функций Has, Insert и Delete для этого класса.
  В примере с папками в файловой системе функция Has должна проверить, существует
  ли такая папка, функция Insert должна создать папку (возможно, с промежуточными
  родительскими папками), а Delete — удалить папку со всеми вложенными подпапками,
  если такая папка существует.
Можно считать, что вектор, передаваемый на вход этих функций, всегда непустой.
 */

struct Node {
  std::map<std::string, Node> children;
};

class Tree {
private:
  Node root;

public:
  bool Has(const std::vector<std::string> &node) const;
  void Insert(const std::vector<std::string> &node);
  void Delete(const std::vector<std::string> &node);
  Node GetNode() const { return root;}
};

// Ваш код будет вставлен сюда
bool Tree::Has(const std::vector<std::string> &node) const {
  const Node* current = &root;
  for(const std::string&n : node){
    auto it = current->children.find(n);
    if (it == current->children.end()){
      return false;
    }
    current = &it -> second;
  }
  return true;
};

void Tree::Insert(const std::vector<std::string> &node) {
  Node* current = &root;
  for (const std::string& n : node) {
    current = &current->children[n];
  }
};

void Tree::Delete(const std::vector<std::string> &node) {
  Node* current =&root;
  for (std::size_t i=0; i+1 < node.size(); ++i){
   auto it = current->children.find(node[i]);
   if (it == current->children.end()){
    return;
   }
   current = &it->second;
  }
  current->children.erase(node.back());
};

int main(){
  Tree t;
  t.Insert({"home", "alex", "docs"});
  for (const  auto& [k, n] : t.GetNode().children){
    std::cout << k << "\n";
  }
  return 1;
}