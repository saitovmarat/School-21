#include "s21_decimal_test.h"

START_TEST(floor_tests_1) {
  float num = 874.902;
  int expected_res = 874;
  int real_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_floor(num_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &real_res);
  ck_assert_int_eq(real_res, expected_res);
}
START_TEST(floor_tests_2) {
  float num = 874.210;
  int expected_res = 874;
  int real_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_floor(num_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &real_res);
  ck_assert_int_eq(real_res, expected_res);
}
START_TEST(floor_tests_3) {
  float num = -874.902;
  int expected_res = -875;
  int real_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_floor(num_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &real_res);
  ck_assert_int_eq(real_res, expected_res);
}
START_TEST(floor_tests_4) {
  float num = -874.210;
  int expected_res = -875;
  int real_res = 0;
  s21_decimal num_dec = {{0, 0, 0, 0}};
  s21_decimal res_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(num, &num_dec);
  s21_floor(num_dec, &res_dec);
  s21_from_decimal_to_int(res_dec, &real_res);
  ck_assert_int_eq(real_res, expected_res);
}
Suite* suite_floor_tests(void) {
  Suite* s = suite_create("s21_floor: ");
  TCase* tc = tcase_create("s21_floor: ");
  tcase_add_test(tc, floor_tests_1);
  tcase_add_test(tc, floor_tests_2);
  tcase_add_test(tc, floor_tests_3);
  tcase_add_test(tc, floor_tests_4);
  suite_add_tcase(s, tc);
  return s;
}