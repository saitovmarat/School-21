#include "../s21_math.h"
/**
 * @brief Gets the principal value of the arc sine of x.
 * @param x Input value.
 * @return principal value of the arc sine of x.
 * @retval long double
 */
long double s21_asin(double x) {
  if (x == +0) return +0;
  if (x == -0) return -0;
  if (x == 1) return S21_PI2;
  if (x == -1) return -S21_PI2;
  if (s21_fabs(x) > 1) return S21_NAN;
  long double num = (long double)x;
  long double result = S21_NAN;
  if (-1 <= num && num <= 1)
    result = s21_atan(num / s21_sqrt(1 - s21_pow(num, 2)));
  return result;
}
