#include "../s21_math.h"

long double s21_log(double x) {
  if (x == S21_INF_POS) return x;
  if (x == 0) return S21_INF_NEG;
  if (x < 0) return S21_NAN;

  long double res = 0.0L;
  long double first = (x - 1) / (x + 1);
  long double first_squar = first * first;
  long double numerator = first;
  long double denominator = 1.0L;
  long double roof = 1e-100L;
  for (int n = 1; s21_fabs(numerator / denominator) > roof; n += 2) {
    res += numerator / denominator;
    numerator *= first_squar;
    denominator += 2.0L;
  }
  res *= 2.0L;

  return res;
}