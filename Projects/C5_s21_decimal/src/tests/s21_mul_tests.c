#include "s21_decimal_test.h"

START_TEST(mul_tests_4) {
  float a = 0;
  float b = 45.9;
  float mul = a * b;
  float actual_mul = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_mul(a_dec, b_dec, &mul_dec);
  ck_assert_float_eq_tol(mul, actual_mul, 0.0001);
}

START_TEST(mul_tests_5) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403.0e2;
  int b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  float res_origin = 189940600;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_tests_6) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403.0;
  float b = 9403.0;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = 88416409;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_tests_7) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403;
  float b = 202;
  float res_our_dec = 0.0;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  float res_origin = 1899406;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_tests_10) {
  s21_decimal src1 = {{0, 1, 0, 0}};
  s21_decimal src2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float res_our_dec = 0.0;
  s21_mul(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our_dec);
  ck_assert_int_eq(src1.bits[0], result.bits[0]);
  ck_assert_int_eq(src1.bits[1], result.bits[1]);
  ck_assert_int_eq(src1.bits[2], result.bits[2]);
}
END_TEST

START_TEST(mul_tests_11) {
  s21_decimal src1 = {{S21_UINT_MAX, S21_UINT_MAX, S21_UINT_MAX, 0}};
  s21_decimal src2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_mul(src1, src2, &result);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(mul_tests_12) {
  s21_decimal val1 = {{0, 0, 0, 0}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  float n1 = -5.6e-15;
  float n2 = 1.5e-15;
  s21_from_float_to_decimal(n1, &val1);
  s21_from_float_to_decimal(n2, &val2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
}
END_TEST

START_TEST(mul_tests_13) {
  s21_decimal val1 = {{10000, 0, 0, 131072}};
  s21_decimal val2 = {{100000, 0, 0, 131072}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_mul(val1, val2, &res);
  ck_assert_int_eq(res.bits[0], 1000000000);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
}
END_TEST

Suite *suite_mul_tests(void) {
  Suite *s = suite_create("s21_mul: ");
  TCase *tc = tcase_create("s21_mul: ");
  tcase_add_test(tc, mul_tests_4);
  tcase_add_test(tc, mul_tests_5);
  tcase_add_test(tc, mul_tests_6);
  tcase_add_test(tc, mul_tests_7);
  tcase_add_test(tc, mul_tests_10);
  tcase_add_test(tc, mul_tests_11);
  tcase_add_test(tc, mul_tests_12);
  tcase_add_test(tc, mul_tests_13);

  suite_add_tcase(s, tc);
  return s;
}