#include "s21_decimal_test.h"

START_TEST(is_equal_tests) {
  s21_decimal a = {{10, 0, 0, 0}};
  s21_decimal b = {{15, 0, 0, 0}};
  s21_decimal c = {{10, 0, 0, 0}};
  ck_assert_int_eq(s21_is_equal(c, a), 1);
  ck_assert_int_eq(s21_is_equal(a, b), 0);
}

Suite *suite_is_equal_tests(void) {
  Suite *s = suite_create("s21_is_equal: ");
  TCase *tc = tcase_create("s21_is_equal: ");
  tcase_add_test(tc, is_equal_tests);
  suite_add_tcase(s, tc);
  return s;
}