#include "../s21_math.h"

long double s21_ceill(long double x) {
  if (x == +0) return +0;
  if (x == -0) return -0;
  if (x == S21_INF_POS) return S21_INF_POS;
  if (x == S21_INF_NEG) return S21_INF_NEG;
  long double intNum = (long long int)x;
  if (x >= 0)
    return (s21_fabs(x - intNum) == 0) ? intNum : intNum + 1;
  else
    return intNum;
}

long double s21_ceil(double x) { return s21_ceill(x); }