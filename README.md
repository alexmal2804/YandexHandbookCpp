# Решения задач из хэндбука по C++

Учебный репозиторий с решениями и черновиками задач из хэндбука Яндекса по C++. Здесь собраны небольшие консольные программы для практики базового синтаксиса языка, условий, циклов, строк, контейнеров и стандартной библиотеки.

Исходные условия: [задачи хэндбука в Яндекс Контесте](https://new.contest.yandex.ru/contests/42155/problems).

Каждый файл в каталоге [`YandexHandbookCpp`](./YandexHandbookCpp) — самостоятельная программа со своей функцией `main`. Файлы нужно собирать и запускать по отдельности.

## Содержание

| Файл | Тема | Состояние |
| --- | --- | --- |
| [`Calendar.cpp`](./YandexHandbookCpp/Calendar.cpp) | Вывод календаря месяца | Реализация |
| [`daysPerMonth.cpp`](./YandexHandbookCpp/daysPerMonth.cpp) | Количество дней в месяце | Реализация |
| [`digitalSum.cpp`](./YandexHandbookCpp/digitalSum.cpp) | Сумма цифр числа | Реализация |
| [`horse.cpp`](./YandexHandbookCpp/horse.cpp) | Проверка взаимного положения клеток на шахматной доске | Реализация |
| [`leapYear.cpp`](./YandexHandbookCpp/leapYear.cpp) | Определение високосного года | Реализация |
| [`naturalLog.cpp`](./YandexHandbookCpp/naturalLog.cpp) | Приближение значения `ln(2)` | Реализация |
| [`password.cpp`](./YandexHandbookCpp/password.cpp) | Проверка сложности пароля | Реализация |
| [`permutation.cpp`](./YandexHandbookCpp/permutation.cpp) | Построение обратной перестановки | Черновик |
| [`rightTriangle.cpp`](./YandexHandbookCpp/rightTriangle.cpp) | Проверка прямоугольного треугольника | Реализация |
| [`soundex.cpp`](./YandexHandbookCpp/soundex.cpp) | Кодирование слова алгоритмом Soundex | Реализация |
| [`typeSize.cpp`](./YandexHandbookCpp/typeSize.cpp) | Размеры, границы и переполнение числовых типов | Эксперимент |

Файл [`main.cpp`](./YandexHandbookCpp/main.cpp) оставлен как пустая заготовка для новых упражнений.

## Требования

- компилятор с поддержкой C++17, например GCC, Clang или MSVC;
- терминал либо IDE с поддержкой сборки C++.

Проект настроен для работы с GCC из MSYS2 в VS Code, но исходники не зависят от конкретной IDE.

## Сборка и запуск

Перейдите в каталог с решениями:

```powershell
cd YandexHandbookCpp
```

Соберите нужную задачу. Например, для проверки високосного года:

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic leapYear.cpp -o leapYear
```

Запустите программу в PowerShell:

```powershell
.\leapYear.exe
```

В Linux и macOS команда запуска будет такой:

```bash
./leapYear
```

После запуска введите данные в формате, указанном в условии соответствующей задачи. Например:

```text
2024
```

Результат:

```text
YES
```

В VS Code можно открыть нужный `.cpp`-файл и запустить задачу сборки `C/C++: g++.exe build active file` сочетанием <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd>.

## Структура репозитория

```text
.
├── README.md
└── YandexHandbookCpp/
    ├── .gitignore
    ├── Calendar.cpp
    ├── daysPerMonth.cpp
    ├── ...
    └── typeSize.cpp
```

Решения предназначены для обучения и могут дорабатываться по мере прохождения хэндбука.
