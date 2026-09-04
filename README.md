# Решения задач из хэндбука по C++

Учебный репозиторий с решениями задач и небольшими экспериментами по C++. Программы охватывают базовый синтаксис, условия, циклы, строки, контейнеры, алгоритмы и числовые типы.

Условия части задач: [хэндбук Яндекса в Яндекс Контесте](https://new.contest.yandex.ru/contests/42155/problems).

Каждый `.cpp`-файл в корне репозитория — отдельная консольная программа со своей функцией `main`. Файлы следует собирать и запускать по одному. [`main.cpp`](./main.cpp) оставлен как пустая заготовка для новых упражнений.

## Содержание

| Файл | Что делает программа |
| --- | --- |
| [`Calendar.cpp`](./Calendar.cpp) | Печатает календарь по номеру первого дня недели и количеству дней в месяце |
| [`daysPerMonth.cpp`](./daysPerMonth.cpp) | Определяет количество дней в указанном месяце с учётом високосного года |
| [`decreasingSort.cpp`](./decreasingSort.cpp) | Сортирует строки по убыванию с помощью `std::sort` |
| [`decreasingSortHandMade.cpp`](./decreasingSortHandMade.cpp) | Сортирует строки по убыванию без `std::sort` |
| [`digitalSum.cpp`](./digitalSum.cpp) | Вычисляет сумму цифр целого числа |
| [`horse.cpp`](./horse.cpp) | Проверяет, находятся ли две клетки на одной строке, в одном столбце или на одной диагонали |
| [`join.cpp`](./join.cpp) | Объединяет строки из вектора, вставляя между ними заданный символ-разделитель |
| [`leapYear.cpp`](./leapYear.cpp) | Определяет, является ли год високосным |
| [`matrixMaximum.cpp`](./matrixMaximum.cpp) | Создаёт случайную матрицу и выводит координаты её первого максимального элемента |
| [`minesweeper.cpp`](./minesweeper.cpp) | Строит поле для игры «Сапёр» по заданным координатам мин |
| [`naturalLog.cpp`](./naturalLog.cpp) | Приближает `ln(2)` первыми `n` членами знакочередующегося гармонического ряда |
| [`palindrom.cpp`](./palindrom.cpp) | Проверяет строку на палиндром без учёта регистра и пробельных символов |
| [`password.cpp`](./password.cpp) | Проверяет длину, допустимые символы и сложность пароля |
| [`permutation.cpp`](./permutation.cpp) | Строит обратную перестановку |
| [`pringContainer.cpp`](./pringContainer.cpp) | Печатает элементы произвольного контейнера через заданный строковый разделитель |
| [`print.cpp`](./print.cpp) | Определяет, является ли введённый год високосным |
| [`rightTriangle.cpp`](./rightTriangle.cpp) | Проверяет существование треугольника и является ли он прямоугольным |
| [`sharedPrefix.cpp`](./sharedPrefix.cpp) | Находит наибольший общий префикс набора строк |
| [`sortPoints.cpp`](./sortPoints.cpp) | Сортирует точки по возрастанию расстояния до начала координат |
| [`soundex.cpp`](./soundex.cpp) | Кодирует английское слово четырёхсимвольным кодом Soundex |
| [`split.cpp`](./split.cpp) | Разбивает строку на части по заданному символу-разделителю |
| [`testPaper.cpp`](./testPaper.cpp) | Формирует стопку контрольных работ и находит работы на указанных позициях |
| [`trainDriver.cpp`](./trainDriver.cpp) | Моделирует добавление и удаление вагонов с обоих концов состава |
| [`transponMatrix.cpp`](./transponMatrix.cpp) | Транспонирует целочисленную матрицу |
| [`typeSize.cpp`](./typeSize.cpp) | Показывает границы и размеры числовых типов, а также примеры переполнения |

## Требования

- компилятор с поддержкой C++17: GCC, Clang или MSVC;
- терминал или IDE для сборки и запуска программ.

C++17 необходим, в частности, для структурированного связывания в `matrixMaximum.cpp`. Конфигурация VS Code использует GCC и GDB из MSYS2 UCRT64.

## Сборка и запуск

Находясь в каталоге репозитория, соберите нужный исходный файл. Например:

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic leapYear.cpp -o leapYear.exe
```

Запуск в PowerShell:

```powershell
.\leapYear.exe
```

Пример ввода:

```text
2024
```

Результат:

```text
YES
```

Для оптимизированной сборки добавьте `-O2` — это заглавная латинская буква `O`, а не цифра `0`:

```powershell
g++ -std=c++17 -O2 -Wall -Wextra -Wpedantic matrixMaximum.cpp -o matrixMaximum.exe
.\matrixMaximum.exe
```

В Linux и macOS расширение `.exe` обычно не используется:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -Wpedantic leapYear.cpp -o leapYear
./leapYear
```

### Измерение времени выполнения

В PowerShell время выполнения программы можно измерить с помощью `Measure-Command`:

```powershell
Measure-Command { .\matrixMaximum.exe }
```

Только время в миллисекундах:

```powershell
(Measure-Command { .\matrixMaximum.exe }).TotalMilliseconds
```

Если программа ожидает ввод, в результат войдёт и время, затраченное на его ввод.

### Работа в VS Code

Откройте нужный `.cpp`-файл и используйте одну из команд:

- <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> — собрать активный файл;
- <kbd>Ctrl</kbd>+<kbd>F5</kbd> — собрать и запустить без отладки;
- <kbd>F5</kbd> — собрать и запустить с отладчиком.

Сборка настроена в режиме C++17 с предупреждениями `-Wall -Wextra -Wpedantic` и кодировкой UTF-8 для исходного кода и исполняемой программы. Программа запускается во встроенном терминале VS Code, поэтому входные данные можно вводить там же.

## Структура репозитория

```text
.
├── .vscode/                    # настройки сборки, запуска и отладки
├── .gitignore
├── README.md
├── Calendar.cpp
├── daysPerMonth.cpp
├── decreasingSort.cpp
├── decreasingSortHandMade.cpp
├── digitalSum.cpp
├── horse.cpp
├── join.cpp
├── leapYear.cpp
├── main.cpp                    # заготовка для новых упражнений
├── matrixMaximum.cpp
├── minesweeper.cpp
├── naturalLog.cpp
├── palindrom.cpp
├── password.cpp
├── permutation.cpp
├── pringContainer.cpp
├── print.cpp
├── rightTriangle.cpp
├── sharedPrefix.cpp
├── sortPoints.cpp
├── soundex.cpp
├── split.cpp
├── testPaper.cpp
├── trainDriver.cpp
├── transponMatrix.cpp
└── typeSize.cpp
```

Скомпилированные программы, объектные файлы и каталоги сборки исключены из Git с помощью `.gitignore`.
