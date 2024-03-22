#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0)
    error = 3;
  int sign_1 = s21_get_sign(value_1);
  int sign_2 = s21_get_sign(value_2);
  int exp = s21_get_scale(value_1) - s21_get_scale(value_2);
  s21_set_scale(&value_1, 0);
  s21_set_scale(&value_2, 0);
  s21_set_sign(&value_1, 0);
  s21_set_sign(&value_2, 0);
  s21_decimal copy = value_2;
  zero_decimal(result);
  int bit_1 = 95;
  int bit_2 = 95;
  while (s21_get_bit(value_2, bit_2) != 1) {
    bit_2--;
  }
  while (s21_get_bit(value_1, bit_1) != 1) {
    bit_1--;
  }
  while (bit_1 >= bit_2) {
    value_2 = s21_shift_left(value_2, bit_1 - bit_2);
    if (s21_is_greater_or_equal(value_1, value_2)) {
      s21_sub_simple(value_1, value_2, &value_1);
      s21_set_bit(result, bit_1 - bit_2, 1);
    } else {
      s21_set_bit(result, bit_1 - bit_2, 0);
    }
    value_2 = copy;
    bit_1--;
  }
  s21_set_scale(result, exp);
  if (exp < 0) {
    s21_set_scale(result, 0);
    s21_decimal tmp = {{0}};
    exp = abs(exp);
    int multiply = pow(10, exp);
    s21_from_int_to_decimal(multiply, &tmp);
    s21_mul(*result, tmp, result);
  }
  if (sign_1 != sign_2) s21_set_sign(result, 1);
  if (sign_1 == sign_2) s21_set_sign(result, 0);
  if (s21_get_bit(*result, 96) == 1) error = 1;
  if (error == 1 && s21_get_sign(*result) == 1) error = 2;
  return error;
}