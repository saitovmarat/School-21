#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!result) return 1;
  zero_decimal(result);
  if (s21_get_scale(value) > 28) return 1;
  int error = 0;
  int sign = s21_get_sign(value);
  int scale = s21_get_scale(value);
  s21_truncate(value, result);
  s21_decimal fract;
  s21_sub(value, *result, &fract);
  if (sign && scale && !is_zero(value) && !is_zero(fract)) {
    s21_set_sign(result, 0);
    error = s21_add_help(*result, S21_DECIMAL_ONE, result);
    s21_set_sign(result, 1);
  }
  return error;
}