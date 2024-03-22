#include "s21_decimal_test.h"

START_TEST(truncate_tests_1) {
  float num = 9.08647;
  float expected_res = 9.0;
  float actual_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_truncate(num_dec, &res_dec);
  s21_from_decimal_to_float(res_dec, &actual_res);
  ck_assert_float_eq(expected_res, actual_res);
}
START_TEST(truncate_tests_2) {
  float num = -9.08647;
  float expected_res = -9.0;
  float actual_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_truncate(num_dec, &res_dec);
  s21_from_decimal_to_float(res_dec, &actual_res);
  ck_assert_float_eq(expected_res, actual_res);
}
START_TEST(truncate_tests_3) {
  float num = 0;
  float expected_res = 0;
  float actual_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_truncate(num_dec, &res_dec);
  s21_from_decimal_to_float(res_dec, &actual_res);
  ck_assert_float_eq(expected_res, actual_res);
}

Suite *suite_truncate_tests(void) {
  Suite *s = suite_create("s21_truncate: ");
  TCase *tc = tcase_create("s21_truncate: ");
  tcase_add_test(tc, truncate_tests_1);
  tcase_add_test(tc, truncate_tests_2);
  tcase_add_test(tc, truncate_tests_3);
  suite_add_tcase(s, tc);
  return s;
}