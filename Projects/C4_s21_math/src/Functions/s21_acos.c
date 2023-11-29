#include "../s21_math.h"
/**
 * @brief Gets the principal value of the arc cosine of x.
 * @param x Input value.
 * @return principal value of the arc cosine of x.
 * @retval long double
 */
long double s21_acos(double x) {
  if (x == 0) return S21_PI2;
  if (x == -1) return S21_PI;
  if (x == 1) return +0;
  if (s21_fabs(x) > 1) return S21_NAN;
  long double num = (long double)x;
  long double result = S21_NAN;
  if (num > 0)
    result = s21_atan(s21_sqrt(1.0 - s21_pow(x, 2)) / num);
  else if (num < 0)
    result = S21_PI + s21_atan(s21_sqrt(1.0 - s21_pow(x, 2)) / num);
  return result;
}
