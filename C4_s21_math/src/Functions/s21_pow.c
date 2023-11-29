#include "../s21_math.h"

long double s21_pow(double base1, double exp1) {
  if (S21_IS_NAN(base1) || S21_IS_NAN(exp1)) return S21_NAN;
  long double base = (long double)base1;
  long double exp = (long double)exp1;
  long double result = 1.0;
  if (exp > 0) {
    long double intPart = s21_floor(exp);
    for (int i = 0; i < intPart; i++) result *= base;

    if (exp - intPart != 0) {
      long double fractPart = exp - intPart;
      result *= s21_exp(fractPart * s21_log(base));
    }
  } else if (exp < 0) {
    long double intPart = s21_floor(exp);
    for (int i = 0; i < intPart; i++) result /= base;

    if (exp - intPart != 0) {
      long double fractPart = exp - intPart;
      result /= s21_exp(fractPart * s21_log(base));
    }
  }
  return result;
}
