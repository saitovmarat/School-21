#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) return 1;
  zero_decimal(result);
  if (s21_get_scale(value) > 28) return 1;
  int error = 0;
  int sign = s21_get_sign(value);
  int scale = s21_get_scale(value);
  zero_decimal(result);
  s21_set_sign(&value, 0);
  int rem = 0;
  s21_truncate(value, result);
  for (int i = 0; i < scale; i++) {
    rem = s21_div_on_ten(&value);
  }
  if (rem >= 5) {
    s21_decimal one = {{1, 0, 0, 0}};
    error = s21_add_help(*result, one, result);
  }
  if (sign) s21_set_sign(result, 1);
  return error;
}
