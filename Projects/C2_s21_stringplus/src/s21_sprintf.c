#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  char specifiers[] = "diuoxXcsnpfFeEgG%";
  char *src = str;

  va_list arguments;
  va_start(arguments, format);

  while (*format) {
    if (*format == '%') {
      format++;
      Spec specs = {0};
      specs.number_system = 10;
      while (!s21_strchr(specifiers, *format)) {
        int flag = 0;
        format = set_specs(format, &specs, &arguments, &flag);
        if (flag) break;
      }
      str = parser(str, src, format, specs, &arguments);
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arguments);
  return (str - src);
}
const char *get_specs(const char *format, Spec *specs) {
  while (format) {
    if (*format == '+')
      specs->sign = 1;
    else if (*format == '-')
      specs->minus = 1;
    else if (*format == '#')
      specs->hash = 1;
    else if (*format == ' ')
      specs->space = 1;
    else if (*format == '0')
      specs->zero = 1;
    else
      break;
    format++;
  }
  specs->space = (specs->space && !specs->sign);
  specs->zero = (specs->zero && !specs->minus);
  return format;
}
const char *get_width(const char *format, int *width, va_list *arguments) {
  *width = 0;
  if (*format == '*') {
    *width = va_arg(*arguments, int);
    format++;
  }
  while (format) {
    if (*format >= '0' && *format <= '9') {
      *width *= 10;
      *width += *format - '0';
    } else
      break;
    format++;
  }
  return format;
}
const char *set_specs(const char *format, Spec *specs, va_list *argumensts,
                      int *flag) {
  const char *formatPos = format;
  format = get_specs(format, specs);
  format = get_width(format, &specs->width, argumensts);
  if (*format == '.') {
    specs->dot = 1;
    format++;
    format = get_width(format, &specs->accuracy, argumensts);
  }

  format = get_specs(format, specs);
  if (*format == 'L')
    specs->length = 'L';
  else if (*format == 'l')
    specs->length = 'l';
  else if (*format == 'h')
    specs->length = 'h';

  if (specs->length != 0) format++;
  if (formatPos == format) *flag = 1;
  return format;
}
char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments) {
  if (*format == 'd' || *format == 'i') {
    str = print_decimal(str, specs, arguments);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    specs = set_number_system(specs, *format);
    str = print_u(str, specs, *(format - 1), arguments);
  } else if (*format == 'c') {
    int symbol = va_arg(*arguments, int);
    str = print_c(str, specs, symbol);
  } else if (*format == 's') {
    str = print_s(str, specs, arguments);
  } else if (*format == 'p') {
    str = print_p(str, &specs, arguments);
  } else if (*format == 'n') {
    int *n = va_arg(*arguments, int *);
    *n = (int)(str - src);
  } else if (*format == 'f' || *format == 'F') {
    str = print_double(str, specs, *(format - 1), arguments);
  } else if (*format == '%') {
    str = print_c(str, specs, '%');
  }
  if (!str) *src = '\0';
  return str;
}
char *print_decimal(char *str, Spec specs, va_list *arguments) {
  long long int num = 0;
  if (specs.length == 'L')
    num = (long long int)va_arg(*arguments, long long int);
  else if (specs.length == 'l')
    num = (long int)va_arg(*arguments, long int);
  else if (specs.length == 'h')
    num = (short)va_arg(*arguments, int);
  else
    num = (int)va_arg(*arguments, int);

  s21_size_t size_to_decimal = get_size_to_decimal(&specs, num);
  char *str_to_num = malloc(sizeof(char) * size_to_decimal);
  if (str_to_num) {
    int i = decimal_to_string(specs, num, str_to_num, size_to_decimal);
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_num[j];
      str++;
    }
    while (i < specs.width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_num) free(str_to_num);
  return str;
}
int decimal_to_string(Spec specs, long long int num, char *str_to_num,
                      s21_size_t size_to_decimal) {
  int flag = 0;
  if (num < 0) {
    flag = 1;
    num = -num;
  }
  int i = 0;
  long long int numCopy = num;
  if ((numCopy == 0 && (specs.accuracy || specs.width || specs.space)) ||
      (numCopy == 0 && !specs.accuracy && !specs.width && !specs.space &&
       !specs.dot)) {
    char sym = numCopy % specs.number_system + '0';
    str_to_num[i] = sym;
    i++;
    size_to_decimal--;
    numCopy /= 10;
  }
  while (numCopy && str_to_num && size_to_decimal) {
    char sym = get_num_char(numCopy % specs.number_system, specs.upper_case);
    str_to_num[i] = sym;
    i++;
    size_to_decimal--;
    numCopy /= 10;
  }
  if (flag) num = -num;
  flag = 0;
  if (specs.accuracy - i > 0) {
    specs.accuracy -= i;
    specs.zero = 1;
  } else
    flag = 1;
  if (size_to_decimal == 1 && specs.zero == 1 && specs.flag_to_size == 1)
    specs.zero = 0;
  while (specs.zero && str_to_num &&
         ((int)size_to_decimal > specs.flag_to_size) &&
         (specs.accuracy || flag)) {
    if (size_to_decimal == 1 && specs.flag_to_size == 1) break;
    if (size_to_decimal <= 0) break;
    str_to_num[i] = '0';
    i++;
    size_to_decimal--;
    specs.accuracy--;
  }
  plus_minus_space_int(num, &specs, &size_to_decimal, &i, str_to_num);
  if (size_to_decimal > 0 && !specs.minus) {
    while (size_to_decimal - specs.flag_to_size > 0 && str_to_num) {
      str_to_num[i] = ' ';
      i++;
      size_to_decimal--;
    }
  }
  return i;
}
char get_num_char(int num, int upper_case) {
  char flag = '0';
  switch (num) {
    case 10:
      flag = (char)('a' - upper_case * 32);
      break;
    case 11:
      flag = (char)('b' - upper_case * 32);
      break;
    case 12:
      flag = (char)('c' - upper_case * 32);
      break;
    case 13:
      flag = (char)('d' - upper_case * 32);
      break;
    case 14:
      flag = (char)('e' - upper_case * 32);
      break;
    case 15:
      flag = (char)('f' - upper_case * 32);
      break;
    default:
      break;
  }
  if (num >= 0 && num <= 9) flag = (char)(num + '0');
  return flag;
}
Spec set_number_system(Spec specs, char format) {
  if (format == 'o')
    specs.number_system = 8;
  else if (format == 'x' || format == 'X')
    specs.number_system = 16;
  if (format == 'X') specs.upper_case = 1;
  return specs;
}
char *print_u(char *str, Spec specs, char format, va_list *arguments) {
  unsigned long int num = 0;
  if (format == 'l')
    num = (unsigned long int)va_arg(*arguments, unsigned long int);
  else if (format == 'h')
    num = (unsigned short int)va_arg(*arguments, unsigned int);
  else
    num = (unsigned int)va_arg(*arguments, unsigned int);

  s21_size_t size_to_num = get_buff_size_unsigned_decimal(&specs, num);
  char *str_to_num = malloc(sizeof(char) * size_to_num);
  if (str_to_num) {
    int i = unsigned_decimal_to_string(str_to_num, specs, num, size_to_num);
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_num[j];
      str++;
    }
    while (i < specs.width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_num) free(str_to_num);
  return str;
}
s21_size_t get_buff_size_unsigned_decimal(Spec *specs, unsigned long int num) {
  s21_size_t result = 0;
  long int numCopy = num;
  while (numCopy > 0) {
    numCopy /= specs->number_system;
    result++;
  }
  if (specs->hash) result += 2;
  if (numCopy == 0 && result == 0 &&
      (specs->accuracy || specs->width || specs->space))
    result++;

  if ((s21_size_t)specs->width > result) result = specs->width;
  if ((s21_size_t)specs->accuracy > result) {
    result = specs->accuracy;
    if (specs->hash && specs->number_system == 16) result += 2;
  }

  if ((result == 0 || specs->hash) && num == 0 && !specs->accuracy &&
      !specs->width && !specs->space && !specs->dot)
    result++;

  return result;
}
s21_size_t get_size_to_decimal(Spec *specs, long int num) {
  s21_size_t result = 0;
  long int numCopy = num;
  if (numCopy < 0) {
    specs->sign = 1;
    numCopy = -num;
  }
  while (numCopy > 0) {
    numCopy /= specs->number_system;
    result++;
  }
  if (numCopy == 0 && result == 0 &&
      (specs->accuracy || specs->width || specs->space))
    result++;

  if (specs->space || specs->sign || num < 0) {
    specs->flag_to_size = 1;
    result++;
  }

  if ((s21_size_t)specs->width > result) result = specs->width;
  if ((s21_size_t)specs->accuracy > result) result = specs->accuracy;

  if (specs->sign && num == 0) result++;
  if (result == (s21_size_t)specs->accuracy && (specs->sign || specs->space))
    result++;

  if (result == 0 && numCopy == 0 && !specs->accuracy && !specs->width &&
      !specs->space && !specs->dot)
    result++;
  return result;
}
int unsigned_decimal_to_string(char *str_to_num, Spec specs,
                               unsigned long int num, s21_size_t size_to_num) {
  int i = 0;
  int flag = 0;
  unsigned long int numCopy = num;
  if (specs.hash && specs.number_system == 8)
    specs.flag_to_size = 1;
  else if (specs.hash && specs.number_system == 16)
    specs.flag_to_size = 2;
  if ((numCopy == 0 && (specs.accuracy || specs.width || specs.space)) ||
      (numCopy == 0 && !specs.accuracy && !specs.width && !specs.space &&
       !specs.dot)) {
    char sym = numCopy % specs.number_system + '0';
    str_to_num[i] = sym;
    i++;
    size_to_num--;
    numCopy /= 10;
  }
  while (numCopy && str_to_num && size_to_num) {
    char sym = get_num_char(numCopy % specs.number_system, specs.upper_case);
    str_to_num[i] = sym;
    i++;
    size_to_num--;
    numCopy /= specs.number_system;
  }
  if (flag) num = -num;
  flag = 0;
  if (specs.accuracy - i > 0) {
    specs.accuracy -= i;
    specs.zero = 1;
  } else
    flag = 1;
  if (size_to_num == 1 && specs.zero == 1 && specs.flag_to_size == 1)
    specs.zero = 0;
  while (specs.zero && str_to_num && (size_to_num - specs.flag_to_size > 0) &&
         (specs.accuracy || flag)) {
    if (size_to_num == 1 && specs.flag_to_size == 1) break;
    if (size_to_num <= 0) break;
    str_to_num[i] = '0';
    i++;
    size_to_num--;
    specs.accuracy--;
  }
  o_x(specs, str_to_num, &i, &size_to_num);
  if (size_to_num > 0 && specs.minus == 0) {
    while ((size_to_num > 0) && str_to_num) {
      str_to_num[i] = ' ';
      i++;
      size_to_num--;
    }
  }
  return i;
}
char *print_c(char *str, Spec specs, int symbol) {
  char *ptr = s21_NULL;

  while (specs.width - 1 > 0 && !specs.minus) {
    *str = (specs.zero) ? '0' : ' ';
    str++;
    specs.width--;
  }
  if (symbol <= 127) {
    *str = (char)symbol;
    str++;
    specs.width--;
    while (specs.width > 0 && specs.minus) {
      *str = (specs.zero) ? '0' : ' ';
      str++;
      specs.width--;
    }
    ptr = str;
  }
  return ptr;
}
char *print_s(char *str, Spec specs, va_list *arguments) {
  char *ptr = str;
  char *string = va_arg(*arguments, char *);

  if (string) {
    int temp = specs.width, i = 0;
    if ((s21_size_t)specs.width < s21_strlen(string)) {
      specs.width = s21_strlen(string);
    }
    int blank = specs.width - s21_strlen(string);
    if (specs.accuracy == 0) specs.accuracy = specs.width;
    if (specs.accuracy != 0 && specs.accuracy < temp)
      blank = temp - specs.accuracy;

    while (blank && !specs.minus) {
      *str = ' ';
      str++;
      blank--;
    }
    while (*string != '\0') {
      if (!specs.accuracy) break;
      *str = *string;
      str++;
      string++;
      i++;
      specs.accuracy--;
    }

    while (blank && specs.minus) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    str = s21_memcpy(str, "{null}", 6);
    str += 6;
  }
  if (ptr) ptr = str;
  return ptr;
}
char *print_p(char *str, Spec *specs, va_list *arguments) {
  unsigned long int ptr =
      (unsigned long int)va_arg(*arguments, unsigned long int);
  specs->number_system = 16;
  specs->hash = 1;
  specs->upper_case = 0;
  s21_size_t size_to_num = get_buff_size_unsigned_decimal(specs, ptr);
  char *str_to_num = malloc(sizeof(char) * size_to_num);
  if (str_to_num) {
    int i = unsigned_decimal_to_string(str_to_num, *specs, ptr, size_to_num);
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_num[j];
      str++;
    }
    while (i < specs->width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_num) free(str_to_num);
  return str;
}
char *print_double(char *str, Spec specs, char format, va_list *arguments) {
  long double num = 0;
  if (format == 'L')
    num = va_arg(*arguments, long double);
  else
    num = va_arg(*arguments, double);

  s21_size_t size_to_double = get_size_to_double(&specs, num);
  char *str_to_double = malloc(sizeof(char) * size_to_double);
  if (str_to_double) {
    int i = double_to_string(str_to_double, specs, num, size_to_double);
    for (int j = i - 1; j >= 0; j--) {
      *str = str_to_double[j];
      str++;
    }
    while (i < specs.width) {
      *str = ' ';
      str++;
      i++;
    }
  }
  if (str_to_double) free(str_to_double);
  return str;
}

