#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return ERROR;
  *result = value;
  int sign = s21_get_sign(value);
  if (!sign) s21_set_sign(result, 1);
  if (sign) s21_set_sign(result, 0);
  return 0;
}