#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_normalization(&value_1, &value_2);
  memset(result->bits, 0, sizeof(result->bits));
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int result_sign;
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  // если знак чисел не равен, меняем знак второго числа, потом складываем
  if (sign_1 != sign_2) {
    result_sign = sign_1;
    error = s21_add(value_1, value_2, result);
    s21_set_sign(result, result_sign);
  } else {
    int cmp_result = s21_compare(value_1, value_2);
    if (cmp_result == 0) {
      memset(result->bits, 0, sizeof(result->bits));
    } else {
      s21_decimal *small, *big;

      if (cmp_result < 0) {
        // меняем местами числа и устанавливаем знак результата
        small = &value_1;
        big = &value_2;
        result_sign = !sign_2;
      } else {
        small = &value_2;
        big = &value_1;
        result_sign = sign_2;
      }
      get_twos_complement(small);
      error = s21_add(*big, *small, result);
      s21_set_sign(result, result_sign);
    }
  }
  return error;
}