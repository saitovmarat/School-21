#include "../s21_math.h"
/**
 * @brief Gets the principal value of the arc tangent of x.
 * @param x Input value.
 * @return principal value of the arc tangent of x.
 * @retval long double
 */
long double s21_atan(double x) {
  if (x == 1) return S21_PI4;
  if (x == +0) return +0;
  if (x == -0) return -0;
  if (x == S21_INF_POS) return +S21_PI2;
  if (x == S21_INF_NEG) return -S21_PI2;
  long double num = (long double)x;
  long double result = 0.0;
  if (num > 1)
    result = S21_PI2 - s21_atan(1.0 / num);
  else if (num < -1)
    result = -S21_PI2 - s21_atan(1.0 / num);
  else {
    for (int n = 1; n < 500; n++) {
      result +=
          s21_pow(-1, n - 1) * (s21_pow(num, 2.0 * n - 1.0) / (2.0 * n - 1.0));
    }
  }
  return result;
}
