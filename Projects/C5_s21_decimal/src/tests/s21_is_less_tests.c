#include "s21_decimal_test.h"

START_TEST(is_less_tests) {
  s21_decimal a = {{10, 0, 0, 0}};
  s21_decimal b = {{15, 0, 0, 0}};
  s21_decimal c = {{6739, 0, 0, 0}};
  s21_decimal d = {{19993, 0, 0, 0}};
  s21_decimal e = {{0, 1, 0, 0}};
  ck_assert_int_eq(s21_is_less(a, b), 1);
  ck_assert_int_eq(s21_is_less(b, a), 0);
  ck_assert_int_eq(s21_is_less(d, c), 0);
  ck_assert_int_eq(s21_is_less(d, e), 1);
}

Suite *suite_is_less_tests(void) {
  Suite *s = suite_create("s21_is_less: ");
  TCase *tc = tcase_create("s21_is_less: ");
  tcase_add_test(tc, is_less_tests);
  suite_add_tcase(s, tc);
  return s;
}