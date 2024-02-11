#include "s21_string_test.h"

START_TEST(memchr_tests) {
  ck_assert_str_eq(s21_memchr("dikibraz", 'i', 8), memchr("dikibraz", 'i', 8));
  ck_assert_ptr_null(s21_memchr("dikobraz", 'D', 8));
  ck_assert_str_eq(s21_memchr("DiKoBrAz", 'D', 8), memchr("DiKoBrAz", 'D', 8));
  ck_assert_ptr_null(s21_memchr("dikobraz", 'D', 8));
  ck_assert_ptr_null(s21_memchr("", 's', 1));
  ck_assert_ptr_null(s21_memchr("dikObraz_69", '2', 11));
}
END_TEST
START_TEST(memcmp_tests) {
  char *str1 = "albunistricheskiy";
  char *str2 = "albunistricheskiy";
  ck_assert_int_eq(s21_memcmp(str1, str2, 18), memcmp(str1, str2, 18));
  str1 = "";
  str2 = "";
  ck_assert_int_eq(s21_memcmp(str1, str2, 0), memcmp(str1, str2, 0));
  str1 = "seksualnye utyata#";
  str2 = "seksualnye utyata!";
  ck_assert_int_eq(s21_memcmp(str1, str2, 18), memcmp(str1, str2, 18));
  str1 = "seksualnye utyata!";
  str2 = "seksualnye utyata#";
  ck_assert_int_eq(s21_memcmp(str1, str2, 18), memcmp(str1, str2, 18));
}
END_TEST
START_TEST(memcpy_tests) {
  char dest[50];
  char src[] = "albunistricheckiy unichtozhaet stringi";
  ck_assert_str_eq(s21_memcpy(dest, src, 10), memcpy(dest, src, 10));
}
END_TEST
START_TEST(memset_tests) {
  char str[] = "123456789";

  ck_assert_str_eq(s21_memset(str, '0', 3), memset(str, '0', 3));
  ck_assert_str_eq(s21_memset(str, 'H', 10), memset(str, 'H', 10));
}
END_TEST
START_TEST(strncat_tests) {
  char str1[20] = "Hello";
  char str2[] = " World";
  int n = 7;
  s21_strncat(str1, str2, n);
  ck_assert_str_eq(str1, "Hello World");
}
END_TEST
START_TEST(strchr_tests) {
  char *str = "school_21\0";
  char ch = '\0';
  ck_assert_str_eq(s21_strchr(str, ch), strchr(str, ch));
  str = "school_42";
  ch = '1';
  ck_assert_ptr_null(s21_strchr(str, ch));
  str = "";
  ch = '2';
  ck_assert_ptr_null(s21_strchr(str, ch));
}
END_TEST
START_TEST(strncmp_tests) {
  ck_assert_int_eq(s21_strncmp("SCHOOL", "SCHO", 6),
                   strncmp("SCHOOL", "SCHO", 6));
  ck_assert_int_eq(s21_strncmp("hello", "hi", 20), strncmp("hello", "hi", 20));
  ck_assert_int_eq(s21_strncmp("hi", "hello", 2), strncmp("hi", "hello", 2));
  ck_assert_int_eq(s21_strncmp(" ", "hello", 10), strncmp(" ", "hello", 10));
  ck_assert_int_eq(s21_strncmp("hi", "hello", 0), strncmp("hi", "hello", 0));
}
END_TEST
START_TEST(strncpy_tests) {
  char str1[20] = "Hi";
  const char str2[20] = "Hello World";
  const char str3[3] = "Hel";
  char str4[20] = "Hello";
  //  ck_assert_str_eq(s21_strncpy(str1, str2, 0), strncpy(str1, str2, 0));
  ck_assert_str_eq(s21_strncpy(str1, str2, 20), strncpy(str1, str2, 20));
  ck_assert_str_eq(s21_strncpy(str4, str3, 5), strncpy(str4, str3, 5));
}
END_TEST
START_TEST(strcspn_tests) {
  ck_assert_uint_eq(s21_strcspn("hel lo", " "), strcspn("hel lo", " "));
  ck_assert_uint_eq(s21_strcspn("hello", "el"), strcspn("hello", "el"));
  ck_assert_uint_eq(s21_strcspn("hello", "pw"), strcspn("hello", "pw"));
}
END_TEST
START_TEST(strerror_tests) {
  int num = 1;
  char *result = "Operation not permitted";
  ck_assert_str_eq(s21_strerror(num), result);
  num = 456;
  result = "Unknown error: 456";
  ck_assert_str_eq(s21_strerror(num), result);
  num = -9;
  result = "Unknown error: -9";
  ck_assert_str_eq(s21_strerror(num), result);
}
END_TEST
START_TEST(strlen_tests) {
  char *str = "SCHOOL";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
  str = "";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
  str = "1";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
  str = "1111112222233333333333333";
  ck_assert_int_eq(s21_strlen(str), strlen(str));
}
END_TEST
START_TEST(strpbrk_tests) {
  char *str = "School_21";
  char *charset = "21";
  ck_assert_str_eq(s21_strpbrk(str, charset), strpbrk(str, charset));
  str = "School_42";
  charset = "21";
  ck_assert_str_eq(s21_strpbrk(str, charset), strpbrk(str, charset));
  str = "School_42";
  charset = "56";
  ck_assert_ptr_null(s21_strpbrk(str, charset));
  str = "";
  charset = "5";
  ck_assert_ptr_null(s21_strpbrk(str, charset));
}
END_TEST
START_TEST(strrchr_tests) {
  char *str = "school_21";
  char ch = '2';
  ck_assert_str_eq(s21_strrchr(str, ch), strrchr(str, ch));
  str = "school_42";
  ch = '1';
  ck_assert_ptr_null(s21_strrchr(str, ch));
  str = "";
  ch = '2';
  ck_assert_ptr_null(s21_strrchr(str, ch));
}
END_TEST
START_TEST(strstr_tests) {
  char *str = "SCHOOL 21 IN KAZAN";
  char *substr = "IN";
  ck_assert_str_eq(s21_strstr(str, substr), strstr(str, substr));
  //    str = "";
  //    substr = "";
  //    ck_assert_pstr_eq(s21_strstr(str, substr), strstr(str, substr)); не
  //    рабочий тест
  str = "STRINGI IZ ZHEMCHUGA";
  substr = "ZOLOTO";
  ck_assert_pstr_eq(s21_strstr(str, substr), strstr(str, substr));
}
END_TEST
START_TEST(strtok_tests) {
  char str[] = "3";
  const char delim[] = "4";
  ck_assert_pstr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST
START_TEST(s21_to_upper_tests) {
  char *str1 = "school";
  char *str2 = "SCHOOL";
  ck_assert_str_eq(s21_to_upper(str1), str2);
  str1 = "sChOoL";
  str2 = "SCHOOL";
  ck_assert_str_eq(s21_to_upper(str1), str2);
  str1 = s21_NULL;
  ck_assert_ptr_null(s21_to_upper(str1));
}
END_TEST
START_TEST(s21_to_lower_tests) {
  char *str1 = "SCHOOL";
  char *str2 = "school";
  ck_assert_str_eq(s21_to_lower(str1), str2);
  str1 = "sChOoL";
  str2 = "school";
  ck_assert_str_eq(s21_to_lower(str1), str2);
  str1 = s21_NULL;
  ck_assert_ptr_null(s21_to_lower(str1));
}
END_TEST
START_TEST(s21_insert_tests) {
  char *str1 = "SCHOOL ";
  char *str2 = "21";
  char *res = "SCHOOL 21";
  ck_assert_str_eq(s21_insert(str1, str2, 7), res);
  str1 = "SCHOOL ";
  str2 = s21_NULL;
  ck_assert_ptr_null(s21_insert(str1, str2, 7));
}
END_TEST
START_TEST(s21_trim_tests) {
  char *str1 = "     SCHOOL     ";
  char *str2 = " ";
  char *res = "SCHOOL";
  ck_assert_str_eq(s21_trim(str1, str2), res);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_c) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  char sign = '&';
  //ТОЛЬКО ШИРИНА
  //без флагов
  s21_sprintf(arr1, "It is %5c", sign);
  sprintf(arr2, "It is %5c", sign);
  ck_assert_str_eq(arr1, arr2);
  //один флаг
  s21_sprintf(arr1, "It is %-5c", sign);
  sprintf(arr2, "It is %-5c", sign);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_d) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  //ПОЛОЖИТЕЛЬНОЕ ЧИСЛО
  int sign = 5;
  //ТОЛЬКО ШИРИНА
  //без флагов
  s21_sprintf(arr1, "It is %5d", sign);
  sprintf(arr2, "It is %5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //один флаг
  s21_sprintf(arr1, "It is %-5d", sign);
  sprintf(arr2, "It is %-5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5d", sign);
  sprintf(arr2, "It is %+5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5d", sign);
  sprintf(arr2, "It is % 5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %05d", sign);
  sprintf(arr2, "It is %05d", sign);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %- 5d", sign);
  sprintf(arr2, "It is %- 5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-+5d", sign);
  sprintf(arr2, "It is %-+5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+05d", sign);
  sprintf(arr2, "It is %+05d", sign);
  ck_assert_str_eq(arr1, arr2);
  //ТОЛЬКО ТОЧНОСТЬ
  //без флагов
  s21_sprintf(arr1, "It is %.5d", sign);
  sprintf(arr2, "It is %.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //один флаг
  s21_sprintf(arr1, "It is %-.5d", sign);
  sprintf(arr2, "It is %-.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+.5d", sign);
  sprintf(arr2, "It is %+.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % .5d", sign);
  sprintf(arr2, "It is % .5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %- .5d", sign);
  sprintf(arr2, "It is %- .5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-+.5d", sign);
  sprintf(arr2, "It is %-+.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //ШИРИНА И ДЛИНА ПОДАЮТСЯ ВМЕСТЕ
  //ширина и длина подаются через звездочку
  s21_sprintf(arr1, "It is %*.*d", 12, 14, sign);
  sprintf(arr2, "It is %*.*d", 12, 14, sign);
  ck_assert_str_eq(arr1, arr2);
  sign = -17;
  //ШИРИНА МЕНЬШЕ ТОЧНОСТИ
  //без флагов
  s21_sprintf(arr1, "It is %5.6d", sign);
  sprintf(arr2, "It is %5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  //один флаг
  s21_sprintf(arr1, "It is %-5.6d", sign);
  sprintf(arr2, "It is %-5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5.6d", sign);
  sprintf(arr2, "It is %+5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5.6d", sign);
  sprintf(arr2, "It is % 5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %-+4.5d", sign);
  sprintf(arr2, "It is %-+4.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //ТОЧНОСТЬ МЕНЬШЕ ШИРИНЫ
  //без флагов
  s21_sprintf(arr1, "It is %7.5d", sign);
  sprintf(arr2, "It is %7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //один флаг
  s21_sprintf(arr1, "It is %-7.5d", sign);
  sprintf(arr2, "It is %-7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+7.5d", sign);
  sprintf(arr2, "It is %+7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 7.5d", sign);
  sprintf(arr2, "It is % 7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %- 7.5d", sign);
  sprintf(arr2, "It is %- 7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-+7.5d", sign);
  sprintf(arr2, "It is %-+7.5d", sign);
  ck_assert_str_eq(arr1, arr2);
  //спецификатор d с длиной l
  long int long_int = 786784687678678;
  //без флагов
  s21_sprintf(arr1, "It is %5.6ld", long_int);
  sprintf(arr2, "It is %5.6ld", long_int);
  ck_assert_str_eq(arr1, arr2);
  //оин флаг
  s21_sprintf(arr1, "It is %-5.6ld", long_int);
  sprintf(arr2, "It is %-5.6ld", long_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.6ld", long_int);
  sprintf(arr2, "It is %5.6ld", long_int);
  ck_assert_str_eq(arr1, arr2);
  //ПОДАЕМ 0
  sign = 0;
  s21_sprintf(arr1, "It is %5.6d", sign);
  sprintf(arr2, "It is %5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6d", sign);
  sprintf(arr2, "It is %-5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5.6d", sign);
  sprintf(arr2, "It is %+5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5.6d", sign);
  sprintf(arr2, "It is % 5.6d", sign);
  ck_assert_str_eq(arr1, arr2);
  //ширина и длина подаются через звездочку
  s21_sprintf(arr1, "It is %*.*d", 12, 14, sign);
  sprintf(arr2, "It is %*.*d", 12, 14, sign);
  ck_assert_str_eq(arr1, arr2);
  //ИСПОЛЬЗОВАНИЕ ДЛИНЫ h
  short int s = 21;
  s21_sprintf(arr1, "It is %5.6hd", s);
  sprintf(arr2, "It is %5.6hd", s);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6hd", s);
  sprintf(arr2, "It is %-5.6hd", s);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5.6hd", s);
  sprintf(arr2, "It is %+5.6hd", s);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5.6hd", s);
  sprintf(arr2, "It is % 5.6hd", s);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_i) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  int sign = 13;
  s21_sprintf(arr1, "It is %5.6i", sign);
  sprintf(arr2, "It is %5.6i", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6i", sign);
  sprintf(arr2, "It is %-5.6i", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.60i", sign);
  sprintf(arr2, "It is %5.60i", sign);
  ck_assert_str_eq(arr1, arr2);
  // i with l
  int long_int = 13;
  s21_sprintf(arr1, "It is %5.6i", long_int);
  sprintf(arr2, "It is %5.6i", long_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6i", long_int);
  sprintf(arr2, "It is %-5.6i", long_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.60i", long_int);
  sprintf(arr2, "It is %5.60i", long_int);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_f) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  double num = 345437.66454;
  s21_sprintf(arr1, "It is %f", num);
  sprintf(arr2, "It is %f", num);
  ck_assert_str_eq(arr1, arr2);
  //ТОЛЬКО ШИРИНА
  s21_sprintf(arr1, "It is %5f", num);
  sprintf(arr2, "It is %5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по одному флагу
  s21_sprintf(arr1, "It is %-5f", num);
  sprintf(arr2, "It is %-5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5f", num);
  sprintf(arr2, "It is %+5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5f", num);
  sprintf(arr2, "It is % 5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %05f", num);
  sprintf(arr2, "It is %05f", num);
  ck_assert_str_eq(arr1, arr2);
  num = 0;
  s21_sprintf(arr1, "It is %f", num);
  sprintf(arr2, "It is %f", num);
  ck_assert_str_eq(arr1, arr2);
  //ТОЛЬКО ШИРИНА
  s21_sprintf(arr1, "It is %5f", num);
  sprintf(arr2, "It is %5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по одному флагу
  s21_sprintf(arr1, "It is %-5f", num);
  sprintf(arr2, "It is %-5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5f", num);
  sprintf(arr2, "It is %+5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5f", num);
  sprintf(arr2, "It is % 5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %05f", num);
  sprintf(arr2, "It is %05f", num);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %-+5f", num);
  sprintf(arr2, "It is %-+5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %- 5f", num);
  sprintf(arr2, "It is %- 5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+05f", num);
  sprintf(arr2, "It is %+05f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 05f", num);
  sprintf(arr2, "It is % 05f", num);
  ck_assert_str_eq(arr1, arr2);
  //ТОЛЬКО ТОЧНОСТЬ
  s21_sprintf(arr1, "It is %.5f", num);
  sprintf(arr2, "It is %.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по одному флагу
  s21_sprintf(arr1, "It is %-.5f", num);
  sprintf(arr2, "It is %-.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+.5f", num);
  sprintf(arr2, "It is %+.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % .5f", num);
  sprintf(arr2, "It is % .5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %0.5f", num);
  sprintf(arr2, "It is %0.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %-+.5f", num);
  sprintf(arr2, "It is %-+.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %- .5f", num);
  sprintf(arr2, "It is %- .5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+0.5f", num);
  sprintf(arr2, "It is %+0.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 0.5f", num);
  sprintf(arr2, "It is % 0.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //ТОЧНОСТЬ И ШИРИНА ВМЕСТЕ
  s21_sprintf(arr1, "It is %8.5f", num);
  sprintf(arr2, "It is %8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по одному флагу
  s21_sprintf(arr1, "It is %-8.5f", num);
  sprintf(arr2, "It is %-8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+8.5f", num);
  sprintf(arr2, "It is %+8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 8.5f", num);
  sprintf(arr2, "It is % 8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %08.5f", num);
  sprintf(arr2, "It is %08.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //по два флага
  s21_sprintf(arr1, "It is %-+8.5f", num);
  sprintf(arr2, "It is %-+8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %- 8.5f", num);
  sprintf(arr2, "It is %- 8.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+08.5f", num);
  sprintf(arr2, "It is %+08.5f", num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 08.5f", num);
  sprintf(arr2, "It is % 08.5f", num);
  ck_assert_str_eq(arr1, arr2);
  //ПРОВЕРКА c long double
  long double long_double = 75687458757.657947;
  s21_sprintf(arr1, "It is %5Lf", long_double);
  sprintf(arr2, "It is %5Lf", long_double);
  ck_assert_str_eq(arr1, arr2);
  //по одному флагу
  s21_sprintf(arr1, "It is %-5Lf", long_double);
  sprintf(arr2, "It is %-5Lf", long_double);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %+5Lf", long_double);
  sprintf(arr2, "It is %+5Lf", long_double);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is % 5Lf", long_double);
  sprintf(arr2, "It is % 5Lf", long_double);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %05Lf", long_double);
  sprintf(arr2, "It is %05Lf", long_double);
  ck_assert_str_eq(arr1, arr2);
  //проверка нан и инф
  s21_sprintf(arr1, "It is %f", num);
  sprintf(arr2, "It is %f", num);
  ck_assert_str_eq(arr1, arr2);
  num = S21_INF_NEG;
  s21_sprintf(arr1, "It is %f", num);
  sprintf(arr2, "It is %f", num);
  ck_assert_str_eq(arr1, arr2);
  num = S21_INF_POS;
  s21_sprintf(arr1, "It is %f", num);
  sprintf(arr2, "It is %f", num);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_o) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  unsigned int sign = 8;
  s21_sprintf(arr1, "It is %5.6o", sign);
  sprintf(arr2, "It is %5.6o", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6o", sign);
  sprintf(arr2, "It is %-5.6o", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.60o", sign);
  sprintf(arr2, "It is %5.60o", sign);
  ck_assert_str_eq(arr1, arr2);

  unsigned int long_int = 8;
  s21_sprintf(arr1, "It is %5.6o", long_int);
  sprintf(arr2, "It is %5.6o", long_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6o", long_int);
  sprintf(arr2, "It is %-5.6o", long_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.60o", long_int);
  sprintf(arr2, "It is %5.60o", long_int);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_s) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  char *str = "cool";
  s21_sprintf(arr1, "It is %5.6s", str);
  sprintf(arr2, "It is %5.6s", str);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6s", str);
  sprintf(arr2, "It is %-5.6s", str);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5.60s", str);
  sprintf(arr2, "It is %5.60s", str);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_u) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  unsigned int sign = 17;
  s21_sprintf(arr1, "It is %5.6u", sign);
  sprintf(arr2, "It is %5.6u", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6u", sign);
  sprintf(arr2, "It is %-5.6u", sign);
  ck_assert_str_eq(arr1, arr2);
  unsigned int long_unsigned_int = 17;
  s21_sprintf(arr1, "It is %5.6u", long_unsigned_int);
  sprintf(arr2, "It is %5.6u", long_unsigned_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6u", long_unsigned_int);
  sprintf(arr2, "It is %-5.6u", long_unsigned_int);
  ck_assert_str_eq(arr1, arr2);
  //ПРОВЕРКА h с unsigned
  s21_sprintf(arr1, "It is %5.6hu", long_unsigned_int);
  sprintf(arr2, "It is %5.6hu", long_unsigned_int);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6hu", long_unsigned_int);
  sprintf(arr2, "It is %-5.6hu", long_unsigned_int);
  ck_assert_str_eq(arr1, arr2);
  sign = 0;
  s21_sprintf(arr1, "It is %5.6u", sign);
  sprintf(arr2, "It is %5.6u", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5.6u", sign);
  sprintf(arr2, "It is %-5.6u", sign);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_x_X) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  int sign = 10;
  //ТОЛЬКО ШИРИНА
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %#5X", sign);
  sprintf(arr2, "It is %#5X", sign);
  ck_assert_str_eq(arr1, arr2);
  //флаг один
  s21_sprintf(arr1, "It is %05x", sign);
  sprintf(arr2, "It is %05x", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5x", sign);
  sprintf(arr2, "It is %-5x", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %#5x", sign);
  sprintf(arr2, "It is %#5x", sign);
  ck_assert_str_eq(arr1, arr2);
  //два флага
  s21_sprintf(arr1, "It is %-#5x", sign);
  sprintf(arr2, "It is %-#5x", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %#05x", sign);
  sprintf(arr2, "It is %#05x", sign);
  ck_assert_str_eq(arr1, arr2);
  //все спецификаторы
  //  s21_sprintf(arr1, "It is % 0-+#5x", sign);
  //  sprintf(arr2, "It is % 0-+#5x", sign);
  //  ck_assert_str_eq(arr1, arr2);
  //ТОЛЬКО ТОЧНОСТЬ
  s21_sprintf(arr1, "It is %.5x", sign);
  sprintf(arr2, "It is %.5x", sign);
  ck_assert_str_eq(arr1, arr2);
  //флаг один
  s21_sprintf(arr1, "It is %-.5x", sign);
  sprintf(arr2, "It is %-.5x", sign);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %#.5x", sign);
  sprintf(arr2, "It is %#.5x", sign);
  ck_assert_str_eq(arr1, arr2);
  //два флага
  s21_sprintf(arr1, "It is %-#.5x", sign);
  sprintf(arr2, "It is %-#.5x", sign);
  ck_assert_str_eq(arr1, arr2);
  //ПРОВЕРКА ЧИСЕЛ 11-15
  sign = 11;
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
  sign = 12;
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
  sign = 13;
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
  sign = 14;
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
  sign = 15;
  s21_sprintf(arr1, "It is %5x", sign);
  sprintf(arr2, "It is %5x", sign);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_p) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  int num = 786;
  s21_sprintf(arr1, "It is %p", &num);
  sprintf(arr2, "It is %p", &num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %-5p", &num);
  sprintf(arr2, "It is %-5p", &num);
  ck_assert_str_eq(arr1, arr2);
  s21_sprintf(arr1, "It is %5p", &num);
  sprintf(arr2, "It is %5p", &num);
  ck_assert_str_eq(arr1, arr2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_n) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  int count1;
  int count2;
  s21_sprintf(arr1, "It is %n", &count1);
  sprintf(arr2, "It is %n", &count2);
  ck_assert_int_eq(count1, count2);
}
END_TEST
START_TEST(s21_sprintf_tests_spec_non) {
  char arr1[80] = {0};
  char arr2[80] = {0};
  s21_sprintf(arr1, "It is %%");
  sprintf(arr2, "It is %%");
  ck_assert_str_eq(arr1, arr2);
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s = suite_create("s_memchr");
  TCase *tc = tcase_create("tc_memchr");
  tcase_add_test(tc, memchr_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_memcmp(void) {
  Suite *s = suite_create("s_memcmp");
  TCase *tc = tcase_create("tc_memcmp");
  tcase_add_test(tc, memcmp_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_memcpy(void) {
  Suite *s = suite_create("s_memcpy");
  TCase *tc = tcase_create("tc_memcpy");
  tcase_add_test(tc, memcpy_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_memset(void) {
  Suite *s = suite_create("s_memset");
  TCase *tc = tcase_create("tc_memset");
  tcase_add_test(tc, memset_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strncat(void) {
  Suite *s = suite_create("s_strncat");
  TCase *tc = tcase_create("tc_strncat");
  tcase_add_test(tc, strncat_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strchr(void) {
  Suite *s = suite_create("s_strchr");
  TCase *tc = tcase_create("tc_strchr");
  tcase_add_test(tc, strchr_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strncmp(void) {
  Suite *s = suite_create("s_strncmp");
  TCase *tc = tcase_create("tc_strncmp");
  tcase_add_test(tc, strncmp_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strncpy(void) {
  Suite *s = suite_create("s_strncpy");
  TCase *tc = tcase_create("tc_strncpy");
  tcase_add_test(tc, strncpy_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strcspn(void) {
  Suite *s = suite_create("s_strcspn");
  TCase *tc = tcase_create("tc_strcspn");
  tcase_add_test(tc, strcspn_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strerror(void) {
  Suite *s = suite_create("s_strerror");
  TCase *tc = tcase_create("tc_strerror");
  tcase_add_test(tc, strerror_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strlen(void) {
  Suite *s = suite_create("s_strlen");
  TCase *tc = tcase_create("tc_strlen");
  tcase_add_test(tc, strlen_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strpbrk(void) {
  Suite *s = suite_create("s_strpbrk");
  TCase *tc = tcase_create("tc_strpbrk");
  tcase_add_test(tc, strpbrk_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strrchr(void) {
  Suite *s = suite_create("s_strrchr");
  TCase *tc = tcase_create("tc_strrchr");
  tcase_add_test(tc, strrchr_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strstr(void) {
  Suite *s = suite_create("s_strrstr");
  TCase *tc = tcase_create("tc_strstr");
  tcase_add_test(tc, strstr_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_strtok(void) {
  Suite *s = suite_create("s_strtok");
  TCase *tc = tcase_create("tc_strtok");
  tcase_add_test(tc, strtok_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_to_upper(void) {
  Suite *s = suite_create("s_s21_to_upper");
  TCase *tc = tcase_create("tc_s21_to_upper");
  tcase_add_test(tc, s21_to_upper_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_to_lower(void) {
  Suite *s = suite_create("s_s21_to_lower");
  TCase *tc = tcase_create("tc_s21_to_lower");
  tcase_add_test(tc, s21_to_lower_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_insert(void) {
  Suite *s = suite_create("s_s21_insert");
  TCase *tc = tcase_create("tc_s21_insert");
  tcase_add_test(tc, s21_insert_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_trim(void) {
  Suite *s = suite_create("s_s21_trim");
  TCase *tc = tcase_create("tc_s21_trim");
  tcase_add_test(tc, s21_trim_tests);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_c(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_c");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_c");
  tcase_add_test(tc, s21_sprintf_tests_spec_c);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_d(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_d");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_d");
  tcase_add_test(tc, s21_sprintf_tests_spec_d);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_i(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_i");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_i");
  tcase_add_test(tc, s21_sprintf_tests_spec_i);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_f(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_f");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_f");
  tcase_add_test(tc, s21_sprintf_tests_spec_f);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_o(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_o");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_o");
  tcase_add_test(tc, s21_sprintf_tests_spec_o);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_s(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_s");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_s");
  tcase_add_test(tc, s21_sprintf_tests_spec_s);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_u(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_u");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_u");
  tcase_add_test(tc, s21_sprintf_tests_spec_u);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_x_X(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_x_X");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_x_X");
  tcase_add_test(tc, s21_sprintf_tests_spec_x_X);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_p(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_p");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_p");
  tcase_add_test(tc, s21_sprintf_tests_spec_p);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_n(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_n");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_n");
  tcase_add_test(tc, s21_sprintf_tests_spec_n);
  suite_add_tcase(s, tc);
  return s;
}
Suite *suite_s21_sprintf_spec_non(void) {
  Suite *s = suite_create("s_s21_sprintf_spec_non");
  TCase *tc = tcase_create("tc_s21_sprintf_spec_non");
  tcase_add_test(tc, s21_sprintf_tests_spec_non);
  suite_add_tcase(s, tc);
  return s;
}

void run_test(Suite *s, int *no_failed) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int no_failed = 0;
  run_test(suite_memchr(), &no_failed);
  run_test(suite_memcmp(), &no_failed);
  run_test(suite_memcpy(), &no_failed);
  run_test(suite_memset(), &no_failed);
  run_test(suite_strncat(), &no_failed);
  run_test(suite_strchr(), &no_failed);
  run_test(suite_strncmp(), &no_failed);
  run_test(suite_strncpy(), &no_failed);
  run_test(suite_strcspn(), &no_failed);
  run_test(suite_strerror(), &no_failed);
  run_test(suite_strlen(), &no_failed);
  run_test(suite_strpbrk(), &no_failed);
  run_test(suite_strrchr(), &no_failed);
  run_test(suite_strstr(), &no_failed);
  run_test(suite_strtok(), &no_failed);
  run_test(suite_s21_to_upper(), &no_failed);
  run_test(suite_s21_to_lower(), &no_failed);
  run_test(suite_s21_insert(), &no_failed);
  run_test(suite_s21_trim(), &no_failed);
  run_test(suite_s21_sprintf_spec_c(), &no_failed);
  run_test(suite_s21_sprintf_spec_d(), &no_failed);
  run_test(suite_s21_sprintf_spec_i(), &no_failed);
  run_test(suite_s21_sprintf_spec_f(), &no_failed);
  run_test(suite_s21_sprintf_spec_o(), &no_failed);
  run_test(suite_s21_sprintf_spec_s(), &no_failed);
  run_test(suite_s21_sprintf_spec_u(), &no_failed);
  run_test(suite_s21_sprintf_spec_x_X(), &no_failed);
  run_test(suite_s21_sprintf_spec_p(), &no_failed);
  run_test(suite_s21_sprintf_spec_n(), &no_failed);
  run_test(suite_s21_sprintf_spec_non(), &no_failed);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

