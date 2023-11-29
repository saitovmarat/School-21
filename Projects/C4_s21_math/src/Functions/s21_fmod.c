#include "../s21_math.h"

/**
 * @brief Gets the floating-point remainder of x/y.
 *
 * @param x Input value.
 * @param y Input value.
 * @return Floating-point remainder of x/y.
 * @retval long double
 */
long double s21_fmod(double x, double y) {
  if (x == +0 && y != 0 && !S21_IS_NAN(y)) return +0;
  if (x == -0 && y != 0 && !S21_IS_NAN(y)) return -0;
  if (S21_IS_INF(x) || y == 0) return S21_NAN;
  if (!S21_IS_INF(x) && S21_IS_INF(y)) return x;

  long double base = (long double)x;
  long double exp = (long double)y;
  long double result = base;
  long double quotient = base / exp;
  if (quotient > 0) {
    result -= exp * (s21_floorl(quotient));
  } else if (quotient < 0) {
    result -= exp * (s21_ceill(quotient));
  }
  return result;
}
