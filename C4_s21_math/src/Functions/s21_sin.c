#include "../s21_math.h"

long double s21_sin(double x) {
  x = s21_fmod(x, S21_2PI);
  long double step = x;
  long double result = step;
  for (int n = 1; n < 500 && s21_fabs(step) > 1e-06; n++) {
    step *= -(x * x) / ((2 * n) * (2 * n + 1));
    result += step;
  }
  return result;
}