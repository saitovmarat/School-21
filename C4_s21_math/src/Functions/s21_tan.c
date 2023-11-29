#include "../s21_math.h"

long double s21_tan(double x) {
  if (x == +0) return +0;
  if (x == -0) return -0;
  if (S21_IS_INF(x)) return S21_NAN;
  long double result = s21_sin(x) / s21_cos(x);
  return result;
}