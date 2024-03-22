#include "s21_decimal_test.h"

START_TEST(sub_tests_1) {
  float a = 76.9;
  float b = 56.7;
  float expected_res = a - b;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(a_dec, b_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_2) {
  float a = 76.9;
  float b = -56.7;
  float expected_res = a - b;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(a_dec, b_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_3) {
  float a = -76.9;
  float b = 56.7;
  float expected_res = a - b;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(a_dec, b_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_4) {
  float a = 76.9;
  float b = 56.7;
  float expected_res = b - a;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(b_dec, a_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_5) {
  float a = 0;
  float b = -56.7;
  float expected_res = b - a;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(b_dec, a_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_6) {
  float a = 76.9;
  float b = 0;
  float expected_res = b - a;
  float actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(a, &a_dec);
  s21_from_float_to_decimal(b, &b_dec);
  s21_sub(b_dec, a_dec, &mul_dec);
  s21_from_decimal_to_float(mul_dec, &actual_res);
  ck_assert_float_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_7) {
  int a = 9;
  int b = 8;
  int expected_res = b - a;
  int actual_res = 0;
  s21_decimal a_dec = {{0, 0, 0, 0}};
  s21_decimal b_dec = {{0, 0, 0, 0}};
  s21_decimal mul_dec = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(a, &a_dec);
  s21_from_int_to_decimal(b, &b_dec);
  s21_sub(b_dec, a_dec, &mul_dec);
  s21_from_decimal_to_int(mul_dec, &actual_res);
  ck_assert_int_eq(actual_res, expected_res);
}
END_TEST
START_TEST(sub_tests_8) {
  s21_decimal src1 = {{10000, 0, 0, 0}};
  s21_decimal src2 = {{500, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int res_our;
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_int(result, &res_our);
  ck_assert_int_eq(res_our, 9500);
}
END_TEST

START_TEST(sub_tests_9) {
  s21_decimal src1 = {{9403, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float b = 202.098;
  float res_our;
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, 9200.902);
}
END_TEST

START_TEST(sub_tests_10) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = -9403;
  float b = 202.098;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(sub_tests_11) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = 9403.0;
  float b = 202.0098421232;
  float res_origin = 9200.9901578768;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(sub_tests_12) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = -9403.000;
  float b = 202.0098421232;
  float res_origin = -9605.0098421232;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_float_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(sub_tests_13) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  float a = -9403.0e2;
  int b = -202;
  float res_origin = a - b;
  float res_our;
  s21_from_float_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  s21_sub(src1, src2, &result);
  s21_from_decimal_to_float(result, &res_our);
  ck_assert_float_eq(res_our, res_origin);
}
END_TEST

START_TEST(sub_tests_14) {
  s21_decimal test_v_1 = {{1, 10, 0, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4);
  ck_assert_uint_eq(result_dec.bits[2], 0);
}
END_TEST

START_TEST(sub_tests_15) {
  s21_decimal test_v_1 = {{1, 4, 5, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4294967294);
  ck_assert_uint_eq(result_dec.bits[2], 4);
}
END_TEST

START_TEST(sub_tests_16) {
  s21_decimal test_v_1 = {0}, test_v_2 = {0};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  test_v_1.bits[0] = 2834956;
  test_v_2.bits[0] = 3834956;
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 1000000);
}
END_TEST

START_TEST(sub_tests_17) {
  s21_decimal test_v_1 = {0}, test_v_2 = {0};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  test_v_1.bits[0] = 2834956;
  s21_set_sign(&test_v_1, 1);
  s21_set_sign(&test_v_2, 1);
  test_v_2.bits[0] = 3834956;
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_int_eq(result_dec.bits[0], 1000000);
}
END_TEST

START_TEST(sub_tests_18) {
  s21_decimal test_v_1 = {{1, 0, 5, 0}};
  s21_decimal test_v_2 = {{5000, 5, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 4294962297);
  ck_assert_uint_eq(result_dec.bits[1], 4294967290);
  ck_assert_uint_eq(result_dec.bits[2], 4);
}
END_TEST

START_TEST(sub_tests_19) {
  s21_decimal test_v_1 = {{1, 0, 0, 0}};
  s21_decimal test_v_2 = {{5000, 0, 0, 0}};
  s21_set_sign(&test_v_2, 1);
  s21_decimal result_dec = {{0, 0, 0, 0}};
  s21_sub(test_v_1, test_v_2, &result_dec);
  ck_assert_uint_eq(result_dec.bits[0], 5001);
  ck_assert_uint_eq(result_dec.bits[1], 0);
  ck_assert_uint_eq(result_dec.bits[2], 0);
  ck_assert_uint_eq(result_dec.bits[3], 0);
}
END_TEST
Suite *suite_sub_tests(void) {
  Suite *s = suite_create("s21_sub: ");
  TCase *tc = tcase_create("s21_sub: ");
  tcase_add_test(tc, sub_tests_1);
  tcase_add_test(tc, sub_tests_2);
  tcase_add_test(tc, sub_tests_3);
  tcase_add_test(tc, sub_tests_4);
  tcase_add_test(tc, sub_tests_5);
  tcase_add_test(tc, sub_tests_6);
  tcase_add_test(tc, sub_tests_7);
  tcase_add_test(tc, sub_tests_8);
  tcase_add_test(tc, sub_tests_9);
  tcase_add_test(tc, sub_tests_10);
  tcase_add_test(tc, sub_tests_11);
  tcase_add_test(tc, sub_tests_12);
  tcase_add_test(tc, sub_tests_13);
  tcase_add_test(tc, sub_tests_14);
  tcase_add_test(tc, sub_tests_15);
  tcase_add_test(tc, sub_tests_16);
  tcase_add_test(tc, sub_tests_17);
  tcase_add_test(tc, sub_tests_18);
  tcase_add_test(tc, sub_tests_19);
  suite_add_tcase(s, tc);
  return s;
}