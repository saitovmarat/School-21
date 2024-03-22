#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  zero_decimal(dst);
  int sign = src < 0;
  if (sign) src *= -1;
  int error = 0;
  if (isnan(src) || isinf(src)) {
    error = 1;
  } else if ((src != 0.0) &&
             (fabs((double)src) < 10e-28 || fabs((double)src) > 10e8)) {
    error = 1;
  } else if (src == 0.0) {
    zero_decimal(dst);
    char str[100];
    sprintf(str, "%f", src);
    if (str[0] == '-') s21_set_sign(dst, 1);
  } else {
    char str[100];
    sprintf(str, "%.6E", src);
    error = s21_string_to_decimal(str, dst);
    s21_set_sign(dst, sign);
  }
  return error;
}