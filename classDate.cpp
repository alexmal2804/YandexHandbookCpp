#include <iostream>
/* Вам надо написать класс Date для хранения даты григорианского календаря.
Используйте три переменных типа int для хранения дня, месяца и года. В вашем
классе должен быть следующий публичный интерфейс: Конструктор, принимающий на
вход три числа: день, месяц и год. В случае некорректной даты должна создаваться
дата 1 января 1970 года. Константные функции GetDay, GetMonth и GetYear.
Бинарные операторы + и -, где вторым аргументом является целое число —
количество дней. Эти операторы должны вернуть новую дату, отстоящую от заданной
на указанное число дней. Бинарный оператор -, вычисляющий разность между двумя
датами и возвращающий int – количество дней. Считайте, что все обрабатываемые
даты будут лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.*/

class Date {
private:
  int day{1};
  int month{1};
  int year{1970};
  static bool IsLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  }
  static int leapYears(int y) { return y / 4 - y / 100 + y / 400; }

public:
  Date(int, int, int);
  Date operator+(int days) const;
  int GetDay() const { return day; }
  int GetMonth() const { return month; }
  int GetYear() const { return year; }
};

Date::Date(int d, int m, int y) {
  bool isCorrectDate = true;
  if (m < 1 || m > 12) {
    isCorrectDate = false;
  }
  switch (m) {
  case 4:
  case 6:
  case 9:
  case 11:
    if (d < 1 || d > 30) {
      isCorrectDate = false;
    }
    break;
  case 2:
    if (IsLeapYear(y)) {
      if (d < 1 || d > 29) {
        isCorrectDate = false;
      } else {
        if (d < 1 || d > 28) {
          isCorrectDate = false;
        }
      }
      break;
    }
  default:
    if (d < 1 || d > 31) {
      isCorrectDate = false;
    }
  }
  if (y < 1970 || y > 2099) {
    isCorrectDate = false;
  }
  if (isCorrectDate == true) {
    day = d;
    month = m;
    year = y;
  } else {
    day = 1;
    month = 1;
    year = 1970;
  }
}

Date Date::operator+(int days) const {
  int leap = leapYears(year - 1) - leapYears(1969);
  int daysBetweenYears = 365 * (year - 1970) + leap;
  // Количество дней перед началом каждого месяца
  // в обычном году: январь — 0, февраль — 31 и т. д.
  const int daysBeforeMonth[12] = {0,   31,  59,  90,  120, 151,
                                   181, 212, 243, 273, 304, 334};

  // Номер исходного дня относительно 1 января 1970 года.
  // У самого 1 января номер равен 0.
  long long totalDays = daysBetweenYears + daysBeforeMonth[month - 1] + day - 1;
  // Если февраль високосного года уже прошёл,
  // учитываем его дополнительный день.
  if (IsLeapYear(year) && month > 2) {
    ++totalDays;
  }
  totalDays += days;
  // Меняем начало отсчёта:
  // вместо 1 января 1970 года используем 1 марта условного года 0.
  // Между этими датами 719468 дней.
  long long marchDays = totalDays + 719468;

  // Каждые 400 лет григорианский календарь повторяется.
  // В таком цикле: 400 * 365 + 97 = 146097 дней.
  int cycle = static_cast<int>(marchDays / 146097);

  // Номер дня внутри найденного 400-летнего цикла: 0..146096.
  int dayOfCycle = static_cast<int>(marchDays % 146097);

  // Номер мартовского года внутри цикла: 0..399.
  // Поправки учитывают високосные годы и исключения для столетий.
  int yearOfCycle = (dayOfCycle - dayOfCycle / 1460 + dayOfCycle / 36524 -
                     dayOfCycle / 146096) /
                    365;

  int newYear = cycle * 400 + yearOfCycle;
  // Вычитаем дни полных мартовских лет внутри цикла.
  // Получаем номер дня текущего мартовского года: 0..365.
  int dayOfYear =
      dayOfCycle - (365 * yearOfCycle + yearOfCycle / 4 - yearOfCycle / 100);
  // Мартовский номер месяца:
  // март — 0, апрель — 1, ..., январь — 10, февраль — 11.
  int marchMonth = (5 * dayOfYear + 2) / 153;

  // Вычитаем дни перед началом найденного месяца.
  // Прибавляем 1, чтобы дни месяца начинались с 1.
  int newDay = dayOfYear - (153 * marchMonth + 2) / 5 + 1;

  // Переводим мартовскую нумерацию месяцев в обычную.
  int newMonth = marchMonth + (marchMonth < 10 ? 3 : -9);

  // Январь и февраль относятся к следующему календарному году.
  if (newMonth <= 2) {
    ++newYear;
  }

  //  return Date(newDay, newMonth, newYear);
}

int main() { return 0; }
