#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  int flag_for_zero = 0;
  error = s21_normalization(&value_1, &value_2);
  if (!error && result) {
    int sign_1 = s21_get_sign(value_1);
    int sign_2 = s21_get_sign(value_2);
    int scale = s21_get_scale(value_1);
    if (is_zero(value_1) && is_zero(value_2)) {
      zero_decimal(result);
      s21_set_scale(result, scale);
      flag_for_zero = 1;
      error = 0;
    }
    if (sign_1 == sign_2 && !flag_for_zero) {
      int remainder = s21_add_help(value_1, value_2, result);
      s21_set_sign(result, sign_1);
      s21_set_scale(result, scale);
      if (remainder) {
        error = (scale == 29) || s21_get_sign(*result) ? 2 : 1;
      }
    } else if (!flag_for_zero) {
      s21_set_sign(&value_1, 0);
      s21_set_sign(&value_2, 0);
      error = sign_1 ? s21_sub(value_2, value_1, result)
                     : s21_sub(value_1, value_2, result);
    }
  }

  return error;
}