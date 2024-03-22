#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  return (s21_compare(value_1, value_2) == 0);
}