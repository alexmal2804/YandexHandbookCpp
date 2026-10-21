#include <iostream>
/*Вам надо переделать реализацию класса Date из предыдущей задачи, сохранив
публичный интерфейс неизменным. Теперь для хранения даты используйте одну
переменную типа int — количество дней, прошедших с некоторого начала отсчёта.
Считайте, что все обрабатываемые даты будут лежать в пределах от
1 января 1970 года до 31 декабря 2099 года.*/

class Date {
private:
  int date{0};
  struct DateParts {
    int day;
    int month;
    int year;
  };
  static bool IsLeapYear(int year) {
    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
  }
  static int leapYears(int y) { return y / 4 - y / 100 + y / 400; }
  static DateParts IntToDate(int d);
  static int DaysInDate(int, int, int);

public:
  Date(int, int, int);
  Date operator+(int days) const;
  Date operator-(int days) const;
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
  int operator-(const Date &other) const;
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
      }
    } else {
      if (d < 1 || d > 28) {
        isCorrectDate = false;
      }
    }
    break;
  default:
    if (d < 1 || d > 31) {
      isCorrectDate = false;
    }
  }
  if (y < 1970 || y > 2099) {
    isCorrectDate = false;
  }
  if (isCorrectDate) {
    date = DaysInDate(d, m, y);
  }
}

Date::DateParts Date::IntToDate(int d) {
  int day = 1;
  int month = 1;
  int year = 1970;
  if (d < 0) {
    return {day, month, year};
  }
  // Меняем начало отсчета на 1 марта 1968
  d = d + 671;
  const int b = d / 1461;
  const int r = d % 1461;
  const int k = r / 365 < 3 ? r / 365 : 3;
  const int t = r - 365 * k;
  year = 1968 + 4 * b + k;
  month = (5 * t + 2) / 153;
  const int p = (153 * month + 2) / 5;
  day = t - p + 1;
  if (month < 10) {
    month += 3;
  } else {
    month -= 9;
    ++year;
  }
  return {day, month, year};
}

int Date::GetDay() const { return IntToDate(date).day; }

int Date::GetMonth() const { return IntToDate(date).month; }

int Date::GetYear() const { return IntToDate(date).year; }

Date Date::operator+(int days) const {
  Date result = *this;
  result.date += days;
  return result;
}

Date Date::operator-(int days) const { return *this + (-days); }

int Date::DaysInDate(int day, int month, int year) {
  int leap = leapYears(year - 1) - leapYears(1969);
  int daysBetweenYears = 365 * (year - 1970) + leap;
  // Количество дней перед началом каждого месяца
  // в обычном году: январь — 0, февраль — 31 и т. д.
  const int daysBeforeMonth[12] = {0,   31,  59,  90,  120, 151,
                                   181, 212, 243, 273, 304, 334};

  // Номер исходного дня относительно 1 января 1970 года.
  // У самого 1 января номер равен 0.
  int totalDays = daysBetweenYears + daysBeforeMonth[month - 1] + day - 1;
  // Если февраль високосного года уже прошёл,
  // учитываем его дополнительный день.
  if (IsLeapYear(year) && month > 2) {
    ++totalDays;
  }
  return totalDays;
}

int Date::operator-(const Date &days) const { return date - days.date; }

int main() {
  Date date{28, 4, 1972};

  Date newDate = date + 10000;

  std::cout << newDate.GetDay() << " " << newDate.GetMonth() << " "
            << newDate.GetYear() << "\n";

  std::cout << Date(28, 4, 1973) - date << "\n";

  return 0;
}
