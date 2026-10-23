#include <cassert>
#include <iostream>
#include <numeric>
/*
Напишите класс Rational (рациональное число). Конструктор класса должен получать
на вход два числа типа int (числитель и знаменатель). Считайте, что по умолчанию
числитель равен 0, а знаменатель — 1. Переопределите бинарные операторы
сложения, вычитания, умножения и деления (работающие в том числе и с аргументами
типа int), унарные плюс и минус. Предусмотрите функции-члены Numerator и
Denominator для получения числителя и знаменателя несократимого представления
этой дроби (знаменатель должен быть положительным). Переопределите также
операторы +=, -=, *= и /=. Не забудьте определить операторы == и !=. Примечание
Используйте функцию std::gcd стандартной библиотеки.
*/

int failures = 0;

#define CHECK(cond)                                                            \
  do {                                                                         \
    if (!(cond)) {                                                             \
      std::cerr << "FAIL " << __FILE__ << ":" << __LINE__ << "  " #cond        \
                << "\n";                                                       \
      ++failures;                                                              \
    }                                                                          \
  } while (false)

class Rational {
private:
  int numerator;
  int denominator;

public:
  Rational(int n = 0, int d = 1);
  int Numerator() const { return numerator; }
  int Denominator() const { return denominator; }
  Rational operator+(Rational r) const;
  Rational operator-(Rational r) const;
  Rational operator*(Rational r) const;
  Rational operator/(Rational r) const;
  Rational &operator+=(Rational r);
  Rational &operator-=(Rational r);
  Rational &operator*=(Rational r);
  Rational &operator/=(Rational r);
  bool operator==(Rational r) const;
  bool operator!=(Rational r) const;
  Rational operator-() const;
  Rational operator+() const;
};

Rational::Rational(int n, int d) : numerator(n), denominator(d) {
  assert(d != 0 && "Rational: zero denominator");
  const int g = std::gcd(n, d);
  numerator /= g;
  denominator /= g;
  if (denominator < 0) {
    denominator = -denominator;
    numerator = -numerator;
  }
}

Rational Rational::operator+(Rational r) const {
  const int g = std::gcd(denominator, r.denominator);
  int n = numerator * (r.denominator / g) + r.numerator * (denominator / g);
  int d = denominator * (r.denominator / g);
  return Rational(n, d);
}

Rational Rational::operator-(Rational r) const { return *this + (-r); }

Rational Rational::operator*(Rational r) const {
  const int g1 = std::gcd(numerator, r.denominator);
  const int g2 = std::gcd(r.numerator, denominator);
  const int n1 = numerator / g1;
  const int d2 = r.denominator / g1;
  const int n2 = r.numerator / g2;
  const int d1 = denominator / g2;
  return Rational(n1 * n2, d1 * d2);
}

Rational Rational::operator/(Rational r) const {
  assert(r.numerator != 0 && "Rational: division by zero");
  const int g1 = std::gcd(numerator, r.numerator);
  const int g2 = std::gcd(denominator, r.denominator);
  const int n1 = numerator / g1;
  const int n2 = r.numerator / g1;
  const int d1 = denominator / g2;
  const int d2 = r.denominator / g2;
  return Rational(n1 * d2, n2 * d1);
}

Rational Rational::operator-() const {
  return Rational(-numerator, denominator);
}

Rational Rational::operator+() const { return *this; }

Rational &Rational::operator+=(Rational r) {
  *this = *this + r;
  return *this;
}

Rational &Rational::operator-=(Rational r) {
  *this = *this - r;
  return *this;
}

Rational &Rational::operator*=(Rational r) {
  *this = *this * r;
  return *this;
}

Rational &Rational::operator/=(Rational r) {
  *this = *this / r;
  return *this;
}

bool Rational::operator==(Rational r) const {
  return (numerator == r.numerator) && (denominator == r.denominator);
}

bool Rational::operator!=(Rational r) const { return !(*this == r); }

Rational operator+(int lhs, Rational rhs) { return Rational(lhs) + rhs; }
Rational operator-(int lhs, Rational rhs) { return Rational(lhs) - rhs; }
Rational operator*(int lhs, Rational rhs) { return Rational(lhs) * rhs; }
Rational operator/(int lhs, Rational rhs) { return Rational(lhs) / rhs; }

int main() {
    // int + Rational
  CHECK(2 + Rational(1, 2) == Rational(5, 2));
  CHECK(-2 + Rational(1, 2) == Rational(-3, 2));
  CHECK(0 + Rational(-1, 3) == Rational(-1, 3));
  CHECK(3 + Rational(-3) == Rational(0));
  CHECK(1 + Rational(1, -2) == Rational(1, 2));

  // int - Rational: важен порядок операндов.
  CHECK(2 - Rational(1, 2) == Rational(3, 2));
  CHECK(1 - Rational(3, 2) == Rational(-1, 2));
  CHECK(-2 - Rational(-1, 2) == Rational(-3, 2));
  CHECK(0 - Rational(-1, 3) == Rational(1, 3));
  CHECK(3 - Rational(3) == Rational(0));

  // int * Rational
  CHECK(2 * Rational(3, 4) == Rational(3, 2));
  CHECK(-3 * Rational(2, 9) == Rational(-2, 3));
  CHECK(-3 * Rational(-2, 9) == Rational(2, 3));
  CHECK(0 * Rational(5, 7) == Rational(0));
  CHECK(50000 * Rational(1, 50000) == Rational(1));

  // int / Rational: важен порядок операндов.
  CHECK(2 / Rational(3, 4) == Rational(8, 3));
  CHECK(-2 / Rational(3, 4) == Rational(-8, 3));
  CHECK(-2 / Rational(-3, 4) == Rational(8, 3));
  CHECK(0 / Rational(5, 7) == Rational(0));
  CHECK(6 / Rational(3, 2) == Rational(4));

  // Смешанные выражения и сохранность исходных объектов.
  const Rational p(1, 2);
  const Rational q(1, 3);

  CHECK(2 * p + q * 3 == Rational(2));
  CHECK(2 - p / q == Rational(1, 2));
  CHECK(2 / p - 3 * q == Rational(3));

  CHECK(p.Numerator() == 1 && p.Denominator() == 2);
  CHECK(q.Numerator() == 1 && q.Denominator() == 3);

  std::cout << (failures == 0 ? "all ok\n"
                              : "failures: " + std::to_string(failures) + "\n");
  return failures != 0;
}
