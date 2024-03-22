#include "s21_decimal_test.h"

START_TEST(negate_tests_1) {
  int num = 12345;
  s21_decimal dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(num, &dec);
  s21_negate(dec, &dec);
  int result = 0;
  s21_from_decimal_to_int(dec, &result);
  ck_assert_int_eq(result, -12345);
}
END_TEST
START_TEST(negate_tests_2) {
  int num = -54321;
  s21_decimal dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(num, &dec);
  s21_negate(dec, &dec);
  int result = 0;
  s21_from_decimal_to_int(dec, &result);
  ck_assert_int_eq(result, 54321);
}
END_TEST
START_TEST(negate_tests_3) {
  int num = 0;
  s21_decimal dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(num, &dec);
  s21_negate(dec, &dec);
  int result = 0;
  s21_from_decimal_to_int(dec, &result);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_negate_tests(void) {
  Suite *s = suite_create("s21_negate: ");
  TCase *tc = tcase_create("s21_negate: ");
  tcase_add_test(tc, negate_tests_1);
  tcase_add_test(tc, negate_tests_2);
  tcase_add_test(tc, negate_tests_3);
  suite_add_tcase(s, tc);
  return s;
}