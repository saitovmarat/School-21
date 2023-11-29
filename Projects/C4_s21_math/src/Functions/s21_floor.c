#include "../s21_math.h"

long double s21_floorl(long double x) {
  if (x == +0) return +0;
  if (x == -0) return -0;
  if (S21_IS_NAN(x)) return S21_NAN;
  if (x == S21_INF_POS) return S21_INF_POS;
  if (x == S21_INF_NEG) return S21_INF_NEG;
  long double intNum = (long long int)x;
  if (x >= 0)
    return intNum;
  else
    return (s21_fabs(x - intNum) == 0) ? intNum : intNum - 1;
}

long double s21_floor(double x) { return s21_floorl(x); }