#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  unsigned int fact_num = 0;
  s21_truncate(src, &src);
  int error = (src.bits[2] != 0 || src.bits[1] != 0);
  int sign = s21_get_sign(src);
  fact_num = src.bits[0];
  if (sign) fact_num *= (-1);
  *dst = fact_num;
  return error;
}