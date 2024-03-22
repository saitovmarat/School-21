#include "s21_decimal_test.h"

START_TEST(from_decimal_to_int_tests_1) {
  s21_decimal num = {{35, 0, 0, 0}};
  int expected_res = 35;
  int actual_res = 0;
  s21_from_decimal_to_int(num, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(from_decimal_to_int_tests_2) {
  s21_decimal num = {{35, 0, 0, 2147483648}};
  int expected_res = -35;
  int actual_res = 0;
  s21_from_decimal_to_int(num, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(from_decimal_to_int_tests_3) {
  s21_decimal num = {{689, 0, 0, 0}};
  int expected_res = 689;
  int actual_res = 0;
  s21_from_decimal_to_int(num, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
START_TEST(from_decimal_to_int_tests_4) {
  s21_decimal num = {{689, 0, 0, 2147483648}};
  int expected_res = -689;
  int actual_res = 0;
  s21_from_decimal_to_int(num, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
Suite* suite_from_decimal_to_int_tests(void) {
  Suite* s = suite_create("s21_from_decimal_to_int: ");
  TCase* tc = tcase_create("s21_from_decimal_to_int: ");
  tcase_add_test(tc, from_decimal_to_int_tests_1);
  tcase_add_test(tc, from_decimal_to_int_tests_2);
  tcase_add_test(tc, from_decimal_to_int_tests_3);
  tcase_add_test(tc, from_decimal_to_int_tests_4);
  suite_add_tcase(s, tc);
  return s;
}