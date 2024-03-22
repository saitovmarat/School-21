#ifndef C5_S21_DECIMAL_TEST_H
#define C5_S21_DECIMAL_TEST_H
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_decimal.h"

//арифметика
Suite *suite_div_tests(void);
Suite *suite_add_tests(void);
Suite *suite_mul_tests(void);
Suite *suite_sub_tests(void);

//сравнение
Suite *suite_is_equal_tests(void);
Suite *suite_is_greater_or_equal_tests(void);
Suite *suite_is_less_tests(void);
Suite *suite_is_greater_tests(void);
Suite *suite_is_less_or_equal_tests(void);
Suite *suite_is_not_equal_tests(void);

//конвертеры
Suite *suite_from_float_to_decimal_tests(void);
Suite *suite_from_int_to_decimal_tests(void);
Suite *suite_from_decimal_to_float_tests(void);
Suite *suite_from_decimal_to_int_tests(void);

//другие функции
Suite *suite_negate_tests(void);
Suite *suite_floor_tests(void);
Suite *suite_round_tests(void);
Suite *suite_truncate_tests(void);

#endif