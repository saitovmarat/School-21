#include "s21_decimal_test.h"

START_TEST(from_decimal_to_float_tests_1) {
  s21_decimal num = {{3456, 0, 0, 0b10000000000000100000000000000000}};
  float expected_res = -34.56;
  float real_res = 0;
  s21_from_decimal_to_float(num, &real_res);
  ck_assert_float_eq(real_res, expected_res);
}
START_TEST(from_decimal_to_float_tests_2) {
  s21_decimal num = {{3456, 0, 0, 0b00000000000000100000000000000000}};
  float expected_res = 34.56;
  float real_res = 0;
  s21_from_decimal_to_float(num, &real_res);
  ck_assert_float_eq(real_res, expected_res);
}
START_TEST(from_decimal_to_float_tests_3) {
  s21_decimal num = {{3456, 0, 0, 0b00000000000000100000000000000000}};
  float expected_res = 34.56;
  float real_res = 0;
  s21_from_decimal_to_float(num, &real_res);
  ck_assert_float_eq(real_res, expected_res);
}
START_TEST(from_decimal_to_float_tests_4) {
  s21_decimal num = {{0, 0, 0, 0}};
  float expected_res = 0;
  float real_res = 0;
  s21_from_decimal_to_float(num, &real_res);
  ck_assert_float_eq(real_res, expected_res);
}
Suite* suite_from_decimal_to_float_tests(void) {
  Suite* s = suite_create("s21_from_decimal_to_float: ");
  TCase* tc = tcase_create("s21_from_decimal_to_float: ");
  tcase_add_test(tc, from_decimal_to_float_tests_1);
  tcase_add_test(tc, from_decimal_to_float_tests_2);
  tcase_add_test(tc, from_decimal_to_float_tests_3);
  tcase_add_test(tc, from_decimal_to_float_tests_4);
  suite_add_tcase(s, tc);
  return s;
}