s21_size_t get_size_to_double(Spec *specs, long double num) {
  if (S21_IS_INF(num) || S21_IS_NAN(num)) {
    if (num == S21_INF_NEG) return 4;
    return 3;
  }

  s21_size_t result = 0;
  (specs->accuracy == 0 && !specs->dot) ? specs->accuracy = 6 : 0;
  int accuracy = specs->accuracy;
  long double integer = 0;
  modfl(num, &integer);
  if (specs->space || specs->sign || num < 0) {
    specs->flag_to_size = 1;
    result++;
    if (num < 0) integer = -integer;
  }
  result += accuracy;

  if (integer == 0) result++;
  while (integer > 0.999999999) {
    result++;
    integer /= 10;
  }
  // точка
  if (specs->accuracy) result++;

  if ((s21_size_t)specs->width > result) result = specs->width;
  return result;
}

int double_to_string(char *str_to_double, Spec specs, long double num,
                     s21_size_t size_to_double) {
  int check = nan_inf(str_to_double, num);
  if (!check) {
    int i = 0;
    int flag = 0;
    if (num < 0) {
      flag = 1;
      num = -num;
    }
    long double integer = 0;
    long double frac = modfl(num, &integer);

    int accuracy = specs.accuracy;

    long double copy_frac = frac;

    int flag_to_dot = 0;
    frac_integer(&frac, &integer, &copy_frac, &accuracy, &flag_to_dot);

    size_to_double = add_sym_from_double_to_str(
        str_to_double, specs, size_to_double, &i, frac, integer);
    if (flag) num = -num;

    flag = 0;
    if (specs.accuracy - i > 0) {
      specs.accuracy -= i;
      specs.zero = 1;
    } else
      flag = 1;

    if (size_to_double == 1 && specs.zero == 1 && specs.flag_to_size == 1)
      specs.zero = 0;

    while (specs.zero && str_to_double &&
           (size_to_double - specs.flag_to_size > 0) &&
           (specs.accuracy || flag)) {
      if (size_to_double == 1 && specs.flag_to_size == 1) break;
      if (size_to_double <= 0) break;
      str_to_double[i] = '0';
      i++;
      size_to_double--;
      specs.accuracy--;
    }

    plus_minus_space_double(specs, &size_to_double, num, str_to_double, &i);
    if (size_to_double > 0 && specs.minus == 0) {
      while ((size_to_double - specs.flag_to_size > 0) && str_to_double) {
        str_to_double[i] = ' ';
        i++;
        size_to_double--;
      }
    }
    return i;
  } else
    return check;
}

