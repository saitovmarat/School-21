#include "s21_decimal_test.h"

START_TEST(is_greater_tests) {
  s21_decimal a = {{10, 0, 0, 0}};
  s21_decimal b = {{15, 0, 0, 0}};
  s21_decimal e = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_greater(b, a), 1);
  ck_assert_int_eq(s21_is_greater(a, b), 0);
  ck_assert_int_eq(s21_is_greater(b, e), 0);
}

Suite *suite_is_greater_tests(void) {
  Suite *s = suite_create("s21_is_greater: ");
  TCase *tc = tcase_create("s21_is_greater: ");
  tcase_add_test(tc, is_greater_tests);
  suite_add_tcase(s, tc);
  return s;
}
