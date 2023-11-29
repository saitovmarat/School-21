#include "../s21_math.h"

long double s21_cos(double x) {
  if (x == +0 || x == -0) return 1;
  if (S21_IS_INF(x)) return S21_NAN;

  long double num = s21_fmod(x, S21_2PI);
  long double result = 1;
  long double numerator = 1;    //числитель
  long double denominator = 1;  //знаменатель
  long double sign = 1;         //знак
  long double rowMember;        //член ряда

  for (int i = 1; i < 500; i++) {
    sign *= -1;
    numerator *= num * num;
    denominator *= (2 * i) * (2 * i - 1);
    rowMember = sign * (numerator / denominator);
    result += rowMember;
  }
  return result;
}