s21_size_t add_sym_from_double_to_str(char *str_to_double, Spec specs,
                                      s21_size_t size_to_double, int *i,
                                      long double frac, long double integer) {
  long int fracCopy = (long int)frac;
  long int integerCopy = (long int)integer;
  int accuracy = specs.accuracy;
  while (accuracy > 0) {
    str_to_double[*i] = fracCopy % 10 + '0';
    (*i)++;
    size_to_double--;
    fracCopy /= 10;
    accuracy--;
  }
  if (specs.accuracy != 0) {
    str_to_double[*i] = '.';
    (*i)++;
    size_to_double--;
  }

  if (integerCopy == 0) {
    str_to_double[*i] = '0';
    (*i)++;
    size_to_double--;
  }
  while (integerCopy > 0) {
    str_to_double[*i] = integerCopy % 10 + '0';
    (*i)++;
    size_to_double--;
    integerCopy /= 10;
  }
  return size_to_double;
}
void plus_minus_space_int(long long int num, Spec *specs, s21_size_t *size,
                          int *i, char *str) {
  if (specs->space && num >= 0 && *size) {
    str[*i] = ' ';
    specs->flag_to_size = 0;
    (*i)++;
    (*size)--;
  }
  if (num < 0 && *size) {
    str[*i] = '-';
    specs->flag_to_size = 0;
    (*i)++;
    (*size)--;
  }
  if (num >= 0 && specs->sign && *size) {
    str[*i] = '+';
    specs->flag_to_size = 0;
    (*i)++;
    (*size)--;
  }
}

