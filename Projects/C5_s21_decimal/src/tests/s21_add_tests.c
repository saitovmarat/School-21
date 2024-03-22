#include "s21_decimal_test.h"

START_TEST(add_tests_1) {
  int a = 136;
  int b = 150;
  int sum = a + b;
  int result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_int(sum_dec, &result);
  ck_assert_int_eq(result, sum);
}
END_TEST
START_TEST(add_tests_2) {
  int a = -136;
  int b = 150;
  int sum = a + b;
  int result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_int(sum_dec, &result);
  ck_assert_int_eq(result, sum);
}
END_TEST
START_TEST(add_tests_3) {
  int a = 136;
  int b = -150;
  int sum = a + b;
  int result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_int(sum_dec, &result);
  ck_assert_int_eq(result, sum);
}
END_TEST
START_TEST(add_tests_4) {
  int a = -136;
  int b = -150;
  int sum = a + b;
  int result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_int(sum_dec, &result);
  ck_assert_int_eq(result, sum);
}
END_TEST

START_TEST(add_tests_5) {
  int a = -136;
  int b = 0;
  int sum = a + b;
  int result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_int(sum_dec, &result);
  ck_assert_int_eq(result, sum);
}
START_TEST(add_tests_6) {
  float a = 1.36;
  float b = 15.06;
  float sum = a + b;
  float result = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal sum_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_add(a_dec, b_dec, &sum_dec);
  s21_from_decimal_to_float(sum_dec, &result);
  ck_assert_float_eq(result, sum);
}
END_TEST
START_TEST(add_tests_7) {
  s21_decimal test_v_1 = {{0, 0, 0, 0}};
  s21_decimal test_v_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int = 0;
  s21_from_int_to_decimal(173789, &test_v_1);
  s21_from_int_to_decimal(47920, &test_v_2);
  s21_add(test_v_1, test_v_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 173789 + 47920);
}
END_TEST
START_TEST(add_tests_8) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  int a = -1234;
  float b = 1.234;
  float res_origin = -1232.766;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_9) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  int a = -1234;
  float b = -1.234;
  float res_origin = -1235.234;
  float res_our;
  s21_from_int_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST
START_TEST(add_tests_10) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -9403;
  float b = 0.00234;
  float res_origin = -9402.9976600;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_11) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -940.3;
  float b = 0.234;
  float res_origin = -940.0660000;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_12) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -0.940301;
  float b = 22.023401;
  float res_origin = 21.0831;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_13) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -0.9403;
  float b = -112.0234;
  float res_origin = -112.9637;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_14) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -0.94e03;
  float b = -112.0234;
  float res_origin = -1052.0234;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_15) {
  s21_decimal src1 = {{0}}, src2 = {{0}}, result = {{0}};
  float a = -0.94e03;
  float b = -112.0e2;
  float res_origin = -12140;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_add(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(add_tests_16) {
  s21_decimal test_v_1 = {{S21_UINT_MAX, S21_UINT_MAX, S21_UINT_MAX - 5, 0}};
  s21_decimal test_v_2 = {{100, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_add(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 99);
  ck_assert_int_eq(result_dec.bits[1], 0);
  ck_assert_int_eq(result_dec.bits[2], 4294967291);
  ck_assert_int_eq(result_dec.bits[3], 0);
}
END_TEST
START_TEST(add_tests_17) {
  s21_decimal a = {{0, 0, 0, 0}};
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal sum = {{0, 0, 0, 0}};
  s21_add(a, b, &sum);
  ck_assert_int_eq(sum.bits[0], 0);
  ck_assert_int_eq(sum.bits[1], 0);
  ck_assert_int_eq(sum.bits[2], 0);
  ck_assert_int_eq(sum.bits[3], 0);
}
END_TEST
Suite* suite_add_tests(void) {
  Suite* s = suite_create("s21_add: ");
  TCase* tc = tcase_create("s21_add: ");
  tcase_add_test(tc, add_tests_1);
  tcase_add_test(tc, add_tests_2);
  tcase_add_test(tc, add_tests_3);
  tcase_add_test(tc, add_tests_4);
  tcase_add_test(tc, add_tests_5);
  tcase_add_test(tc, add_tests_6);
  tcase_add_test(tc, add_tests_7);
  tcase_add_test(tc, add_tests_8);
  tcase_add_test(tc, add_tests_9);
  tcase_add_test(tc, add_tests_10);
  tcase_add_test(tc, add_tests_11);
  tcase_add_test(tc, add_tests_12);
  tcase_add_test(tc, add_tests_13);
  tcase_add_test(tc, add_tests_14);
  tcase_add_test(tc, add_tests_15);
  tcase_add_test(tc, add_tests_16);
  tcase_add_test(tc, add_tests_17);
  suite_add_tcase(s, tc);
  return s;
}