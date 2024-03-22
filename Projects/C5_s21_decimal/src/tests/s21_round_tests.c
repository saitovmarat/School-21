#include "s21_decimal_test.h"

START_TEST(round_tests_1) {
  float a = 546.98647;
  int expected_res = 547;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_round(a_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(round_tests_2) {
  float a = 546.47;
  int expected_res = 546;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_round(a_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(round_tests_3) {
  float a = 0;
  int expected_res = 0;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_round(a_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(round_tests_4) {
  float a = -546.47;
  int expected_res = -546;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_round(a_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(round_tests_5) {
  float a = -546.947;
  int expected_res = -547;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_round(a_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
Suite *suite_round_tests(void) {
  Suite *s = suite_create("s21_round: ");
  TCase *tc = tcase_create("s21_round: ");
  tcase_add_test(tc, round_tests_1);
  tcase_add_test(tc, round_tests_2);
  tcase_add_test(tc, round_tests_3);
  tcase_add_test(tc, round_tests_4);
  tcase_add_test(tc, round_tests_5);
  suite_add_tcase(s, tc);
  return s;
}