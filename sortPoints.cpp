#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
  int x;
  int y;
};

// Функция для вычисления квадрата расстояния до начала координат.
// Используем квадрат, чтобы избежать потери точности и лишней работы с sqrt.
long long distSq(const Point &p)
{
  return 1LL * p.x * p.x + 1LL * p.y * p.y;
}

int main()
{
  // Оптимизация скорости ввода/вывода (хорошая практика для олимпиадных задач)
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  if (!(std::cin >> n))
    return 0;

  std::vector<Point> points(n);

  // Читаем n пар координат. cin автоматически пропускает пробелы и переносы строк.
  for (int i = 0; i < n; ++i)
  {
    std::cin >> points[i].x >> points[i].y;
  }

  // Сортируем точки по возрастанию расстояния до (0,0)
  std::sort(points.begin(), points.end(), [](const Point &a, const Point &b)
            { return distSq(a) < distSq(b); });

  // Выводим результат: "x y" и перевод строки после каждой пары
  for (const auto &p : points)
  {
    std::cout << p.x << " " << p.y << "\n";
  }

  return 0;
}
