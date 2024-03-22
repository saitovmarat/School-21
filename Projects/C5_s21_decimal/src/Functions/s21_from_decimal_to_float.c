#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = 0;
  if (dst == NULL)
    error = 1;
  else {
    *dst = 0.0f;
    int sign = s21_get_sign(src);
    int scale = s21_get_scale(src);
    for (unsigned int i = 0;
         i < 32 * ((sizeof(s21_decimal) / sizeof(unsigned int)) - 1); i++) {
      if (s21_get_bit(src, i)) {
        *dst += powf(2.0f, (float)i);
      }
    }
    float temp = 1.0f;
    for (int i = 0; i < scale; i++) temp *= 10.0f;
    if (temp != 1.0f) *dst = *dst / temp;
    if (sign == 1) *dst *= -1;
  }
  return error;
}
