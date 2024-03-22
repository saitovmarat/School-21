#include "s21_decimal_test.h"

START_TEST(from_float_to_decimal_tests_1) {
  s21_decimal result;
  s21_from_float_to_decimal(127.1234, &result);
  ck_assert_int_eq(result.bits[0], 1271234);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 262144);
}
END_TEST

START_TEST(from_float_to_decimal_tests_2) {
  s21_decimal result;
  s21_from_float_to_decimal(22.14836e+03, &result);
  ck_assert_int_eq(result.bits[0], 2214836);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 131072);
}
END_TEST

START_TEST(from_float_to_decimal_tests_3) {
  s21_decimal result;
  s21_from_float_to_decimal(-333.2200, &result);
  ck_assert_int_eq(result.bits[0], 33322);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147614720);
}
END_TEST
START_TEST(from_float_to_decimal_tests_4) {
  float a = -9400;
  s21_decimal result;
  s21_from_float_to_decimal(a, &result);
  ck_assert_int_eq(result.bits[0], 9400);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 2147483648);
}
END_TEST

START_TEST(from_float_to_decimal_tests_5) {
  float a = 0.0;
  s21_decimal result;
  s21_from_float_to_decimal(a, &result);
  ck_assert_int_eq(result.bits[0], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_tests_6) {
  float a = NAN;
  s21_decimal result;
  int error = s21_from_float_to_decimal(a, &result);
  ck_assert_int_eq(error, 1);
}
END_TEST
START_TEST(from_float_to_decimal_tests_7) {
  float a = 0.0000000000000009278395;
  s21_decimal result;
  s21_from_float_to_decimal(a, &result);
  ck_assert_int_eq(result.bits[0], 9278395);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 1441792);
}
END_TEST

Suite* suite_from_float_to_decimal_tests(void) {
  Suite* s = suite_create("s21_from_float_to_decimal: ");
  TCase* tc = tcase_create("s21_from_float_to_decimal: ");
  tcase_add_test(tc, from_float_to_decimal_tests_1);
  tcase_add_test(tc, from_float_to_decimal_tests_2);
  tcase_add_test(tc, from_float_to_decimal_tests_3);
  tcase_add_test(tc, from_float_to_decimal_tests_4);
  tcase_add_test(tc, from_float_to_decimal_tests_5);
  tcase_add_test(tc, from_float_to_decimal_tests_6);
  tcase_add_test(tc, from_float_to_decimal_tests_7);
  suite_add_tcase(s, tc);
  return s;
}