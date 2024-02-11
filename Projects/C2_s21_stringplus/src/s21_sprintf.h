#include <stdarg.h>

#include "s21_string.h"

#define S21_INF_POS +1.0 / 0.0
#define S21_INF_NEG -1.0 / 0.0
#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_NEG || x == S21_INF_POS)

typedef struct {
  int minus;
  int sign;
  int space;
  int hash;
  int zero;
  int width;
  int accuracy;
  char length;
  int number_system;
  int flag_to_size;
  int dot;
  int upper_case;
  int g;
  int e;
} Spec;

const char *get_specs(const char *format, Spec *specs);
const char *get_width(const char *format, int *width, va_list *arguments);
const char *set_specs(const char *format, Spec *specs, va_list *argumensts,
                      int *flag);

Spec set_number_system(Spec specs, char format);
char get_num_char(int num, int upper_case);

char *parser(char *str, char *src, const char *format, Spec specs,
             va_list *arguments);

char *print_decimal(char *str, Spec specs, va_list *arguments);
size_t get_size_to_decimal(Spec *specs, long int num);
int decimal_to_string(Spec specs, long long int num, char *str_to_num,
                      s21_size_t size_to_decimal);
char *print_u(char *str, Spec specs, char format, va_list *arguments);
s21_size_t get_buff_size_unsigned_decimal(Spec *specs, unsigned long int num);
int unsigned_decimal_to_string(char *buffer, Spec specs, unsigned long int num,
                               s21_size_t size_to_num);

char *print_c(char *str, Spec specs, int symbol);
char *print_s(char *str, Spec specs, va_list *arguments);
char *print_p(char *str, Spec *specs, va_list *arguments);

char *print_double(char *str, Spec specs, char format, va_list *arguments);
s21_size_t add_sym_from_double_to_str(char *str_to_double, Spec specs,
                                      s21_size_t size_to_double, int *i,
                                      long double frac, long double integer);
s21_size_t get_size_to_double(Spec *specs, long double num);
int double_to_string(char *str_to_double, Spec specs, long double num,
                     s21_size_t size_to_double);

void plus_minus_space_int(long long int num, Spec *specs, s21_size_t *size,
                          int *i, char *str);
void plus_minus_space_double(Spec specs, s21_size_t *size, long double num,
                             char *str, int *i);
void o_x(Spec specs, char *str, int *i, s21_size_t *size);
int nan_inf(char *str, long double num);
void frac_integer(long double *frac, long double *integer,
                  long double *copy_frac, int *accuracy, int *flag_to_dot);