void plus_minus_space_double(Spec specs, s21_size_t *size, long double num,
                             char *str, int *i) {
  if (specs.space && num >= 0 && *size) {
    str[*i] = ' ';
    (*i)++;
    (*size)--;
  }
  if (num < 0 && *size) {
    str[*i] = '-';
    (*i)++;
    (*size)--;
  }
  if (num >= 0 && specs.sign && *size) {
    str[*i] = '+';
    (*i)++;
    (*size)--;
  }
}
void o_x(Spec specs, char *str, int *i, s21_size_t *size) {
  if (specs.hash && specs.number_system == 8) {
    str[*i] = '0';
    (*i)++;
    (*size)--;
  } else if (specs.hash && specs.number_system == 16 && specs.upper_case) {
    str[*i] = 'X';
    (*i)++;
    (*size)--;
    str[*i] = '0';
    (*i)++;
    (*size)--;
  } else if (specs.hash && specs.number_system == 16 && !specs.upper_case) {
    str[*i] = 'x';
    (*i)++;
    (*size)--;
    str[*i] = '0';
    (*i)++;
    (*size)--;
  }
}

int nan_inf(char *str, long double num) {
  int result = 0;
  if (S21_IS_INF(num)) {
    char inf[] = "inf";
    for (int i = 2; i >= 0; i--) {
      *str = inf[i];
      str++;
    }
    if (num == S21_INF_NEG) {
      *str = '-';
      str++;
      result = 4;
    } else
      result = 3;
  } else if (S21_IS_NAN(num)) {
    char nan[] = "nan";
    for (int i = 2; i >= 0; i--) {
      *str = nan[i];
      str++;
    }
    result = 3;
  }
  return result;
}

void frac_integer(long double *frac, long double *integer,
                  long double *copy_frac, int *accuracy, int *flag_to_dot) {
  if (*frac + 0.000000000000001 >= 1) {
    *frac = 0;
    *integer += 1;
  }
  for (int j = 0; j < 15; j++) {
    *copy_frac *= 10;
    if ((long)(*copy_frac) != 0) break;
  }

  while (*accuracy > 0) {
    *frac *= 10;
    (*accuracy)--;
  }
  if (fmodl(fabsl(*frac) * 10, 10.0) > 4) *frac = roundl(*frac);

  if ((long)(*frac) == 0) *flag_to_dot = 1;
}

