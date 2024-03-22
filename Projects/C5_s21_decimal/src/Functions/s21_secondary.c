#include "../s21_decimal.h"

int s21_get_bit(s21_decimal dec, int index) {
  return (dec.bits[index / 32] & (1 << (index % 32))) >> (index % 32);
}

void s21_set_bit(s21_decimal *dec, int index, int bit_value) {
  uint32_t mask = 1u << (index % 32);
  if (bit_value == 0) {
    dec->bits[index / 32] = dec->bits[index / 32] & (~mask);
  } else {
    dec->bits[index / 32] = dec->bits[index / 32] | mask;
  }
}

int s21_get_sign(s21_decimal dec) { return dec.bits[3] >> 31; }

void s21_set_sign(s21_decimal *dec, int sign_value) {
  s21_set_bit(dec, 127, sign_value);
}

int s21_get_scale(s21_decimal dec) { return dec.bits[3] << 8 >> 24; }

void s21_set_scale(s21_decimal *dec, int scale_value) {
  int sign = s21_get_sign(*dec);
  dec->bits[3] = 0;
  dec->bits[3] = dec->bits[3] | scale_value << 16;
  s21_set_sign(dec, sign);
}

int s21_normalization(s21_decimal *a, s21_decimal *b) {
  int scale_a = s21_get_scale(*a);
  int scale_b = s21_get_scale(*b);
  int delta = abs(scale_a - scale_b);
  int error = delta > 29 || delta < 0 || scale_a > 29 || scale_b > 29 ||
              scale_a < 0 || scale_b < 0;
  //проверка на слигком большое или сликшом маленькое число (скейл)
  if (scale_a < scale_b) {
    while (scale_a != scale_b) {
      s21_add_help(s21_shift_left(*a, 3), s21_shift_left(*a, 1), a);
      scale_a++;
    }
  } else if (scale_b < scale_a) {
    while (scale_a != scale_b) {
      s21_add_help(s21_shift_left(*b, 3), s21_shift_left(*b, 1), b);
      scale_b++;
    }
  }
  s21_set_scale(a, scale_a);
  s21_set_scale(b, scale_b);
  return error;
}

s21_decimal s21_shift_left(s21_decimal dec, int shift_value) {
  s21_decimal result = dec;
  for (int i = 0; i < shift_value; i++) {
    int dec_31 = s21_get_bit(result, 31);
    int dec_63 = s21_get_bit(result, 63);
    result.bits[0] <<= 1u;
    result.bits[1] <<= 1u;
    s21_set_bit(&result, 32, dec_31);
    result.bits[2] <<= 1u;
    s21_set_bit(&result, 64, dec_63);
  }
  return result;
}

int is_zero(s21_decimal num) {
  if (num.bits[0] == 0 && num.bits[1] == 0 && num.bits[2] == 0) return 1;
  return 0;
}

unsigned int reverseNumber(unsigned int number) {
  unsigned int reversedNumber = 0;
  while (number != 0) {
    unsigned int remainder = number % 10;
    reversedNumber = reversedNumber * 10 + remainder;
    number /= 10;
  }
  return reversedNumber;
}

int s21_compare(s21_decimal a, s21_decimal b) {
  // return 1: first number is bigger
  // return 0: numbers is equal
  // return -1: second number is bigger
  int result = 0;
  int flag = 0;
  int sign_a = s21_get_sign(a);
  int sign_b = s21_get_sign(b);
  s21_normalization(&a, &b);
  if (sign_a != sign_b) {
    if (!sign_a) {
      result = 1;
    } else {
      result = -1;
    }
    flag = 1;
  }
  if (is_zero(a) && is_zero(b)) {
    result = 0;
    flag = 1;
  }
  int res_of_sign = sign_a || sign_b ? 1 : 0;
  int i = 95;
  while (!flag && i >= 0) {
    int bit_a = s21_get_bit(a, i);
    int bit_b = s21_get_bit(b, i);
    if (bit_a != bit_b) {
      int res_of_value = bit_a ? 1 : 0;
      result = (res_of_sign + res_of_value) % 2 == 0 ? -1 : 1;
      flag = 1;
    }
    i--;
  }
  return result;
}

