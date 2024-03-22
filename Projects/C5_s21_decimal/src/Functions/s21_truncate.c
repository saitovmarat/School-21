#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (!result) error = 1;
  zero_decimal(result);
  int scale = s21_get_scale(value);
  if (scale > 28) error = 1;
  while (s21_get_scale(value) > 0 && !error) {
    s21_div_10(&value);
  }
  if (scale < 29 && scale >= 0) {
    *result = value;
  }
  return error;
}