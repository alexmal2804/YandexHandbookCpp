#include <iostream>
#include <list>
#include <string>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  // Читаем файл до пустой строки — она разделитель, в файл не входит
  std::list<std::string> text;
  std::string line;
  while (std::getline(std::cin, line))
  {
    if (line.empty())
      break;
    text.push_back(line);
  }

  auto cursor = text.begin();

  std::list<std::string> buffer;

  bool shiftPressed = false;
  int shiftOffset = 0;
  auto shift = text.begin();

  std::string command;
  while (std::cin >> command)
  {
    if (command == "Up")
    {
      if (cursor == text.begin())
        continue;
      --cursor;
      if (!shiftPressed)
      {
        shift = cursor;
      }
      else
      {
        --shiftOffset;
      }
    }
    else if (command == "Down")
    {
      if (cursor == text.end())
        continue;
      ++cursor;
      if (!shiftPressed)
      {
        shift = cursor;
      }
      else
      {
        ++shiftOffset;
      }
    }
    else if (command == "Shift")
    {
      shiftPressed = true;
    }
    else if (command == "Ctrl+X")
    {
      // Нет выделения и курсор в конце — игнорируем
      if (shift == cursor && cursor == text.end())
        continue;

      buffer.clear();

      if (shift == cursor)
      {
        // Без выделения — вырезаем текущую строку
        auto toSplice = cursor;
        cursor = std::next(cursor);
        buffer.splice(buffer.begin(), text, toSplice);
      }
      else if (shiftOffset < 0)
      {
        // Курсор выше shift — диапазон [cursor, shift)
        buffer.splice(buffer.begin(), text, cursor, shift);
        cursor = shift;
      }
      else
      {
        // Курсор ниже shift — диапазон [shift, cursor)
        buffer.splice(buffer.begin(), text, shift, cursor);
      }

      shiftPressed = false;
      shift = cursor;
      shiftOffset = 0;
    }
    else if (command == "Ctrl+V")
    {
      if (buffer.empty())
        continue;

      // Стираем выделение, если оно есть
      if (shiftOffset < 0)
      {
        cursor = text.erase(cursor, shift);
      }
      else if (shiftOffset > 0)
      {
        cursor = text.erase(shift, cursor);
      }

      // Вставляем буфер перед курсором (копированием, не перемещением)
      text.insert(cursor, buffer.begin(), buffer.end());

      shiftPressed = false;
      shift = cursor;
      shiftOffset = 0;
    }
  }

  for (const auto &x : text)
  {
    std::cout << x << "\n";
  }

  return 0;
}
