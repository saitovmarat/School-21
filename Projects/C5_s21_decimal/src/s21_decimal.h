#ifndef C5_S21_DECIMAL_2
#define C5_S21_DECIMAL_2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define ERROR 1
#define S21_UINT_MAX 4294967295
#define S21_DECIMAL_ONE \
  (s21_decimal) {       \
    { 1, 0, 0, 0 }      \
  }
#define DEC_UNIT ((s21_decimal){{1U, 0U, 0U, 0U}})
typedef struct {
  unsigned int bits[4];
} s21_decimal;

#define S21_DECIMAL_ONE \
  (s21_decimal) {       \
    { 1, 0, 0, 0 }      \
  }
#define S21_DECIMAL_TEN \
  (s21_decimal) {       \
    { 10, 0, 0, 0}      \
  }

//secondary
int s21_get_bit(s21_decimal dec, int index);
void s21_set_bit(s21_decimal *dec, int index, int bit_value);
int s21_get_sign(s21_decimal dec);
void s21_set_sign(s21_decimal *dec, int sign_value);
int s21_get_scale(s21_decimal dec);
void s21_set_scale(s21_decimal *dec, int scale_value);
int s21_normalization(s21_decimal *a, s21_decimal *b);
int is_zero(s21_decimal num);
s21_decimal s21_shift_left(s21_decimal dec, int shift_value);
unsigned int reverseNumber(unsigned int number);
int s21_compare(s21_decimal a, s21_decimal b);
int s21_add_help(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void zero_decimal(s21_decimal *dst);
int s21_get_exp(char *str);
int s21_string_to_decimal(char *str, s21_decimal *res);
s21_decimal add_bit(s21_decimal *value_1, s21_decimal *value_2);
void get_twos_complement(s21_decimal *num);
s21_decimal add_bit(s21_decimal *value_1, s21_decimal *value_2);
void s21_div_10(s21_decimal *dec);
int s21_div_on_ten(s21_decimal *dec);
int s21_sub_simple(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//compare
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

//converse
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

//ariphmetic
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//another
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif

