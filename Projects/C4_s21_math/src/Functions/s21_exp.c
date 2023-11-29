#include "../s21_math.h"
long double s21_exp(double x) {
  long double result = 1.0;
  double term = 1.0;

  for (int n = 1; n < 500; n++) {
    term *= x / n;
    result += term;
  }

  return result;
}