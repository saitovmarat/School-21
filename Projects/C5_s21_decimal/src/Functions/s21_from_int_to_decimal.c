#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst) {
    zero_decimal(dst);
    unsigned int overflow_check = 0b11111111111111111111111111111111;
    if ((unsigned int)src > overflow_check) error = 1;
    if (src < 0) {
      s21_set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    error = 1;
  }
  return error;
}
