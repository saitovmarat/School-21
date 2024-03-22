#include "s21_decimal_test.h"

START_TEST(is_not_equal_tests) {
  s21_decimal a = {{10, 0, 0, 0}};
  s21_decimal b = {{15, 0, 0, 0}};
  s21_decimal c = {{10, 0, 0, 0}};
  ck_assert_int_eq(s21_is_not_equal(c, a), 0);
  ck_assert_int_eq(s21_is_not_equal(a, b), 1);
}

Suite *suite_is_not_equal_tests(void) {
  Suite *s = suite_create("s21_is_not_equal: ");
  TCase *tc = tcase_create("s21_is_not_equal: ");
  tcase_add_test(tc, is_not_equal_tests);
  suite_add_tcase(s, tc);
  return s;
}