int s21_add_help(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  unsigned int remainder = 0;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(unsigned) - 1) * 32;
       ++i) {
    int bit_a = s21_get_bit(value_1, i);
    int bit_b = s21_get_bit(value_2, i);
    unsigned sum = bit_a + bit_b + remainder;
    remainder = sum / 2;
    sum %= 2;
    s21_set_bit(result, i, sum);
  }
  return remainder;
}

void zero_decimal(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

int s21_get_exp(char *str) {
  int exp = 0;

  char *str_tmp = str;
  while (*str_tmp) {
    if (*str_tmp == 'E') {
      ++str_tmp;
      exp = strtol(str_tmp, NULL, 10);
      break;
    }
    ++str_tmp;
  }
  return exp;
}

int s21_string_to_decimal(char *str, s21_decimal *res) {
  char *str_tmp = str;
  zero_decimal(res);
  uint64_t tmp = 0;
  int counter = 6;
  int exp = s21_get_exp(str_tmp);

  while (*str_tmp) {
    if (*str_tmp == '.') {
      str_tmp++;
      continue;
    } else if (*str_tmp >= '0' && *str_tmp <= '9') {
      uint32_t num = (*str_tmp - '0') * (uint32_t)pow(10, counter);
      tmp += num;
      --counter;
      str_tmp++;
    } else {
      break;
    }
  }
  while (tmp % 10 == 0) {
    tmp /= 10;
    exp++;
  }
  exp -= 6;
  if (exp > 0) {
    tmp *= pow(10, exp);
    exp = 0;
  } else if (exp < 0) {
    exp *= -1;
  }
  res->bits[0] = tmp & 0b11111111111111111111111111111111;
  res->bits[1] = tmp >> 32;

  s21_set_scale(res, exp);
  return 0;
}

void get_twos_complement(s21_decimal *num) {
  s21_decimal result;
  s21_decimal one = {{1, 0, 0, 0}};
  // Получение обратного кода
  for (int i = 0; i < 3; i++) {
    num->bits[i] = ~num->bits[i];
  }
  result = add_bit(num, &one);
  for (int i = 0; i < 3; i++) {
    num->bits[i] = result.bits[i];
  }
}

// побитовое сложение
s21_decimal add_bit(s21_decimal *value_1, s21_decimal *value_2) {
  s21_decimal result;
  int buffer = 0;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(unsigned) - 1) * 32;
       ++i) {
    // берем каждый текущий бит
    int cur_bit_value_1 = s21_get_bit(*value_1, i);
    int cur_bit_value_2 = s21_get_bit(*value_2, i);

    // если оба равны 0
    if (!cur_bit_value_1 && !cur_bit_value_2) {
      if (buffer) {
        s21_set_bit(&result, i, 1);
        buffer = 0;
      } else {
        s21_set_bit(&result, i, 0);
      }
      // если не равны между собой
    } else if (cur_bit_value_1 != cur_bit_value_2) {
      if (buffer) {
        s21_set_bit(&result, i, 0);
        buffer = 1;
      } else {
        s21_set_bit(&result, i, 1);
      }
      // если оба равны 1
    } else if (buffer) {
      s21_set_bit(&result, i, 1);
      buffer = 1;
    } else {
      s21_set_bit(&result, i, 0);
      buffer = 1;
    }
  }
  return result;
}

void s21_div_10(s21_decimal *dec) {
  s21_div(*dec, S21_DECIMAL_TEN, dec);
  int scale = s21_get_scale(*dec) - 1;
  s21_set_scale(dec, scale);
}
int s21_div_on_ten(s21_decimal *dec) {
  int ost = 0;
  for (int i = 95; i >= 0; --i) {
    int bit = s21_get_bit(*dec, i);
    int new = (bit + ost * 2) / 10;
    ost = (bit + ost * 2) % 10;
    s21_set_bit(dec, i, new);
  }
  return ost;
}

int s21_sub_simple(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int error = 0;
  zero_decimal(result);
  int res = 0;
  int bit_v_ume = 0;
  int size_dec = 95;
  while (s21_get_bit(value_1, size_dec) != 1) {
    size_dec--;
  }
  for (int i = 0; i <= size_dec; i++) {
    int x = s21_get_bit(value_1, i);
    int y = s21_get_bit(value_2, i);
    res = x - y - bit_v_ume;
    if (res < 0) {
      bit_v_ume = 1;
    } else {
      bit_v_ume = 0;
    }
    res = abs(res);
    s21_set_bit(result, i, res % 2);
  }
  return error;
}