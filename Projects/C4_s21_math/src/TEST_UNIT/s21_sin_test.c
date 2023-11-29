#include "s21_math_test.h"

START_TEST(sin_test_1) {
  ck_assert_double_eq_tol(s21_sin(10000), sin(10000), 0.000001);
}
END_TEST

START_TEST(sin_test_2) {
  ck_assert_double_eq_tol(s21_sin(-0.96), sin(-0.96), 0.000001);
}
END_TEST

START_TEST(sin_test_3) { ck_assert_double_nan(s21_sin(S21_NAN)); }
END_TEST

START_TEST(sin_test_4) {
  ck_assert_double_nan(s21_sin(S21_INF_POS));
  ck_assert_double_nan(sin(S21_INF_POS));
}
END_TEST

START_TEST(sin_test_5) {
  ck_assert_double_nan(s21_sin(S21_INF_NEG));
  ck_assert_double_nan(sin(S21_INF_NEG));
}
END_TEST

START_TEST(sin_test_6) {
  ck_assert_double_eq_tol(s21_sin(S21_PI), sin(S21_PI), 0.000001);
}
END_TEST

START_TEST(sin_test_7) {
  ck_assert_double_eq_tol(s21_sin(S21_2PI), sin(S21_2PI), 0.000001);
}
END_TEST

START_TEST(sin_test_8) {
  ck_assert_double_eq_tol(s21_sin(0), sin(0), 0.000001);
}
END_TEST

START_TEST(sin_test_9) {
  ck_assert_double_eq_tol(s21_sin(-S21_2PI), sin(-S21_2PI), 0.000001);
}
END_TEST

Suite *suite_sin(void) {
  Suite *s = suite_create("s_sin");
  TCase *tc = tcase_create("tc_sin");
  tcase_add_test(tc, sin_test_1);
  tcase_add_test(tc, sin_test_2);
  tcase_add_test(tc, sin_test_3);
  tcase_add_test(tc, sin_test_4);
  tcase_add_test(tc, sin_test_5);
  tcase_add_test(tc, sin_test_6);
  tcase_add_test(tc, sin_test_7);
  tcase_add_test(tc, sin_test_8);
  tcase_add_test(tc, sin_test_9);
  suite_add_tcase(s, tc);
  return s;
}
