#include "s21_decimal_test.h"

void run_test(Suite *s, int *no_failed) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int no_failed = 0;

  //арифметика
  run_test(suite_add_tests(), &no_failed);
  run_test(suite_div_tests(), &no_failed);
  run_test(suite_mul_tests(), &no_failed);
  run_test(suite_sub_tests(), &no_failed);

  //конвертеры
  run_test(suite_from_decimal_to_float_tests(), &no_failed);
  run_test(suite_from_decimal_to_int_tests(), &no_failed);
  run_test(suite_from_float_to_decimal_tests(), &no_failed);
  run_test(suite_from_int_to_decimal_tests(), &no_failed);

  //сравнение
  run_test(suite_is_less_tests(), &no_failed);
  run_test(suite_is_less_or_equal_tests(), &no_failed);
  run_test(suite_is_greater_tests(), &no_failed);
  run_test(suite_is_greater_or_equal_tests(), &no_failed);
  run_test(suite_is_equal_tests(), &no_failed);
  run_test(suite_is_not_equal_tests(), &no_failed);

  //другие функции
  run_test(suite_negate_tests(), &no_failed);
  run_test(suite_floor_tests(), &no_failed);
  run_test(suite_round_tests(), &no_failed);
  run_test(suite_truncate_tests(), &no_failed);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}