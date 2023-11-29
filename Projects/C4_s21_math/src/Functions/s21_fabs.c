#include "../s21_math.h"

/**
 * @brief Get absolute value of x.
 *
 * @param x Input value.
 * @return Absolute value of x.
 * @retval long double
 */
long double s21_fabs(double x) {
  if (x == +0 || x == -0) return 0;
  if (x == S21_INF_POS) return S21_INF_POS;
  if (x == S21_INF_NEG) return S21_INF_NEG;
  long double num = (long double)x;
  return (num < 0) ? -num : num;
}