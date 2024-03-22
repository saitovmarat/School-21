#include "s21_decimal_test.h"

START_TEST(div_1) {
  s21_decimal src1 = {{25, 0, 0, 0}};
  s21_decimal src2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_div(src1, src2, &result);
  ck_assert_int_eq(result.bits[0], 5);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(div_2) {
  s21_decimal src1 = {{25, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res = s21_div(src1, src2, &result);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(div_3) {
  s21_decimal src1 = {{0, 1, 0, 0}};
  s21_decimal src2 = {{2, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_div(src1, src2, &result);
  ck_assert_int_eq(result.bits[0], 2147483648);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
}
END_TEST

START_TEST(div_4) {
  s21_decimal src1 = {{10, 0, 0, 0}};
  s21_decimal src2 = {{5, 0, 0, 65536}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_div(src1, src2, &result);
  ck_assert_int_eq(result.bits[0], 20);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[3], 0);
}
END_TEST

Suite* suite_div_tests(void) {
  Suite* s = suite_create("s21_div: ");
  TCase* tc = tcase_create("s21_div: ");
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  suite_add_tcase(s, tc);
  return s;
}
